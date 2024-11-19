#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
int N, M;
long long ans = 0;
int visited[51] = {};
int map[51][51] = {};
vector <vector <int > > p;
vector <int> party;
deque <int> visitv;
void printmap() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}
void bfs(int a) {
	for (int i = 1; i <= N; i++) {
		if (map[a][i]) {
			if (visited[i] == 0) {
				visited[i] = 1;
				visitv.push_back(i);
			}
		}
	}
}
int main() {
	cin >> N >> M;
	// N: 사람 수 M: 파티 수
	int temp;
	int index;
	int ans = 0;
	cin >> temp;
	for (int i = 0; i < temp; i++) {
		cin >> index;
		visited[index] = 1;
		visitv.push_back(index);
	}

	for (int how = 0; how < M; how++) {
		cin >> temp;
		party.clear();
		for (int i = 0; i < temp; i++) {
			cin >> index;
			party.push_back(index);
		}
		for (int i = 0; i < party.size(); i++) {
			for (int j = i + 1; j < party.size(); j++) {
				map[party[i]][party[j]] = 1;
				map[party[j]][party[i]] = 1;
			}
		}
		p.push_back(party);
	}

	while (visitv.size() != 0) {
		int tempindex = visitv[0];
		visitv.pop_front();
		bfs(tempindex);
	}

	for (int i = 0; i < p.size(); i++) {
		bool flag = false;
		for (int j = 0; j < p[i].size(); j++) {
			if (visited[p[i][j]]) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			ans++;
		}
	}
	cout << ans;
}