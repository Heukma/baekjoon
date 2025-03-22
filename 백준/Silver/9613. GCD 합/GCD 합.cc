#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <numeric>

using namespace std;
int N;
deque<int> d;
long long ans = 0;
void combination() {
	for (int i = 0; i < d.size() -1; i++) {
		for (int j = i + 1; j < d.size(); j++) {
            // cout << d[i] << ' ' << d[j] << '\n';
			ans += gcd(d[i], d[j]);
		}
	}
}
int main() {
	cin >> N;
	for (int t = 0; t < N; t++) {
		int M;
        cin >>M;
		d.clear();
        ans = 0;
		for (int i = 0; i < M; i++) {
			int temp;
			cin >> temp;
			d.push_back(temp);
		}
        
        combination();
        cout << ans << '\n';

	}
}