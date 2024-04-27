#include <stdio.h>

int main() {
	int t = 0;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n = 0;
		scanf("%d", &n);
		int leftY = 0;
		int flag = 0;//判断是否处于坑中
		for (int j = 0; j < n; j++) {
			int nowY = 0;
			scanf("%d", &nowY);
			if (!flag && nowY < leftY) {
				flag = 1;
			}
		}
	}
}