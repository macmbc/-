#include <stdio.h>
#include <math.h>

void change(char str[20][20], int i, int j, int n, int m) {
	str[i][j] = (str[i][j] - '0') ^ 1 + '0';
	if (i > 0) {
		str[i - 1][j] = (str[i - 1][j] - '0') ^ 1 + '0';
	}
	if (i < n) {
		str[i + 1][j] = (str[i + 1][j] - '0') ^ 1 + '0';
	}
	if (j > 0) {
		str[i][j - 1] = (str[i][j - 1] - '0') ^ 1 + '0';
	}
	if (j < m) {
		str[i][j + 1] = (str[i][j + 1] - '0') ^ 1 + '0';
	}
}

int func(char str[20][20], int number, int n, int m) {
	int total = 0;
	for (int i = 0; number != 0; i++) {
		if (number % 2) {
			change(str, 0, i, n, m);
			total++;
		}
		number /= 2;
	}
	return total;
}

int isok(char str[20][20], int n, int m) {
	int total = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (str[i][j] == '1') {
				change(str, i + 1, j, n, m);
				total++;
			}
		}
	}
	for (int j = 0; j < m; j++) {
		if (str[n - 1][j] != '0') {
			return -1;
		}
	}
	return total;
}

int main() {
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	int min = n * m;
	char str[20][20] = {0};
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}
	char STR[20][20] = {0};
	for (int i = 0; i < pow(2, m); i++) {//遍历第一行
		for (int k = 0; k < n; k++) {
			for (int j = 0; j < m; j++) {
				STR[k][j] = str[k][j];
			}
		}//STR数组的复原
		int total = 0;
		total += func(STR, i, n, m);
		int result = isok(STR, n, m);
		if (result != -1) {
			total += result;
			min = (min > total) ? total : min;
		}
	}
	printf("%d\n", min);
	return 0;
}
