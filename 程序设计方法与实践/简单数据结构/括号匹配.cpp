#include <stdio.h>
#include <string.h>

int main() {
	int n = 0;
	scanf("%d", &n);
	int arr1[100010] = {0};
	int arr2[100010] = {0};
	char str[500010] = {0};
	int None = 0;
	int l = 0, r = 0;
	for (int i = 0; i < n; i++) {
		int depth = 0;
		scanf("%s", str);
		getchar();
		int len = strlen(str);
		int isRight = 0;
		for (int j = 0; j < len; j++) {
			if (str[j] == '(') {
				depth++;
			} else if (str[j] == ')') {
				if (depth == 0) {
					isRight++;
				} else {
					depth--;
				}
			}
		}
		if (isRight > 0 && depth == 0) {
			arr1[l++] = isRight;
		} else if (isRight > 0 && depth > 0) {
			continue;
		} else if (isRight == 0 && depth == 0) {
			None++;
		} else if (isRight == 0 && depth > 0) {
			arr2[r++] = depth;
		}
	}
	int total = 0;
	total += None / 2;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < r; j++) {
			if (arr1[i] == arr2[j]) {
				arr2[j] = 0;
				total++;
				break;
			}
		}
	}
	printf("%d\n", total);
	return 0;
}
