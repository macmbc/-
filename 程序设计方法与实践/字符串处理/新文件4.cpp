#include <stdio.h>
#include <string.h>

void my_strrev(char str[100001]) {
	int len = strlen(str);
	char temp = 0;
	for (int i = 0; i < len / 2; i++) {
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

int main() {
	int t = 0;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		char str1[100001] = {0};
		char str2[100001] = {0};
		char str[100001] = {0};
		memset(str1, '0', 100001);
		memset(str2, '0', 100001);
		scanf("%s", str1);
		scanf("%s", str2);
		my_strrev(str1);
		my_strrev(str2);
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		int min = len1 > len2 ? len2 : len1;
		int max = len1 < len2 ? len2 : len1;
		int flag = 0;
		if ( len1 == min) {
			str1[len1] = '0';
		} else {
			str2[len2] = '0';
		}
		for (int j = 0; j < max; j++) {
			str[j] = (str1[j] + str2[j] + flag - 2 * '0') % 2 + '0';
			if (str1[j] + str2[j] + flag - 2 * '0' >= 2) {
				flag = 1;
			} else {
				flag = 0;
			}
		}
		if (flag) {
			str[max] = '1';
			str[max + 1] = '\0';
		} else {
			str[max] = '\0';
		}
		my_strrev(str);
		int len = strlen(str);
		if ( len1 == min) {
			str1[len1] = '\0';
		} else {
			str2[len2] = '\0';
		}
		my_strrev(str1);
		my_strrev(str2);
		for (int j = 0; j < len - len1 + 2; j++) {
			printf(" ");
		}
		printf("%s\n", str1);
		printf("+");
		for (int j = 0; j < len - len2 + 1; j++) {
			printf(" ");
		}
		printf("%s\n", str2);
		for (int j = 0; j < len + 2; j++) {
			printf("-");
		}
		printf("\n");
		printf("  ");
		printf("%s\n", str);
	}
	return 0;
}
