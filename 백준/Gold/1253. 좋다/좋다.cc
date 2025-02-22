#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int N;
int ans = 0;
deque <long long > d;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		d.push_back(temp);
	}

	sort(d.begin(), d.end());
	for (int i = 0; i < N; i++) {
		int left_point = 0;
		int right_point = N-1;
		if (right_point == i) {
			right_point--;
		}
		if (left_point == i) {
			left_point++;
		}
		while (left_point < right_point) {
			if (d[left_point] + d[right_point] == d[i]) {
				ans++;
				break;
			}
			else if(d[left_point] + d[right_point] > d[i]){
				right_point--;
				if (right_point == i) {
					right_point--;
				}
			}
			else {
				left_point++;
				if (left_point == i) {
					left_point++;
				}
			}
		}
	}

	cout << ans;
	return 0;
}