#include <stdio.h>

int main() {
	int n = 0, h = 0;
	scanf("%d%d", &n, &h);
	int total = 0;
	int leftY = h; //Ŀǰ�������ĸ߶�
	for (int x = 0; x < n; x++) {
		int nowY = 0;
		scanf("%d", &nowY);
		if (nowY >= leftY) {
		} else {
			total += leftY - nowY;
		}
		leftY = nowY;
	}
	printf("%d\n", total);
}