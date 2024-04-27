#include <stdio.h>
#include <string.h>

void my_strrev(char str[1000]) {
	int len = strlen(str);
	char temp = 0;
	for (int i = 0; i < len / 2; i++) {
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

int main() {
	char str[10] = {0};
	scanf("%s", str);
	my_strrev(str);
	printf("%s\n", str);
	return 0;
}
