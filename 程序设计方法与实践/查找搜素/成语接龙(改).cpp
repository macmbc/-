#include <iostream>
#include <queue>
#include <vector>
#define MAX 300010
using namespace std;

int BFS(vector<vector<int>> &graph, int start, int end) {
	vector<bool> visited(MAX, false);
	vector<int> step(MAX, 0);
	queue<int> node;
	node.push(start);
	visited[start] = true;
	step[start] = 1;
	while (!node.empty()) {
		int current = node.front();
		node.pop();
		if (current == end) {
			return step[current] + 1;
		}
		for (int next : graph[current]) {
			if (!visited[next]) {
				node.push(next);
				visited[next] = true;
				step[next] = step[current] + 1;
			}
		}
	}
	return -1;
}

int main() {
	int m = 0;
	scanf("%d", &m);
	int st = 0, ed = 0;
	vector<vector<int>> graph(MAX);
	for (auto i = 0; i < m; i++) {
		scanf("%d %*d %*d %d", &st, &ed);
		graph[st].push_back(ed);
	}
	vector<int> begin(4);
	vector<int> end(4);
	bool flag = true; //是否首尾成语相同
	for (auto i = 0; i < 4; i++) {
		scanf("%d", &begin[i]);
	}
	for (auto i = 0; i < 4; i++) {
		scanf("%d", &end[i]);
	}
	for (auto i = 0; i < 4; i++) {
		if (begin[i] != end[i]) {
			flag = false;
		}
	}
	if (flag) {
		cout << "1" << endl;
	} else {
		int res = BFS(graph, begin[3], end[0]);
		cout << res << endl;
	}
}