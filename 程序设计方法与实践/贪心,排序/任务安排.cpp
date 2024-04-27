#include <stdio.h>
#include <limits.h>

int main() {
	int n = 0;
	scanf("%d", &n);
	long st[300000] = {0};
	long ed[300000] = {0};
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &st[i], &ed[i]);
	}
	long long sum = 0;
	long end = 0;
	long pl = 0;
	int flag = 1;
	while (1) {
		long min = INT_MAX;
		flag = 0;
		for (int i = 0; i < n; i++) {
			if (st[i] >= end) {
				flag = 1;
				if (ed[i] < min) {
					min = ed[i];
				}
			}
		}
		if (flag == 0) {
			break;
		}
		end = min;
		sum++;
	}
	printf("%d\n", sum);

	return 0;
}
