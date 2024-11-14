#include <iostream>
#include <queue>
#include <deque>
#include <utility>

using namespace std;

int N, M;
vector <vector <int>> map;
vector <vector <int>> dp;
void printdp() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;
	dp.resize(N+1, vector<int>(N+1));
	map.resize(N+1, vector<int>(N+1));
	 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (j == 1) {
				cin >> map[i][j];
				dp[i][j] = map[i][j];
			}
			else {
				cin >> map[i][j];
				dp[i][j] += map[i][j] + dp[i][j-1];
			}
		}
	}
	for(int i=1;i<=N;i++){
		for (int j = 2; j <= N; j++) {
			dp[j][i] += dp[j - 1][i];
		}
	}

	//printdp();

	int x1, x2, y1, y2;
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << '\n';
	}


}