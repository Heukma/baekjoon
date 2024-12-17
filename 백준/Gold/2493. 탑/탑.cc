#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <utility>
using namespace std;

int N;
deque <int> d;
deque <pair<int,int>> ans;
int main() {
	cin >> N;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int count = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		bool flag = false;
		while(ans.size()!=0) {
			if (ans[0].first > temp) {
				cout << ans[0].second << ' ';
				flag = true;
				break;
			}
			else {
				ans.pop_front();
			}
		}
		if (!flag) {
			cout << 0 << ' ';
		}
		count++;
		ans.push_front({ temp,count });
	}
	return 0;
}