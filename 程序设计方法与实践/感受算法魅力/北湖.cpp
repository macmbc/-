#include <stdio.h>

int main() {
	int n = 0, h = 0;
	int arr[10000] = {0};
	scanf("%d%d", &n, &h);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int y = h; //Ŀǰ�߶�
	int x = 0; //Ŀǰ����λ��
	int  total = 0;
	while (y > 0) {
		while (x < n) {
			while (arr[x] < y) {
				x++;
				if (x == n) {
					break;
				}//��֤����ѭ��
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