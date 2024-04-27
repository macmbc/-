#include <stdio.h>
long long int array[300002];
long long int count = 0;

void Merge(long long int arr[], int l, int r, int mid) {
	int temp[100000] = {0};
	int i = l;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= r) {
		if (arr[i] < arr[j]) {
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
	while (l <= r) {
		arr[l++] = temp[k++];
	}
}

void MergeSort(long long int arr[], int l, int r) {
	if (l >= r) {
		return ;
	}
	int mid = (l + r) / 2;
	MergeSort(arr, l, mid);
	MergeSort(arr, mid + 1, r);
	Merge(arr, l, r, mid);
}

int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	MergeSort(array, 0, n - 1);
	printf("%lld\n", count);
	return 0;
}
