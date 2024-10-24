#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

deque <pair <int, int>> d[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
int ans1[1001] = {};
int ans2[1001] = {};
int temp[1001] = {};
int N, M, X;
void printans1() {
	for (int i = 0; i <= N; i++) {
		cout << ans1[i] << ' ';
	}
	cout << '\n';
}
void dijkstra(int ind, int cost, int ans[]) {
	if (cost > ans[ind]) return;
	for (int i = 0; i < d[ind].size(); i++) {
		int des =d[ind][i].first; // 도착지점
		int time = d[ind][i].second; // cost;
		if (ans[des] > time + cost) {
			ans[des] = time + cost;
			pq.push({ ans[des],des });
		}
	}
	
}
int main() {
	cin >> N >> M >> X;
	// X 집으로 왕복하기.
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a].push_back({ b,c });
	}
	// X에서 각자 집으로 가는 ans;
	fill(ans1, ans1 + N + 1, 1e9 + 10);
	

	pq.push({ 0,X }); // cost , index;
	ans1[X] = 0;
	while (pq.size() != 0) {
		int cost = pq.top().first;
		int index = pq.top().second;
		pq.pop();
		dijkstra(index, cost, ans1);
	}
	for (int i = 1; i <= N; i++) {
		pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > >(); // queue 초기화하기.
		fill(temp, temp + N + 1, 1e9 + 10);
		pq.push({ 0,i }); // cost , index;
		temp[i] = 0;
		while (pq.size() != 0) {
			int cost = pq.top().first;
			int index = pq.top().second;
			pq.pop();
			dijkstra(index, cost, temp);
		}
		ans2[i] = temp[X];
	}
	int ret = -1;
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		ret = max(ret, ans1[i] + ans2[i]);
	}
	cout << ret;
}