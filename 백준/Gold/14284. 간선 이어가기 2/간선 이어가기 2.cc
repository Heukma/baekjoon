#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int N, M;
int costmap[5001] = {};
int startpoint, endpoint;
vector<vector<pair<int,int>>> v(5000);
priority_queue <pair<int, int>> pq;
void dijkstra(int point, int cost) {
	if (costmap[point] == cost) {
		for (int i = 0; i < v[point].size(); i++) {
			int visitpoint = v[point][i].first; // 방문 point;
			int visitcost = v[point][i].second; // 간선 cost;
			if (costmap[visitpoint] > visitcost + cost) {
				costmap[visitpoint] = visitcost + cost;
				pq.push({ costmap[visitpoint],visitpoint });
			}
		}
	}
	
}
int main() {
	cin >> N >> M;
	fill(costmap, costmap + 5001, 1e9 + 10);
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ b,cost });
		v[b].push_back({ a,cost });
	}
	cin >> startpoint >> endpoint;
	pq.push({ 0,startpoint });
	costmap[startpoint] = 0;
	while (pq.size() != 0) {
		int cost = pq.top().first;
		int point = pq.top().second;
		pq.pop();
		dijkstra(point, cost);
	}

	cout << costmap[endpoint];
}