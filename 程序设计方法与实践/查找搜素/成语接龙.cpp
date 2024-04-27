#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

struct words {
	int from = 0;
	int to = 0;
	bool visit = false;
};

int main() {
	int  m = 0;
	scanf("%d", &m);
	words edge[100];
	queue <int> que;
	vector<int>step(100, 0);//到达末尾为j的成语所需步骤
	for (auto i = 0; i < m; i++) {
		scanf("%d %*d %*d %d", &edge[i].from, &edge[i].to);
	}
	int start = 0;
	int end = 0;
	scanf("%*d %*d %*d %d", &start);
	scanf("%d %*d %*d %*d", &end);
	edge[0].visit = true;
	que.push(start);
	step[start]++;
	bool flag = false;
	int res = 0;
	while (!que.empty()) {
		int ed = que.front();
		que.pop();
		for (auto j = 0; j < m; j++) {
			if (edge[j].from == ed && edge[j].visit == false) {
				que.push(edge[j].to);
				edge[j].visit = true;
				step[edge[j].to] = step[ed] + 1;
				if (edge[j].to == end) {
					break;
					flag = true;
					res = step[edge[j].to];
				}
			}
		}
		if (flag) {
			break;
		}
	}
	if (flag) {
		cout << res << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}

