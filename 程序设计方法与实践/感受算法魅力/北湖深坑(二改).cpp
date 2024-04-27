#include <stdio.h>

int main() {
	long t = 0;
	scanf("%ld", &t);
	long arr[100000] = {0};
	long left[100000] = {0};
	long right[100000] = {0};
	for (long i = 0; i < t; i++) {
		long total = 0;
		long n = 0;
		scanf("%ld", &n);
		for (long j = 0; j < n; j++) {
			scanf("%ld", &arr[j]);
		}
		int max = 0;
		for (long j = 0; j < n; j++) {
			max = (max > arr[j]) ? max : arr[j];
			left[j] = max;
		}
		max = 0;
		for (long j = 0; j < n; j++) {
			max = (max > arr[n - 1 - j]) ? max : arr[n - 1 - j];
			right[n - 1 - j] = max;
		}
		for (long j = 0; j < n; j++) {
			total += ((left[j] > right[j]) ? right[j] : left[j]) - arr[j];
		}
		printf("%ld\n", total);
	}
	return 0;
}