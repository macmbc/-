#include <stdio.h>

int main() {
	int n = 0;
	scanf("%d", &n);
	getchar();
	int num[2] = {0}; //分别表示可竞选人数和自由票数
	int vote[2] = {0}; //0表示'D',1表示'X'
	char c = 0;
	for (int i = 0; i < n; i++) {
		c = getchar();
		int j = c == 'D' ? 0 : 1;
		if (vote[!j] != 0) {
			vote[!j]--;
		} else {
			num[j]++;
			if (num[!j] != 0) {
				num[!j]--;
			} else {
				vote[j]++;
			}
		}
	}
	if (num[0] > num[1]) {
		printf("D\n");
	} else if (num[0] < num[1]) {
		printf("X\n");
	} else {
		if (c == 'D') {
			printf("X\n");
		} else {
			printf("D\n");
		}
	}
	return 0;
}
