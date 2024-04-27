#include <stdio.h>

int main() {
	int min = 0, max = 11;
	while (1) {
		int n = 0;
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		getchar();
		char str[10] = {};
		gets(str);
		if (str[4] == 'l') {
			min = (n > min) ? n : min;
		}
		if (str[4] == 'h') {
			max = (n < max) ? n : max;
		}
		if (str[4] == 't') {
			if (n > min && n < max) {
				printf("Tom may be honest\n");
			} else {
				printf("Tom is dishonest\n");
			}
			min = 0;
			max = 11;
		}
	}
}