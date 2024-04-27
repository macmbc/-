#include <stdio.h>

int main() {
	int t = 0;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		long long n = 0;
		int total = 0;
		scanf("%lld", &n);
		n--;
		while (n) {
			n /= 2;
			total++;
		}
		printf("%d\n", total);
	}

}