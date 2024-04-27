#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0;
	scanf("%d", &n);
	getchar();
	char race[200010];
	char vote[200010];
//	char *race = (char *)malloc(sizeof(char) * n);
//	char *vote = (char *)malloc(sizeof(char) * n);
	int index = -1;
	for (int i = 0; i < n; i++) {
		char c = getchar();
		if (index == -1) {
			index++;
			race[index] = c;
			vote[index] = 1;
		} else {
			if (c == race[index]) {//同一种族
				int j = index;
				while (race[j] == c) {
					j--;
					if (j == -1) {
						break;
					}
				}
				if (j == -1) {
					index++;
					race[index] = c;
					vote[index] = 1;
				} else {
					race[j] = c;
				}
			} else {//不同种族
				int j = index;
				while (vote[j] == 0) {
					j--;
					if (j == -1) {
						break;
					}
				}
				if (j != -1) {
					vote[j] = 0;
				} else {
					race[index] = c;
				}
			}
		}
	}
	int i = 0;
	int len1 = 0;
	char res = 0;
	while (race[i++] == race[0]) {
		len1++;
	}
	if (2 * len1 >= index + 1) {
		res = race[0];
	} else {
		res = race[index];
	}
	printf("%c\n", res);
	return 0;
}
