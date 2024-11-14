#include <iostream>
#include <deque>
#include <cmath>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

priority_queue <pair < int, int >,vector<pair<int,int>>, greater<>> pq;
vector <vector<pair<int,int>>> v;
int ans[50001] = {};
int N, M;
void dk(int des, int cost) {
	if (cost == ans[des]) {
		for (int i = 0; i < v[des].size(); i++) {
			int des_point = v[des][i].first;
			int current_cost = cost + v[des][i].second;
			//cout <<"From : " << des <<", To: " << des_point << '\n';
			if (ans[des_point] > current_cost) {
				ans[des_point] = current_cost;
				pq.push({ current_cost,des_point });
			}
		}
	}
}
int main() {
	cin >> N >> M;
	vector <vector<pair<int, int>>> tv(N);
	int tempa, tempb, tempc;
	for (int i = 0; i < M; i++) {
		cin >> tempa >> tempb >> tempc;
		tempa--;
		tempb--;
		tv[tempa].push_back({tempb,tempc});
		tv[tempb].push_back({ tempa,tempc });
	}
	v = tv;
	fill(ans, ans + 50001, 1e9 + 100);
	ans[0] = 0;
	pq.push({ 0,0 });
	while (pq.size() != 0) {
		int cost = pq.top().first;
		int des = pq.top().second;
		pq.pop();
		dk(des, cost);
	}

	cout << ans[N - 1];
	return 0;
}

