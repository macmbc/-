#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *arr = {0};
	int index = 0;
} stack;

int push(stack &l, int n) {
	l.arr[(l.index)++] = n;
	return n;
}

int pop(stack &l) {
	if (l.index == 0) {
		return 0;
	} else {
		int res = l.arr[(l.index)--];
		return res;
	}
}

int main() {
	int n = 0;
	while (scanf("%d", &n) != EOF) {
		int flag = 1;
		stack STACK;
		STACK.arr = (int *)malloc(sizeof(int) * n);
		int *arr = (int *)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			if (STACK.index == 0 || STACK.arr[STACK.index - 1] != arr[i] % 2) {
				push(STACK, arr[i] % 2);
			} else {
				pop(STACK);
			}
			if (STACK.index > 2) {
				flag = 0;
			}
		}
		if (flag == 0) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
		free(arr);
		free(STACK.arr);
	}
	return 0;
}
