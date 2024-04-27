#include <stdio.h>
#include <string.h>

int main() {
	int s1[100] = {0};
	int ten1[20] = {0};
	int m1[20] = {0};
	char len = 0, k = 0, i = 0, a = 0;
	a = getchar();
	int *s = s1;
	int *ten = ten1;
	int *m = m1;
	int *temp = NULL;
	while (a != '\n') {
		ten[i] = a - '0';
		a = getchar();
		i++;
	}
	len = i;
	i = 0;
	// -------------------
	for (k = 0;; k++) {
		i = 0;
		while (i < len) {
			m[i] = ten[i] / 2;
			if (ten[i] % 2) {
				ten[i + 1] += 10;
			}
			i++;
		}
		if (ten[len]) {
			s[k] = 1;
		}
		for (i = 0; i <= len; i++) {
			ten[i] = 0;
		}
		if (!m[0]) {
			len--;
			for (i = 0; i < len; i++) {
				m[i] = m[i + 1];
			}
		}
		temp = m;
		m = ten;
		ten = temp;
		if (!ten[0])
			break;
	}
	k++;
	printf("%d\n", k);
	return 0;
}

