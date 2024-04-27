#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmpfunc (const void *a, const void *b) {
	return ( *(long *)a - * (long *)b );
}

long long MinDistance(long arr[], long len) {
	qsort(arr, len, sizeof(long long int), cmpfunc);
	long long res = 0;
	for (long i = 0; i < len; i++) {
		res += fabs(arr[i] - arr[len / 2]);
	}
	return res;
}

int main() {
	long n = 0;
	long total = 0;
	scanf("%ld", &n);
	long x[100002] = {0};
	long y[100002] = {0};
	for (long i = 0; i < n; i++) {
		scanf("%ld%ld", &x[i], &y[i]);
	}
	total += MinDistance(y, n);
	qsort(x, n, sizeof(long long int), cmpfunc);
	long new_x[100002] = {0};
	for (long i = 0; i < n; i++) {
		new_x[i] = x[i] - i;
	}
	total += MinDistance(new_x, n);
	printf("%lld\n", total);
	return 0;
}
