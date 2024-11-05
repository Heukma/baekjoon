#include <iostream>
#include <queue>

using namespace std;

int N;
int n;
int map[126][126] = {};
int costmap[126][126] = {};
int ra[4] = { 0,0,1,-1 };
int rb[4] = { 1,-1,0,0 };
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
bool isvalid(int a, int b) {
	return a >= 0 && a < n && b >= 0 && b < n;
}
void resetmap() {
	for (int i = 0; i < 126; i++) {
		for (int j = 0; j < 126; j++) {
			map[i][j] = 0;
			costmap[i][j] = 1e9 + 10;
		}
	}
}
void dik(int ind, int cost) {
	int a = ind / n;
	int b = ind % n;
	if (costmap[a][b] == cost) {
		for (int i = 0; i < 4; i++) {
			int tempa = a + ra[i];
			int tempb = b + rb[i];
			if (isvalid(tempa, tempb)) {
				if (costmap[tempa][tempb] > cost + map[tempa][tempb]) {
					costmap[tempa][tempb] = cost + map[tempa][tempb];
					pq.push({ costmap[tempa][tempb], tempa * n + tempb });
				}
			}
		}
	}
}
int main() {
	for (int prob = 1;; prob++) {
		// reset cost, map;
		//fill(map, map + sizeof(map) / sizeof(int), 0);
		//fill(costmap, costmap + sizeof(costmap) / sizeof(int), 1e9+10);
		resetmap();
		long long ans = 0;
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		// i * n + j;
		pq.push({ map[0][0], 0 });
		costmap[0][0] = map[0][0];
		while (pq.size()!=0) {
			int cost = pq.top().first;
			int ind = pq.top().second;
			pq.pop();
			dik(ind, cost);
		}
		cout << "Problem " << prob << ": " << costmap[n - 1][n - 1] << '\n';
	}
}