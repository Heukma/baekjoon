#include <iostream>
#include <queue>
#include <deque>
#include <utility>

using namespace std;

int N, M;
int must1, must2;
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
int solve(int startpoint, int endpoint) {
	fill(ans, ans + 1001, 1e9 + 10);
	ans[startpoint] = 0;
	pq.push({ startpoint,0 });
	while (pq.size() != 0) {
		int point = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		dijkstra(point, cost);
	}
	return ans[endpoint];
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a].push_back({ b,c });
		d[b].push_back({ a,c });
	}

	cin >> must1 >> must2;
	int flag1 = 1, flag2 = 1;
	int one_mone = solve(1,must1);
	if (one_mone == 1e9 + 10) {
		flag1 = 0;
	}
	int one_mtwo = solve(1,must2);
	if (one_mtwo == 1e9 + 10) {
		flag2 = 0;
	}
	int mone_mtwo = solve(must1, must2);
	if (mone_mtwo == 1e9 + 10) {
		flag1 = 0;
	}
	int mtwo_mone = solve(must2, must1);
	if (mtwo_mone == 1e9 + 10) {
		flag2 = 0;
	}
	int mone_N = solve(must1, N);
	if (mone_N == 1e9 + 10) {
		flag1 = 0;
	}
	int mtwo_N = solve(must2, N);
	if (mtwo_N == 1e9 + 10) {
		flag2 = 0;
	}

	// 1 -> one - two - M
	// 1 -> two -> one -> M;
	if (flag1 && flag2) {
		cout << min(one_mone + mone_mtwo + mtwo_N, one_mtwo + mtwo_mone + mone_N);
	}
	else if (!flag1 && !flag2) {
		cout << "-1";
	}
	else if (flag1) {
		cout << one_mone + mone_mtwo + mtwo_N;
	}
	else {
		cout << one_mtwo + mtwo_mone + mone_N;
	}
}