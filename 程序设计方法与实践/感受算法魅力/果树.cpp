#include <stdio.h>

int main() {
	int n = 0, v = 0;
	int arr1[10000] = {0};
	int arr2[10000] = {0};
	scanf("%d%d", &n, &v);//����������ÿ��ժ������
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);//�ڼ������
		scanf("%d", &arr2[i]);//����ʱ�ж�������
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		max = (max < arr1[i]) ? arr1[i] : max;
	}
	int day = 1;//����
	int yesterday = 0;
	int total = 0;
	while (1) {
		int today = 0;
		int j = 0;
		for (j = 0; j < n; j++) {
			if (arr1[j] == day) {
				today += arr2[j];
			}
		}
		if (v >= yesterday + today) {
			total += yesterday + today;
			yesterday = 0;
		} else if (v < yesterday + today && v >= yesterday) {
			total += v;
			yesterday = yesterday + today - v;
		} else if (v < yesterday) {
			total += v;
			yesterday = today;
		}
		day++;
		if (day > max + 1) {
			break;
		}
	}
	printf("%d\n", total);
}