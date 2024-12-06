#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <utility>
#include <string>
using namespace std;
int counting[41] = {};

int N, a, b;
string st;
void printcounting() {
	for (int i = 0; i <= st.length(); i++) {
		cout << counting[i] << ' ';
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> st;
	if (st[0] - '0' == 0) {
		cout << "0";
		return 0;
	}
	counting[0] = 1;
	counting[1] = 1;
	for (int i = 1; i < st.length(); i++) {
		int cur = st[i] - '0';
		int past = st[i-1] - '0';
		//cout << "cur , past, sum: " << cur << " " << past << " " << cur + past * 10 << '\n';
		if (cur > 0) {
			counting[i+1]+=counting[i];
		}
		if (cur + past * 10 >= 10 && cur + past * 10 <= 34) {
			counting[i+1] += counting[i - 1];
		}
		if (counting[i] == 0) {
			cout << "0";
			return 0;
		}
		
	}
	//printcounting();
	cout << counting[st.length()];
	return 0;
}