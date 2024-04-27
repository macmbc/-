#include <stdio.h>
#include <string.h>

int main() {
	int t = 0;
	scanf("%d", &t);
	getchar();
	int total = 0;
	char str[1000][1000] = {0};
	for (int i = 0; i < t; i++) {
		gets(str[i]);
		int len = strlen(str[i]);
		int flag = 0;
		if (len > 10) {
			for (int j = 0; j < i; j++) {
				if (strcmp(str[i], str[j]) == 0) {
					flag = 1;
				}
			}
			if (flag == 0) {
				total++;
			}
		}
	}
	printf("%d\n", total);
	return 0;
}
