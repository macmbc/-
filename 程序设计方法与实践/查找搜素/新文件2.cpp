#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;
char map[16][16];
char mapCopy[16][16];

struct pos { //记录路径
	int x;
	int y;
};

unordered_set<char> standard = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'A', 'B', 'C', 'D', 'E', 'F'};
int myMin = INT_MAX;
vector<pos> path;    //当前方案
vector<pos> minPath; //最小方案

void spin(pos place) {
	path.push_back(place);
	int arr[4][4];
	for (auto i = 0; i < 4; i++) {
		for (auto j = 0; j < 4; j++) {
			arr[3 - j][i] = mapCopy[i + place.x * 4][j + place.y * 4];
		}
	}
	for (auto i = 0; i < 4; i++) {
		for (auto j = 0; j < 4; j++) {
			mapCopy[i + place.x * 4][j + place.y * 4] = arr[i][j];
		}
	}
}
void back_spin(pos place) {
	path.pop_back();
	int arr[4][4];
	for (auto i = 0; i < 4; i++) {
		for (auto j = 0; j < 4; j++) {
			arr[j][3 - i] = mapCopy[i + place.x * 4][j + place.y * 4];
		}
	}
	for (auto i = 0; i < 4; i++) {
		for (auto j = 0; j < 4; j++) {
			mapCopy[i + place.x * 4][j + place.y * 4] = arr[i][j];
		}
	}
}
bool rowOK(int row) { //检测第row大行是否符合数独
	for (auto i = 0; i < 4; i++) {
		unordered_set<char> num;
		for (auto j = 0; j < 16; j++) {
			num.insert(mapCopy[i + row * 4][j]);
		}
		if (num != standard) {
			return false;
		}
	}
	return true;
};

bool colOK() { //直接判断所有列是否符合
	for (auto i = 0; i < 16; i++) {
		unordered_set<char> num;
		for (auto j = 0; j < 16; j++) {
			num.insert(mapCopy[j][i]);
		}
		if (num != standard) {
			return false;
		}
	}
	return true;
}

void DFS(pos place) {
	pos new_place;
	if (place.y == 4) {
		return;
	}
	if (place.x == 4) {
		if (colOK()) {
			if (myMin > path.size()) {
				myMin = path.size();
				minPath = path;
			}
		}
		return;
	}
	for (auto i = 0; i < 4; i++) {
		for (auto j = 0; j < i; j++) {
			spin(place);
		}
		int num = i; //表示目前已经旋转次数
		while (!rowOK(place.x) && num < 4) {
			spin(place);
			num++;
		}
		if (rowOK(place.x)) {
			new_place.x = place.x + 1;
			new_place.y = 0;
			DFS(new_place);
		} else {
			new_place.x = place.x;
			new_place.y = place.y + 1;
			DFS(new_place);
		}
		for (auto j = 0; j < i; j++) {
			back_spin(place);
		}
	}
	return;
}

int main() {
	int T = 0;
	scanf("%d\n", &T);
	for (auto i = 0; i < T; i++) {
		for (auto j = 0; j < 16; j++) {
			for (auto l = 0; l < 16; l++) {
				scanf("%c", &map[j][l]);
				mapCopy[j][l] = map[j][l];
			}
			getchar();
		}
		pos place = {0, 0};
		DFS(place);
		cout << minPath.size() << endl;
		for (auto i = 0; i < minPath.size(); i++) {
			printf("%d %d\n", minPath[i].x + 1, minPath[i].y + 1);
		}
	}
	system("pause");
	return 0;
}