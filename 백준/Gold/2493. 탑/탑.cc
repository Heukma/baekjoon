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
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		d.push_back(temp);
	}
	int count = 0;
	while (d.size() != 0) {
		int temp = d[0];
		d.pop_front();
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