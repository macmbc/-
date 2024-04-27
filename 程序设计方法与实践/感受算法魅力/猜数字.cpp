#include <stdio.h>

int main() {
	while (1) {
		int n = 0; //猜测次数
		int i = 0;
		int GuessNumber = 0;
		scanf("%d", &GuessNumber);
		if (GuessNumber == 0) {
			break;
		}
		char JudgeArr[100] = {0};
		gets(JudgeArr);
		int len = 0;
		int arr1[100] = {0};
		int arr2[100] = {0}; //记录数字大小关系
		arr1[n] = GuessNumber;
		while (JudgeArr[len++] != '\0');
		if (JudgeArr[len - 2] == 'w') {
			arr2[n] = -1;
		}
		if (JudgeArr[len - 2] == 'h') {
			arr2[n] = 1;
		}
		if (JudgeArr[len - 2] == 'n') {
			for (i = 0; i < n; i++) {
				if ((arr1[n] - GuessNumber)*arr2[n] > 0);
				else {
					printf("Tom is dishonest\n");
					break;
				}
			}
			if (i == n) {
				printf("Tom may be honest\n");
			}
		}
		n++;
	}
}