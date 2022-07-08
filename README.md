# Sum-of-Convergent-Series

Riemann zeta function using MPI and c Code
Calculate it with s = 3 - Apéry's constant -
This problem from n = 1 to infinite will be approximately equal to ζ(3) =
1.202056903159594 at the end we are trying to reach to value near this result and print the error
as our expected result = 1.202056903159594 ( error = expected - calculated)

- Process 0 (master) broadcast n to all processes and reduce to get the sum from all other
processes
- All processes (including master process) are doing their part of calculation
- we are using Bcast and Reduce

in the excel Sheet we are Calculating the runtime, speedup and efficiency for number of processes (2,4,8,16,64)
making other input constant to be able to find the impact of changing number of
processes.
