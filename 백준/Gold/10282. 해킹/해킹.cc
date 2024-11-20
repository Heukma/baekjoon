#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>

using namespace std;
int N;
int n, d, c;
int a, b, s;
vector <vector<pair<int, int>> > v; // map;
deque <int> deq;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
int dp[10001] = {};
int maxtime;
void dijkstra(int cost, int index) {
	if (dp[index] == cost) {
		for (int i = 0; i < v[index].size(); i++) {
			int ind = v[index][i].first;
			if (dp[ind] > v[index][i].second + cost) {
				
				dp[ind] = v[index][i].second + cost;
				pq.push({ dp[ind] , ind });
			}
		}
	}
}
pair<int, int> costcount() {
	int m_time = 0;
	int count = 0;
	for (int i = 0; i < 10001;i++) {
		if (dp[i] != 1e9 + 10) {
			count++;
			m_time = max(m_time, dp[i]);
		}
	}
	return make_pair(count,m_time);
}
int main() {
	cin >> N;
	for (int test = 0; test < N; test++) {
		cin >> n >> d >> c;
		v.clear();
		deq.clear();
		fill(dp, dp + 10001, 1e9 + 10);
		v.resize(n);
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			a--; b--;
			v[b].push_back({ a,s });
		}
		deq.push_back(c - 1);
		maxtime = 0;
		pq.push({ 0,c - 1 });
		dp[c - 1] = 0;
		while (pq.size() != 0) {
			int cost = pq.top().first;
			int index = pq.top().second;
			pq.pop();
			dijkstra(cost, index);
		}
		pair<int, int> ret = costcount();
		cout << ret.first << ' ' << ret.second << '\n';
	}

	return 0;
}