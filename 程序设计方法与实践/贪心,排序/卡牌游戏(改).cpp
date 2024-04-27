#include <stdio.h>

int deck[200010] = {0};
int hands[200010] = {0};
int search[200010] = {0};
int distance[200010] = {0};

int IsContinue(int arr[], int len) {//判断牌堆底部是否有1开始的连续数列
	for (int i = len - 1;; i--) {
		if (arr[i] == 1) {
			return 1;
		}
		if (arr[i] - 1 != arr[i - 1]) {
			return 0;
		}
	}
}

int main() {
	int n = 0;
	int temp = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		hands[temp] = 1; //表示temp号在手上
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &deck[i]);//表示牌堆第i张牌的序号
		search[deck[i]] = i + 1; //表示deck[i]号牌在第几张
	}
	int flag = 1;
	int res = IsContinue(deck, n);
	if (res != 0) {
		for (int i = res + 1; i <= n; i++) {
			if (search[i] > i - res - 1) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			printf("%d\n", n - res);
		}
	} else {
		for (int i = 1; i <= n; i++) {
			distance[i] = search[i] - i + 1;
		}
		int max_distance = 0;
		for (int i = 1; i <= n; i++) {
			max_distance = max_distance > distance[i] ? max_distance : distance[i];
		}
		printf("%d\n", max_distance + n);
	}
}