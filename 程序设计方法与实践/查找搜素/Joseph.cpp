#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

int main() {
	int n, k, m = 0;
	scanf("%d,%d,%d", &n, &k, &m);
	if (n < 1 || k < 1 || m < 1) {
		cout << "n,m,k must bigger than 0." << endl;
	} else if (k > n) {
		cout << "k should not bigger than n." << endl;
	} else {
		node *head, *pNode, *end;
		head = (node *)malloc(sizeof(node));
		head->data = -1;
		end = head;
		for (auto i = 1; i <= n; i++) {
			pNode = (node *)malloc(sizeof(node));
			pNode->data = i;
			end->next = pNode;
			end = pNode;
		}
		end->next = head->next;
		node *cur = head;
		for (auto i = 0; i < k; i++) {
			cur = cur->next;
		}
		for (auto i = 0; i < n; i++) {
			for (auto j = 0; j < m - 1; j++) {
				cur = cur->next;
			}
			if (i < n - 1 && (i + 1) % 10 != 0) {
				cout << cur->data << ' ';
			} else {
				cout << cur->data << endl;
			}
			cur->data = cur->next->data;
			cur->next = cur->next->next;
		}
	}
	return 0;
}
