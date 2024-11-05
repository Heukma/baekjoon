#include <iostream>
#include <queue>
using namespace std;

pair<int, int> where[25] = {};
int map[5][5] = {};
int orders[25] = {};
bool findbingo() {
	int ret = 0;
	for (int i = 0; i < 5; i++) {
		int flag = 1;
		for (int j = 0; j < 5; j++) {
			if (map[i][j] == 0) {
				flag = 0;
				break;
			}
		}
		ret += flag;
	}
	for (int j = 0; j < 5; j++) {
		int flag = 1;
		for (int i = 0; i < 5; i++) {
			if (map[i][j] == 0) {
				flag = 0;
				break;
			}
		}
		ret += flag;
	}
	int flag = 1;
	for (int i = 0; i < 5; i++) {
		if (map[i][i] == 0) {
			flag = 0;
			break;
		}
	}
	ret += flag;

	flag = 1;
	for (int i = 0; i < 5; i++) {
		if (map[i][4-i] == 0) {
			flag = 0;
			break;
		}
	}
	ret += flag;


	if (ret >= 3) return true;
	return false;
}
int main() {
	int temp;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> temp;
			where[temp] = { i,j };
		}
	}
	int i = 0;
	for (; i < 25; i++) {
		cin >> orders[i];
	}
	for (i =0; i < 25; i++) {
		temp = orders[i];
		map[where[temp].first][where[temp].second] = 1;
		if (findbingo()) {
			break;
		}
	}
	cout << i + 1;
}