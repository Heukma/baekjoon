#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;
int N, K;
int alphabet[26] = {};
vector <string> word;
string unused = "bdefghjklmopqrsuvwxyz";
int ret = 0;
void solve() {
	int ans = 0;
	for (int i = 0; i < word.size(); i++) {
		int flag = 1;
		for (int j = 0; j < word[i].length(); j++) {
			if (alphabet[word[i][j] - 'a'] == 0) {
				flag = 0;
				break;
			}
		}
		ans += flag;
	}
	ret = max(ret, ans);
}
void DFS(int count, int ind) {
	if (count == K - 5) {
		solve();
	}
	else {
		for (int i = ind; i <= unused.length(); i++) {
			alphabet[unused[i] - 'a'] = 1;
			DFS(count + 1, i+1);
			alphabet[unused[i] - 'a'] = 0;
		}
	}
}
int main() {
	cin >> N >> K;
	// antatica -> a n t i c -> 5개는 무조건 배워야 최소 1개의 단어를 읽을 수 있다. 
	string temp = "antic";
	for (int i = 0; i < temp.length(); i++) {
		alphabet[temp[i] - 'a'] = 1;
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;
		word.push_back(temp);
	}
	if (K < 5) {
		cout << "0";
		return 0;
	}
	DFS(0, 0);

	cout << ret;
}