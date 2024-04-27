#include <stdio.h>
#include <string.h>
#define STR "fattyhappy"


int main() {
	int n = 0;
	scanf("%d", &n);
	int LEN = strlen(STR);
	for (int i = 0; i < n; i++) {//n次输入
		int flag = 0;
		int FLAG = 0;
		char str[1001] = {0};
		scanf("%s", str);
		int len = strlen(str);
		for (int j = 0; j < len - LEN + 1; j++) { //从目标字符串的每一个开头检测匹配度
			int fir = 0;
			int sec = 0;
			int k = 0;
			for (k = 0; k < LEN; k++) {//检测匹配度
				if (str[k + j] != STR[k]) {
					if (fir == 0) {
						fir = k + j + 1;
					} else if (sec == 0) {
						sec = k + j + 1;
					} else {
						break;
					}
				}
			}
			if (k < LEN) {
				continue;
			} else if (sec != 0) {
				if (str[fir - 1] == STR[sec - j - 1] && str[sec - 1] == STR[fir - j - 1] ) {
					printf("%d %d\n", fir, sec);
					flag = 1;
					break;
				}
			} else if (fir != 0) {
				for (int l = 0; l < j; l++) {
					if (str[l] == STR[fir - j - 1]) {
						printf("%d %d\n", l + 1, fir);
						flag = 1;
						FLAG = 1;
						break;
					}
				}
				if (FLAG == 1) {
					break;
				}
				for (int l = j + LEN; l < len ; l++) {
					if (str[l] == STR[fir - j - 1]) {
						printf("%d %d\n", fir, l + 1);
						flag = 1;
						FLAG = 1;
						break;
					}
				}
				if (FLAG == 1) {
					break;
				}
			} else {
				printf("%d %d\n", j + 3, j + 4);
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			printf("-1\n");
		}
	}
	return 0;
}
