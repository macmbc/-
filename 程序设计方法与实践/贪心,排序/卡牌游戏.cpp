#include <stdio.h>

int number[200010] = {0};
int deck[200010] = {0};
int new_deck[200010] = {0};
int search[200010] = {0};
int distance[200010] = {0};
int IsContinue(int arr[], int len) {//�ж��ƶѵײ��Ƿ���1��ʼ����������,���򷵻���������
	for (int i = len - 1;; i--) {
		if (arr[i] == 1) {
			return arr[len - 1];
		}
		if (arr[i] - 1 != arr[i - 1]) {
			return 0;
		}
	}
}
int IsExist(int arr[], int len, int n) { //�����ƶ�ǰlen�������Ƿ������Ϊ"n"����
	for (int i = 0; i < len; i++) {
		if (arr[i] == n ) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int n = 0;
	scanf("%d", &n);
	int num = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		number[num] = 1;//��ʾ���Ϊ'num'����������
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &deck[i]);//¼���ƶ������
		search[deck[i]] = i + 1;
	}
	int res = IsContinue(deck, n);
	int total = 0;
	int flag = 1;//�ж��Ƿ��������·��
	if (res != 0) {
		for (int i = res + 1; i <= n ; i++) {
			if (number[i] == 1 || IsExist(deck, i - res - 1, i)) {
			} else {
				flag = 0;
				break;
			}
		}
		if (flag) {
			total += n - res;
		} else {
			total += n - res + 1 + n;
		}
	}
//	} else {
//		for (int i = 0; i < n; i++) {
//			int flag = 1;
//			for (int j = 0; j < n - i; j++) {
//				new_deck[j] = deck[i + j];
//			}
//			if (i > 0) {
//				number[deck[i - 1]] = 1;
//			}
//			for (int j = n - i; j < n; j++) {
//				new_deck[j] = 0;
//			}
//			for (int j = 1; j <= n; j++) {
//				if (number[j] == 1 || IsExist(new_deck, j - 1, j)) {
//				} else {
//					flag = 0;
//					break;
//				}
//			}
//			if (flag) {
//				total += i + n;
//				break;
//			}
//		}
//	}
	else {
		for (int i = 1; i <= n; i++) {
			distance[i] = search[i] - i + 1;
		}
		int max_distance = 0;
		for (int i = 1; i <= n; i++) {
			max_distance = max_distance > distance[i] ? max_distance : distance[i];
		}
		total += max_distance + n;
	}
	printf("%d\n", total);
	return 0;
}
