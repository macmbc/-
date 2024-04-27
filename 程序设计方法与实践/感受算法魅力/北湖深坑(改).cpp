#include <stdio.h>

int main() {
	long long t = 0;
	scanf("%lld", &t);
	for (int i = 0; i < t; i++) {
		long long n = 0;
		scanf("%lld", &n);
		long long leftH = 0;//左边界高度
		long long rightH = 0; //右边界高度
		long long nowH = 0;
		long long total = 0;
		for (long long j = 0; j < n; j++) {
			scanf("%lld", &nowH);
			if (nowH >= leftH) {
				leftH = nowH;
				rightH = 0;
			} else {
				total += leftH - nowH;
			}
			if (nowH < leftH) {
				rightH = (nowH > rightH) ? nowH : rightH;
			}
		}
		if (rightH < leftH) {

		}
		printf("%d\n", total);
	}
}