#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a;
	int b;
	int c;
	int n;//保证排序打乱后原位置仍可读取
} crystal;

crystal cube[100002];
crystal new_cube[100002];

int cmpfunc_a (const void *x, const void *y) {
	return ( *(crystal *)x).a - (* (crystal *)y).a;
}

int cmpfunc_b (const void *x, const void *y) {
	return ( *(crystal *)x).b - (* (crystal *)y).b;
}


int cmpfunc_c (const void *x, const void *y) {
	return ( *(crystal *)x).c - (* (crystal *)y).c;
}


int main() {
	int n = 0;
	scanf("%d", &n);
	int arr[3] = {0};
	int temp = 0;
	int p0 = 0;
	int p1 = 0, p2 = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
		for (int j = 1; j < 3; j++) {
			for (int k = 0; k < 3 - j; k++) {
				if (arr[k] > arr[k + 1] ) {
					temp = arr[k];
					arr[k] = arr[k + 1];
					arr[k + 1] = temp;
				}
			}
		}
		cube[i].a = arr[0];
		cube[i].b = arr[1];
		cube[i].c = arr[2];
		cube[i].n = i;
	}
	qsort(cube, n, sizeof(crystal), cmpfunc_a);//以水晶的最短边排序
	int r_max_1 = cube[n - 1].a;//最短边的最大值
	p0 = cube[n - 1].n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (cube[i].b > r_max_1) {//简单筛选
			new_cube[k].a = cube[i].a;
			new_cube[k].b = cube[i].b;
			new_cube[k].c = cube[i].c;
			new_cube[k].n = cube[i].n;
			k++;
		}
	}
	qsort(new_cube, k, sizeof(crystal), cmpfunc_b);//以水晶的中边排序
	qsort(new_cube, k, sizeof(crystal), cmpfunc_c);//以水晶的长边排序,保证b,c相同的水晶一定相邻
	int r_max_2 = 0;
	for (int i = 0; i < k - 1; i++) {
		if (new_cube[i].b == new_cube[i + 1].b && new_cube[i].c == new_cube[i + 1].c) {
			temp = new_cube[i].a + new_cube[i + 1].a;
			temp = temp > new_cube[i].b ? new_cube[i].b : temp;
			if (temp > r_max_2) {
				r_max_2 = temp;
				p1 = new_cube[i].n;
				p2 = new_cube[i + 1].n;
			}
		}
	}
	if (r_max_1 > r_max_2) {
		printf("1\n%d\n", p0 + 1);
	} else {
		printf("2\n%d %d\n", p1 + 1, p2 + 1);
	}
	return 0;
}
