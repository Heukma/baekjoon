#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

struct xy {
	int a;
	int b;
};
int map[9][9] = {};
int paintmap[9][9] = {};
int N, M;
int ans = 0;
int wall = 0;
deque <xy> cctv;
deque <xy> painted;
int ra[4] = { -1,1,0,0 };
int rb[4] = { 0,0,1,-1 };
void printmap();
void printpaintmap();

bool isvalid(int a, int b) {
	return a >= 0 && a < N && b >= 0 && b < M;
}
int kind_num(int kind) {
	if (kind == 1 || kind == 3 || kind == 4) return 4;
	else if (kind == 2) return 2;
	else if (kind == 5) return 1;

}
int num_can_see() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (paintmap[i][j] == 1) ans++;
		}
	}
	return ans++;
}

void input_() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			if (temp == 1 || temp == 2 || temp == 3 || temp == 4 || temp == 5) {
				cctv.push_back({ i,j });
			}
			if (temp == 6) wall++;
			map[i][j] = temp;
		}
	}
}
int paint_line(int a, int b, int i) {
	int ret = 0;
	while (1) {
		if (!isvalid(a, b)) break;
		if (map[a][b] == 6) break;
		if (paintmap[a][b] != 1) {
			paintmap[a][b] = 1;
			painted.push_back({ a,b });
			ret++;
		}
		a += ra[i];
		b += rb[i];
	}
	return ret;
}
int paint_map(int a,int b, int i, int kind) {
	int ret = 0;
	if (kind == 1) {
		ret += paint_line(a, b, i);
	}
	else if (kind == 2) {
		if (i == 0) {
			//상하
			ret += paint_line(a, b, 0);
			ret += paint_line(a, b, 1);
		}
		else {
			//좌우
			ret += paint_line(a, b, 2);
			ret += paint_line(a, b, 3);
		}
	}

	else if (kind == 3) {
		if (i == 0) {
			//상좌
			ret += paint_line(a, b, 0);
			ret += paint_line(a, b, 2);
		}
		else if (i == 1) {
			//상우
			ret += paint_line(a, b, 0);
			ret += paint_line(a, b, 3);
		}
		else if (i == 2) {
			//하좌
			ret += paint_line(a, b, 1);
			ret += paint_line(a, b, 2);
		}
		else if (i == 3) {
			//하우
			ret += paint_line(a, b, 1);
			ret += paint_line(a, b, 3);
		}
	}

	else if (kind == 4) {
		if (i == 0) {
			//상빼고
			ret += paint_line(a, b, 1);
			ret += paint_line(a, b, 2);
			ret += paint_line(a, b, 3);
		}
		else if (i == 1) {
			//하빼고
			ret += paint_line(a, b, 0);
			ret += paint_line(a, b, 2);
			ret += paint_line(a, b, 3);
		}
		else if (i == 2) {
			//좌빼고
			ret += paint_line(a, b, 0);
			ret += paint_line(a, b, 1);
			ret += paint_line(a, b, 3);
		}
		else if (i == 3) {
			//우빼고
			ret += paint_line(a, b, 0);
			ret += paint_line(a, b, 1);
			ret += paint_line(a, b, 2);
		}
	}

	else if (kind == 5) {
		ret += paint_line(a, b, 0);
		ret += paint_line(a, b, 1);
		ret += paint_line(a, b, 2);
		ret += paint_line(a, b, 3);
	}
	return ret;
}
void undo_paint_map(int num) {
	for (int i = 0; i < num;i++) {
		xy temp = painted.back();
		painted.pop_back();
		paintmap[temp.a][temp.b] = 0;
	}
}
void selectcctv(int index) {
	xy cctv_xy;
	cctv_xy.a = cctv[index].a;
	cctv_xy.b = cctv[index].b;
	int whatkind = map[cctv_xy.a][cctv_xy.b];
	for (int i = 0; i < kind_num(whatkind); i++) {
		int num = paint_map(cctv_xy.a, cctv_xy.b,i, whatkind);
		if (index == cctv.size() - 1) {

			/*printmap();
			printpaintmap();*/
			if (num_can_see() > ans) {
				ans = num_can_see();
			}
		}
		else {
			selectcctv(index + 1);
		}
		undo_paint_map(num);
	}
}

// debug
void printmap() {
	cout << "============map==========\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}
void printpaintmap() {
	cout << "============paintmap==========\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << paintmap[i][j] << ' ';
		}
		cout << '\n';
	}
}
void debug_kindnum() {
	cout << "============paintmap==========\n";
	for (int i = 1; i <= 5; i++) {
		cout << kind_num(i) << ' ';
	}
}
// debug

int main() {
	input_();
	/*printmap();
	printpaintmap();*/
	if (!cctv.size() == 0) {
		selectcctv(0);
	}
	cout << N * M - (ans + wall);
}

