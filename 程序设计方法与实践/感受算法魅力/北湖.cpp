#include <stdio.h>

int main() {
	int n = 0, h = 0;
	int arr[10000] = {0};
	scanf("%d%d", &n, &h);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int y = h; //目前高度
	int x = 0; //目前区间位置
	int  total = 0;
	while (y > 0) {
		while (x < n) {
			while (arr[x] < y) {
				x++;
				if (x == n) {
					break;
				}//保证跳出循环
			}
			total++;
			while (arr[x] >= y) {
				x++;
				if (x == n) {
					break;
				}
			}
		}
		y--;
		x = 0;
	}
	printf("%d\n", total);
}