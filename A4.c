#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include "time.h"
#include <mpi.h>
#define Sn 1.202056903159594

double f(double a) // 1/a power 3
{
	double res = a;
	int i = 0;
	for (; i < 2; i++)
		res = res * a;
	return (double)1.0 / ((double)res);
}

int main(int argc, char *argv[])
{
	int n, myid, numprocs, i;
	double myZeita, zeita, sum;
	double local_start, local_finish, local_elapsed, elapsed;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	if (myid == 0)
	{
		printf(" Enter the number of intervals : (0 quits ) ");
		scanf ("%d" ,&n );
		local_start = MPI_Wtime();

	}

	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
	sum = 0.0;
	for (i = myid+1; i <= n; i += numprocs)
	{
		sum += f(i);
		printf("my rank %d, with index %d \n", myid, i);
	}
	myZeita = sum;
	MPI_Reduce(&myZeita, &zeita, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	
	if (myid == 0)
	{
		printf("zeita is approximatly : %.16f Error is: %.16f\n", zeita, fabs(zeita - Sn));
		local_finish = MPI_Wtime();
		elapsed=local_finish-local_start;
		printf("ELapsed Time = %f seconds \n", elapsed);

	}
	
	MPI_Finalize();

	return EXIT_SUCCESS;
}
