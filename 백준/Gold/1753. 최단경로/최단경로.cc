#include <iostream>
#include <deque>
#include <queue>
using namespace std;
int V, E;
int target;
deque <pair<int, int>> d[20001];
int ans[20001] = {};
struct Compare {
	bool operator()(pair<int, int> const& a, pair<int, int> const& b) {
		return a.first > b.first; 
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
void push_edges(int ind) {
	for (int i = 0; i < d[ind].size(); i++) {
		pair<int, int> t = d[ind][i];
		if (ans[t.first] > t.second + ans[ind]) {
			ans[t.first] = t.second + ans[ind];
			q.push({ ans[t.first] , t.first });
		}
	}
}
void reset_ans() {
	for (int i = 0; i <= V; i++) {
		ans[i] = 1e9;
	}
}
void print_q() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> qq;
	qq = q;
	int i = 0;
	while(qq.size()!=0) {
		i++;
		cout << i << ": " << qq.top().first << " " << qq.top().second << '\n';
		qq.pop();
	}
	cout << "-------------------------------------\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E;
	cin >> target;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a].push_back({ b,c }); // a -> b 가는 간선 cost c
	}
	reset_ans();
	ans[target] = 0;
	q.push({ 0,target });
	while (q.size() != 0) {
		// print_q();
		pair<int, int> t = q.top();
		q.pop();
		if (ans[t.second] < t.first) continue;
		push_edges(t.second);
		
	}
	for (int i = 1; i <= V; i++) {
		if (ans[i] == 1e9) {
			cout << "INF\n";
		}
		else{
			cout << ans[i]  << '\n';
		}
	}
}