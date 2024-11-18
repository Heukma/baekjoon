#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
multiset <long long> st;
int N;
long long ans = 0;
void solve() {
	long long a = *st.begin();
	st.erase(st.begin());
	long long b = *st.begin();
	st.erase(st.begin());
	st.insert(a + b);
	ans += a + b;
}
int main() {
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		st.insert(temp);
	}
	while (st.size() != 1) {
		solve();
	}
	cout << ans;
	return 0;
}