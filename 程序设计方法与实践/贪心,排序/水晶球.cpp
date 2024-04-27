#include <stdio.h>

int main() {
	int n = 0;
	scanf("%d", &n);
	int a[1000] = {0};
	int b[1000] = {0};
	int c[1000] = {0};
	int r_max = 0;
	int r = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		r = (a[i] > b[i] ? b[i] : a[i]) > c[i] ? c[i] : (a[i] > b[i] ? b[i] : a[i]);
		r_max = r > r_max ? r : r_max;
	}

	return 0;
}
