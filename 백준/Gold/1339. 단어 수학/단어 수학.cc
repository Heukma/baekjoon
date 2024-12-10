#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int map[27] = {};

int N, M;
int main(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		int count = 1;
		for (int i = s.length()-1; i != -1; i--) {
			map[s[i] - 'A'] += count;
			count *= 10;
		}
	}
	int ans = 0;
	int count = 9;
	sort(map, map + 27, greater<>());
	for (int i = 0; i != 9; i++) {
		ans += count * map[i];
		count--;
	}
	cout << ans;
}