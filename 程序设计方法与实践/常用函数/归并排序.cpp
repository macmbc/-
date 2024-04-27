#include <stdio.h>
#include <string.h>

void Merge(int arr[], int l, int r, int mid) {
	int temp[100000] = {0};
	int i = l;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= r) {
		if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= r) {
		temp[k++] = arr[j++];
	}
	k = 0;
	while (l <= r) {
		arr[l++] = temp[k++];
	}
}

void MergeSort(int arr[], int l, int r) {
	if (l >= r) {
		return ;
	}
	int mid = (l + r) / 2;
	MergeSort(arr, l, mid);
	MergeSort(arr, mid + 1, r);
	Merge(arr, l, r, mid);
}

int main() {
	int arr[1000] = {0}, n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	MergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
