#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *Color = {0};
	int *Height = {0};
	int index = 0;
} stack;

int push(stack &l, int c, int h) {//返回对应的高度
	l.Color[l.index] = c;
	l.Height[l.index] = h;
	l.index++;
	return h;
}

int pop(stack &l) {//返回对应的颜色
	if (l.index == 0) {
		return 0;
	} else {
		l.index--;
		return l.Color[l.index];
	}
}

int main() {
	int m = 0;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int n = 0;
		scanf("%d", &n);
		int *color = (int *)malloc(sizeof(int) * n);
		int *height = (int *)malloc(sizeof(int) * n);//储存对应的颜色和高度
		for (int j = 0; j < n; j++) {
			scanf("%d", &color[j]);
		}
		for (int j = 0; j < n; j++) {
			scanf("%d", &height[j]);
		}
		stack buildings;
		buildings.Color = (int *)malloc(sizeof(int) * n);
		buildings.Height = (int *)malloc(sizeof(int) * n);
		int *colorAll = (int *)malloc(sizeof(int) * n);
		long long sum = 0;
		for (int j = 0; j < n; j++) {
			while (buildings.index != 0 && buildings.Height[buildings.index - 1] < height[j]) {
				int temp = pop(buildings);
				colorAll[temp]--;
				if (colorAll[temp] == 0) {
					sum--;
				}
			}
			push(buildings, color[j], height[j]);
			colorAll[color[j]]++;
			if (colorAll[color[j]] == 1) {
				sum++;
			}
			printf("%lld", sum);
			if (j != n - 1) {
				printf(" ");
			}
		}
		printf("\n");
		free(buildings.Color);
		free(buildings.Height);
		free(color);
		free(height);
		free(colorAll);
	}
	return 0;
}
