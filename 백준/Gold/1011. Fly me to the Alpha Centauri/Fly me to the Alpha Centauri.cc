#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int N;
int start_point, end_point;
long long what[10000] = {};
int main() {
	cin >> N;
	/*1
	1 1
	1 2 1
	1 2 2 1
	1 2 3 2 1*/

	for (int num = 0; num < N; num++) {
		cin >> start_point >> end_point;
		int dis = end_point - start_point;
		int ans = 0;
		int count = 0;
		int speed = 1;
		while (dis > 0) {
			ans++;
			count++;
			dis -= speed;
			if (count % 2 == 0) {
				speed++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}