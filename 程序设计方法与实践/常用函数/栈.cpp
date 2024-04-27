#include <stdio.h>
#define MAX 100

typedef struct {
	int arr[MAX];
	int index = 0;
} stack;

int push(stack l, int n) {
	if (l.index == MAX - 1) {
		return 0;
	} else {
		l.arr[(l.index)++] = n;
		return n;
	}
}

int pop(stack l) {
	if (l.index == 0) {
		return 0;
	} else {
		int res = l.arr[(l.index)--];
		return res;
	}
}

int main() {

}