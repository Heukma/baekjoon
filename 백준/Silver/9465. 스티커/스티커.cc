#include <iostream>
#include <deque>
#include <cmath>

using namespace std;
int N, M;
int sticker[2][100001] = {};
int anssticker[2][100001] = {};
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		for (int j = 0; j < M; j++) {
			cin >> sticker[0][j];
		}
		for (int j = 0; j < M; j++) {
			cin >> sticker[1][j];
		}

		anssticker[0][0] = sticker[0][0];
		anssticker[1][0] = sticker[1][0];

		for (int j = 1; j < M; j++) {
			anssticker[0][j] = max(anssticker[1][j - 1] + sticker[0][j], anssticker[0][j - 1]);
			anssticker[1][j] = max(anssticker[0][j - 1] + sticker[1][j], anssticker[1][j - 1]);
		}
		cout << max(anssticker[0][M - 1], anssticker[1][M - 1]) <<'\n';
	}
}