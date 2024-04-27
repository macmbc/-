#include <stdio.h>

int combine(int sum, int select) {//组合数
	if (sum < select || select < 0) {//检测组合数的合法性
		return 0;
	}
	int res = 1;
	for (int i = sum; i > select; i--) {
		res *= i;
	}
	for (int i = sum - select; i > 0; i--) {
		res /= i;
	}
	return res;
}

int main() {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	int arr[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
	for (int i = 0; i < 8; i++) {
		arr[i][0] += x2;
		arr[i][1] += y2;
	}
	int imTotal = 0;
	for (int i = 0; i < 8; i++) {
		imTotal += combine(x1 + y1 - arr[i][0] - arr[i][1], x1 - arr[i][0]) * combine(arr[i][0] + arr[i][1], arr[i][0]);
	}
	int total = combine(x1 + x2, y1) - imTotal;
	printf("%d\n", total);
	return 0;
}
