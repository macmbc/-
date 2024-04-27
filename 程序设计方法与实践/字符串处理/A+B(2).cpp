#include <stdio.h>
#include <string.h>

//防止数组索引越界等问题时报错
char trans(char str[100001], int n) {
	if (n < 0 || str[n] == '\0') {
		return '0';
	} else {
		return str[n];
	}
}

void my_strrev(char str[100001]) {
	int len = strlen(str);
	char temp = 0;
	for (int i = 0; i < len / 2; i++) {
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

int main() {
	char str1[100001] = {0};
	char str2[100001] = {0};
	char intstr[100001] = {0};
	char frastr[100001] = {0};
	memset(str1, '0', 100001);
	memset(str2, '0', 100001);
	scanf("%s", str1);
	scanf("%s", str2);
	int dot1 = 0;
	int dot2 = 0;//小数点的位置--整数部分长度
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int flag1 = 0;
	int flag2 = 0;
	while (str1[++dot1] != '.') {
		if (dot1 >= len1) {
			flag1 = 1;
			break;
		}
	}
	while (str2[++dot2] != '.') {
		if (dot2 >= len2) {
			flag2 = 1;
			break;
		}
	}
	int int_max = dot1 < dot2 ? dot2 : dot1;//整数部分较长值
	int flag = 0;
	int fra_max = ((len1 - dot1) > (len2 - dot2) ? (len1 - dot1) : (len2 - dot2)) - 1; //小数部分较长值
	for (int i = 0; i < fra_max; i++ ) {
		frastr[i] = (trans(str1, fra_max + dot1 - i) + trans(str2, fra_max + dot2 - i) - 2 * '0' + flag) % 10 + '0';
		if (trans(str1, fra_max + dot1 - i) + trans(str2, fra_max + dot2 - i) - 2 * '0' + flag >= 10) {
			flag = 1;
		} else {
			flag = 0;
		}
	}
	frastr[fra_max] = '\0';
	for (int i = 0; i < int_max; i++) {
		intstr[i] = (trans(str1, dot1 - 1 - i) + trans(str2, dot2 - 1 - i) - 2 * '0' + flag) % 10 + '0';
		if (trans(str1, dot1 - 1 - i) + trans(str2, dot2 - 1 - i) - 2 * '0' + flag >= 10) {
			flag = 1;
		} else {
			flag = 0;
		}
	}
	if (flag) {
		intstr[int_max] = '1';
		intstr[int_max + 1] = '\0';
	} else {
		intstr[int_max] = '\0';
	}
	int len_int = strlen(intstr);
	for (int i = 0;; i++) {
		if (intstr[len_int - 1 - i] != '0' || len_int - 1 - i == 0) {
			intstr[len_int - i] = '\0';
			break;
		}
	}
	int len = strlen(intstr);
	my_strrev(intstr);
	my_strrev(frastr);
	strcat(intstr, ".");
	strcat(intstr, frastr);
	//格式化输出
	int max_len = ((len > dot1) ? len : dot1) > dot2 ? ((len > dot1) ? len : dot1) : dot2;//最大的整数长度
	int max = max_len + 4 + fra_max;
	for (int i = 0; i < max - fra_max - 1 - dot1; i++) {
		printf(" ");
	}
	printf("%s", str1);
	for (int i = 0; i < fra_max - (len1 - dot1 - 1); i++) {
		printf(" ");
	}
	printf("\n");
	printf("+");
	for (int i = 0; i < max - fra_max - 2 - dot2; i++) {
		printf(" ");
	}
	printf("%s", str2);
	for (int i = 0; i < fra_max - (len2 - dot2 - 1); i++) {
		printf(" ");
	}
	printf("\n");
	for (int i = 0; i < max; i++) {
		printf("-");
	}
	printf("\n");
	for (int i = 0; i < max - fra_max - 1 - len; i++) {
		printf(" ");
	}
	if (flag1 && flag2) {
		intstr[len] = '\0';
	}
	printf("%s\n", intstr);
	return 0;
}
