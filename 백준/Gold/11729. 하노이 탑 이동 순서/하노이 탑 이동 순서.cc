#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

int N;

void move(int start, int end,int index) {
	if (index == 1) {
		cout << start << " " << end << '\n';
		return ;
	}
	int temp = 3;
	if (start == 1 && end == 3) {
		temp = 2;
	}
	else if (start == 1 && end == 2) {
		temp = 3;
	}

	else if (start == 2 && end == 3) {
		temp = 1;
	}
	else if (start == 2 && end == 1) {
		temp = 3;
	}
	else if (start == 3 && end == 1) {
		temp = 2;
	}
	else if (start == 3 && end == 2) {
		temp = 1;
	}
	move(start, temp, index-1);
	cout << start << " " << end << '\n';
	move(temp, end, index -1);
	return ;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	cout << (long long)pow(2,N) - 1 << '\n';
	move(1, 3, N);
}