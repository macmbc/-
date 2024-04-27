#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n = 0; //²Â²â´ÎÊý
	int arr1[100] = {};
	int arr2[100] = {};
	int i = 0;
	while (1) {
		int GuessNumber = 0;
		scanf("%d", &GuessNumber);
		getchar();
		arr1[n] = GuessNumber;
		if (GuessNumber == 0) {
			break;
		} else {
			char str[100] = {};
			gets(str);
			int len = 0;
			while (str[len++] != '\0');
			if (str[len - 2] == 'w') {
				arr2[n] = -1;
			}
			if (str[len - 2] == 'h') {
				arr2[n] = 1;
			}
			if (str[len - 2] == 'n') {
				for (i = 0; i < n; i++) {
					if ((arr1[i] - GuessNumber)*arr2[i] > 0);
					else {
						printf("Tom is dishonest\n");
						break;
					}
				}
				if (i == n) {
					printf("Tom may be honest\n");
				}
				n = 0;
			}
		}
		n++;
	}
}