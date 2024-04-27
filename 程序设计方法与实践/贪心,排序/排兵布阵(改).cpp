#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmpfunc (const void *a, const void *b) {
	return ( *(long *)a - * (long *)b );
}

int main() {
	long n = 0;
	long long total = 0;
	long x0 = 0, y0 = 0;
	scanf("%ld", &n);
	long x[100002] = {0};
	long y[100002] = {0};
	long new_x[100002] = {0};
	for (long i = 0; i < n; i++) {
		scanf("%ld%ld", &x[i], &y[i]);
	}
	qsort(y, n, sizeof(long), cmpfunc);
	y0 = y[n / 2];
	for (long i = 0; i < n; i++) {
		total += fabs(y[i] - y0);
	}
	qsort(x, n, sizeof(long), cmpfunc);
	for (long i = 0; i < n; i++) {
		new_x[i] = x[i] - i;
	}
	qsort(new_x, n, sizeof(long), cmpfunc);
	x0 = new_x[n / 2];
	for (long i = 0; i < n; i++) {
		total += fabs(new_x[i] - x0);
	}
	printf("%lld\n", total);
	return 0;
}
