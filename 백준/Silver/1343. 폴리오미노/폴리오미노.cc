#include <iostream>
#include <string>

using namespace std;

int flag = true;
string ret;
void solve_(int count) {
	if (count <= 0) {

	}
	else if (count == 1) {
		flag = false;
	}
	else {
		int c = count;
		while (c - 4 >= 0) {
			c -= 4;
			ret += "AAAA";
		}
		while (c - 2 >= 0) {
			c -= 2;
			ret += "BB";
		}
	}
	ret += ".";
}
void solve(int count) {
	if (count <= 0) {

	}
	else if (count == 1) {
		flag = false;
	}
	else {
		int c = count;
		while (c - 4 >= 0) {
			c -= 4;
			ret += "AAAA";
		}
		while (c - 2 >= 0) {
			c -= 2;
			ret += "BB";
		}
	}
}
int main() {
	string t;
	cin >> t;
	int count = 0;
	for (int i = 0; i < t.length(); i++) {
		if (t[i] == '.') {
			if (count % 2 == 0) {
				solve_(count);
			}
			else {
				flag = false;
			}
			count = 0;
		}

		else {
			count++;
		}
	}

	if (count % 2 == 0) {
		solve(count);
	}
	else {
		flag = false;
	}
	if (flag) {
		cout << ret;
	}
	else {
		cout << "-1";
	}
}
