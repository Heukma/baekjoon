#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> v;
bool visited[2001];
bool found = false;

void dfs(int node, int depth) {
    if (depth == 5) { 
        found = true;
        return;
    }

    visited[node] = true;

    for (int neighbor : v[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, depth + 1);
            if (found) return; 
        }
    }

    visited[node] = false; 
}

int main() {
    cin >> N >> M;

    v.resize(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        fill(visited, visited + N, false);
        dfs(i, 1);
        if (found) {
            cout << "1\n";
            return 0;
        }
    }

    cout << "0\n";
    return 0;
}
