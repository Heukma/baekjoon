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
vector <int> per(21,0);
string unused = "bdefghjklmopqrsuvwxyz";
void printalpha() {
	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << ' ';
	}
	cout << '\n';
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
	for (int i = 0; i < K - 5; i++) {
		per[i] = 1;
	}
	int ans = 0;
	sort(per.begin(), per.end());
	do {
		for (int i = 0; i < 21; i++) {
			if (per[i]) {
				alphabet[unused[i] - 'a'] = 1;
			}
		}
		int tempans = 0;
		for (int i = 0; i < word.size(); i++) {
			int flag = 1;
			for (int j = 0; j < word[i].size(); j++) {
				if (!alphabet[word[i][j] - 'a']) {
					flag = 0;
					break;
				}
			}
			tempans += flag;
			
		}
		ans = max(ans, tempans);
		for (int i = 0; i < 21; i++) {
			if (per[i]) {
				alphabet[unused[i] - 'a'] = 0;
			}
		}
	} while (next_permutation(per.begin(), per.end()));

	cout << ans;
}