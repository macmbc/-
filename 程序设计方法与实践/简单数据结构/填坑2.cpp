#include <stdio.h>

int main() {
	int n = 0;
	while (scanf("%d", &n) != EOF) {
		int arr[100010] = {0};
		int index = 0;
		int temp = 0;
		int flag = 0;
		int max = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			max = max > temp ? max : temp;
			if (index == 0) {
				arr[index++] = temp;
			} else {
				if (temp > arr[index - 1]) {
					flag = 1;
				} else if (arr[index - 1] == temp) {
					index--;
				} else {
					arr[index++] = temp;
				}
			}
		}
		if (index > 1 || flag == 1) {
			printf("NO\n");
		} else {
			if (max > arr[index - 1] && index == 1) {
				printf("NO\n");
			} else
				printf("YES\n");
		}
	}

	return 0;
}
