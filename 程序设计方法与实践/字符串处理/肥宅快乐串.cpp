#include <stdio.h>
#include <string.h>
#define STR "fattyhappy"

int main() {
	int t = 0;
	int len = strlen(STR);
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		char str[1000] = {0};
		scanf("%s", str);
		int first = 0;
		int second = 0;
		for (int j = 0; str[j + len] != '\0'; j++) {//依次检测长度为len的字符匹配度
			int number = 0;
			int flag = 1;
			char c1 = '0';
			char c2 = '0';
			for (int k = 0; k < len; k++) {
				if (str[k + j] != STR[k]) {
					number++;
					if (number == 1) {
						first = k + j;
						c1 = STR[k];
					}
					if (number == 2) {
						second = k + j;
						c2 = STR[k];
					}
				}
				if (number > 2) {
					break;
					flag = 0; //不匹配
				}
			}
			if (flag) {
				if (number == 1) {
					for (int )
					}
			}
		}
	}
	return 0;
}
