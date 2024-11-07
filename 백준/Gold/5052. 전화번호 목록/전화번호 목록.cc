#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int N;
deque <string> d;
bool consistent(string a, string b) {
	// a > b;
	int countb = b.length();

	a.resize(b.length());
	if (a == b) {
		return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int testcase = 0; testcase < N; testcase++) {
		int count;
		cin >> count;
		d.clear();
		for (int i = 0; i < count; i++) {
			string temp;
			cin >> temp;
			d.push_back(temp);
		}
		sort(d.begin(), d.end());
		bool flag = true;
		for (int i = 1; i < count; i++) {
			if (!consistent(d[i], d[i-1])) {
				flag = false;
			}
		}
		if (flag) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}


	return 0;
}