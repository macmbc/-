#include <stdio.h>

long long dp[100][100] = {0};
long long search(int x, int y, int arr[9][2]) {
	if (x < 0 || y < 0) {
		return 0;
	}
	if (dp[x][y] != 0) {
		return dp[x][y];
	}
	for (int i = 0; i < 9; i++) {
		if (arr[i][0] == x && arr[i][1] == y) {
			return 0;
		}
	}
	return dp[x][y] = search(x - 1, y, arr) + search(x, y - 1, arr);
}
int main() {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	int arr[9][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {0, 0}};
	for (int i = 0; i < 9; i++) {
		arr[i][0] += x2;
		arr[i][1] += y2;
	}
	dp[0][0] = 1;
	long long res = search(x1, y1, arr);
	printf("%lld\n", res);
}