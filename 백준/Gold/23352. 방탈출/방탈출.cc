#include <iostream>
#include <deque>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;
int ret = 0;
int maxnum = 0;
int map[51][51] = {};
int ra[4] = { 1,-1,0,0 };
int rb[4] = { 0,0,-1,1 };
deque <pair<int, int> > d;
deque <pair<pair<int, int>, int> > bfsd;
int visited[51][51] = {};

bool isvalid(int a, int b) {
	return a >= 0 && a < N && b >= 0 && b < M;
}

void bfs(int a, int b, int c) {
	for (int i = 0; i < 4; i++) {
		int tempa = a + ra[i];
		int tempb = b + rb[i];
		if (isvalid(tempa, tempb)) {
			if (map[tempa][tempb]) {
				if (visited[tempa][tempb] == 0) {
					visited[tempa][tempb] = 1;
					bfsd.push_back({ { tempa,tempb },c + 1 });
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j]) {
				d.push_back({i,j});
			}
		}
	}
	while (d.size() != 0) {
		int startnum = 0;
		int endnum = 0;
		int count = 0;

		int starta = d[0].first;
		int startb = d[0].second;
		d.pop_front();

		memset(visited, 0, sizeof(visited));
		visited[starta][startb] = 1;
		bfsd.push_back({ { starta,startb },0 });
		startnum = map[starta][startb];

		while (bfsd.size() != 0) {
			int a = bfsd[0].first.first;
			int b = bfsd[0].first.second;
			int c = bfsd[0].second;
			count = max(count, c);
			//cout << "a num : " << a << " b num : " << b << '\n';
			
			bfsd.pop_front();
			endnum = map[a][b];
			bfs(a, b, c);
		}
		//cout << "count : " << count << '\n';
		if (maxnum < count) {
			maxnum = count;
			//cout << "start num : " << startnum << " end num : " << endnum << '\n';
			ret = startnum + endnum;
		}
		else if (maxnum == count) {
			//cout << "start num : " << startnum << " end num : " << endnum << '\n';
			ret = max(startnum + endnum, ret);

		}
	}

	cout << ret;

	return 0;
}