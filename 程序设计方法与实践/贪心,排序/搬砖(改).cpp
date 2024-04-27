#include <stdio.h>

int arr[300020];
int temp[300020];
long long count = 0;

void Merge(int l, int r, int mid) {
	int i = l;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= r) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
			count += mid - i + 1;
		}
	}
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= r) {
		temp[k++] = arr[j++];
	}
	k = 0;
	for (int p = 0; p <= r - l; p++) {
		arr[l + p] = temp[p];
	}
}

void MergeSort(int l, int r) {
	if (l >= r) {
		return ;
	}
	int mid = (l + r) / 2;
	MergeSort(l, mid);
	MergeSort(mid + 1, r);
	Merge(l, r, mid);
}

int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	MergeSort(0, n - 1);
	printf("%lld\n", count);
	return 0;
}
