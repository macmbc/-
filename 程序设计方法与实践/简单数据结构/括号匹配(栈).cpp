#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
	int num[MAX];
	int i;
} stack;

int push(stack &l, int  c) {
	if (l.i == MAX - 1) {
		return 0;
	} else {
		l.num[(l.i)++] = c;
		return c;
	}
}

int pop(stack &l) {
	if (l.i = 0) {
		return 0;
	} else {
		int res = l.num[(l.i)--];
		return res;
	}
}

int isEmpty(stack &l) {
	if (l.i == 0) {
		return 1;
	}
	return0;
}

int main() {
	stack STACK;
	int n = 0;
	int ifLeft = 0;
	scanf("%d", &n);
	char STR[100] = {0};
	char str[100] = {0};
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		getchar();
		int len = strlen(str);
		for (int j = 0; j < len; j++) {
			if (str[j] == '(') {
				push(STACK, 1);
			} else if (str[j] == ')') {
				if (isEmpty(STACK)) {
					ifLeft = 1;
				}
			}

		}
	}
	return 0;
}
