#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>
#include <string>

using namespace std;
set <pair<int, int>> st;
int N, M;
int hard_[100001] = {};
string command;
int main() {
	cin >> N;
	int num, level;
	for (int i = 0; i < N; i++) {
		cin >> num >> level;
		hard_[num] = level;
		st.insert({ level,num });
	}
	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> command;
		if (command == "add") {
			cin >> num >> level;
			hard_[num] = level;
			st.insert({ level,num });
		}
		else if (command == "recommend") {
			cin >> level;
			if (level == 1) {
				pair<int, int> temp = *st.rbegin();
				cout << temp.second << '\n';
			}
			else if (level == -1) {
				pair<int, int> temp = *st.begin();
				cout << temp.second << '\n';
			}
		}
		else if (command == "solved") {
			cin >> num;
			int hard = hard_[num];
			auto iter = st.find(pair<int, int>(hard, num));
			st.erase(iter);
		}
	}
}