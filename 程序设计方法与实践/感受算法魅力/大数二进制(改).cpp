#include <stdio.h>
#include <string.h>

int main() {
	int t = 0;
	scanf("%d", &t) ;
	for (int i = 0; i < t; i++) {
		char str[20] = {0};
		char mystr[20] = "1000000000000000000";
		char newstr[20] = {0};
		scanf("%s", str);
		int len = strlen(str);
		int n = 0;
		int flag = 0;
		while (strcmp(str, newstr) > 0) {
			int mylen = 18;
			for (int j = 0; j < 20; j++) {
				if (mystr[j] >= '5') {
					mystr[j] = (mystr[j] - '0') * 2 - 10 + flag + '0';
					flag = 1;
				} else {
					mystr[j] = (mystr[j] - '0') * 2 + flag + '0';
					flag = 0;
				}
			}
			while (mystr[mylen] != '0') {
				mylen--;
			}
			if (mylen > len) {
				break;
			} else if (mylen < len) {
				continue;
			} else if (mylen == len) {
				for (int j = 0; j < len; j++) {
					newstr[j] = mystr[len - j];
				}
			}
			n++;
		}
		printf("%d\n", n);
	}
}