#include <stdio.h>

int main() {
	long long n = 0, h = 0;
	scanf("%lld%lld", &n, &h);
	long long leftH = h;
	long long nowH = 0;
	long long total = 0;
	for (long long i = 0; i < n; i++) {
		scanf("%lld", &nowH);
		if (nowH >= leftH) {
		} else {
			total += leftH - nowH;
		}
		leftH = nowH;
	}
	printf("%lld\n", total);
}