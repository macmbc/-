#include <stdio.h>

int func(int x1, int y1, int arr[9][2]) {
	if (x1 < 0 && y1 < 0) {
		return 0;
	}
	for (int i = 0; i < 9; i++) {
		if (x1 == arr[i][0] && y1 == arr[i][1]) {
			return 0;
		}
	}
	if (x1 == 0 && y1 == 0) {
		return 0;
	}
	return func(x1 - 1, y1, arr) + func(x1, y1 - 1, arr) + 1;
}

int main() {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	int arr[9][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {0, 0}};
	for (int i = 0; i < 9; i++) {
		arr[i][0] += x2;
		arr[i][1] += y2;
	}
	int total = func(x1, y1, arr);
	printf("%d\n", total);
	return 0;
}
