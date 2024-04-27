#include <stdio.h>

int main() {
	int n = 0;
	while (scanf("%d", &n) != EOF) {
		int arr[2] = {0};
		int index = 0;
		for (int i = 0; i < n; i++) {
			int m = 0;
			scanf("%d", &m);
			if (index == 0 || arr[index - 1] != m % 2) {
				arr[index++] = m % 2;
			} else {
				index--;
			}
			if (index > 2) {
				break;
			}
		}
		if (index >= 2) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}
