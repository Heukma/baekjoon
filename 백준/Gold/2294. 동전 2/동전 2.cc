#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int dp[10001] = {};
vector <int> v;
int n, k;
bool isvalid(int a) {
	return a >= 0;
}
int main(){
	cin >> n >> k;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	dp[k] = 1;
	for (int ind = 0; ind < v.size(); ind++) {
		for (int i = k; i != 0; i--) {
			if (dp[i] != 0) {
				if (isvalid(i - v[ind])) {
					if (dp[i - v[ind]] == 0 || dp[i - v[ind]] > dp[i] + 1) {
						dp[i - v[ind]] = dp[i] + 1;
					}
				}
			}
		}
	}
	cout << dp[0] - 1;
}