#include <iostream>
#include <queue>
#include <deque>
#include <utility>

using namespace std;

int N, M;
int startpoint, endpoint;
deque <pair<int, int>> d[1001];
int ans[1001] = {};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
void dijkstra(int point, int cost) {
	if (ans[point] == cost) {
		for (int i = 0; i < d[point].size(); i++) {
			int secondpoint = d[point][i].first;
			int secondcost = d[point][i].second;
			if (ans[secondpoint] > cost + secondcost) {
				ans[secondpoint] = cost + secondcost;
				pq.push({ secondpoint,ans[secondpoint] });
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a].push_back({ b,c });
	}

	cin >> startpoint >> endpoint;
	fill(ans, ans + 1001, 1e9 + 10);
	ans[startpoint] = 0;
	pq.push({ startpoint,0 });
	while (pq.size() != 0) {
		int point = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		dijkstra(point,cost);
	}
	cout << ans[endpoint];
}