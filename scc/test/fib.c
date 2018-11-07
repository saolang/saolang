#include "scc_dl.h"

int fib(n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n-1) + fib(n-2);
}

int main(int argc, char **argv)
{
	int n;
	if (argc < 2) {
		SCC(printf)("usage: fib n\n"
				"Compute nth Fibonacci number\n");
		return 1;
	}

	n = SCC(atoi,int)(argv[1]);
	SCC(printf)("fib(%d) = %d\n", n, fib(n));
	return 0;
}
