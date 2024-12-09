#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int map[16] = {};
int N, M;
void solve(int num, string t, int index) {
	if (num == 0) {
		int flag1 = 0;
		int flag2 = 0;
		for (int j = 0; j < t.length(); j++) {
			if (t[j] == 'a' || t[j] == 'e' || t[j] == 'i' || t[j] == 'o' || t[j] == 'u') {
				flag1++;
			}
			else {
				flag2++;
			}
		}
		if (flag1 >= 1 && flag2 >= 2) {
			cout << t << '\n';
		}
	}
	for (int i = index; i < M; i++) {
		char temp = map[i] + 'a';
		//cout << "Temp : " << temp << '\n';
		t += temp;
		solve(num - 1, t, i + 1);
		t.pop_back();
	}
}
void printmap() {
	for (int i = 0; i < M; i++) {
		cout << map[i] << '\n';
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		char temp;
		cin >> temp;
		map[i] = temp - 'a';
	}

	sort(map, map + M);
	string t = "";
	solve(N, t, 0);

}