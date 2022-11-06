#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

long long int memo[1001][5][2];

long long int kai(int n) {
	long long int ans = 1;
	while (n >= 1) {
		ans *= n;
		n--;
	}
	return ans;
}

long long int solve(long long int n, int k,int flag) {
	if (memo[n][k][flag] != -1)return memo[n][k][flag];
	if (flag) {

		if (k == 0) {
			return memo[n][k][flag] = 1;
		}
		else if(n==k){
			return memo[n][k][flag] = kai(n);
		}
		else {
			return memo[n][k][flag] = solve(n - 1, k, 1) + (n - 1)*solve(n - 1, k - 1, 0);
		}
	}
	else {
		if (k == 0) {
			return memo[n][k][flag] = 0;
		}
		else {
			return memo[n][k][flag] = solve(n - 1, k - 1, 1) + (n - 1)*solve(n - 1, k - 1, 0);
		}
	}
}
int main() {
	for (int i = 0; i < 1001; ++i) {
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 2; ++k) {

				memo[i][j][k] = -1;
			}
		}
	}
	int n, k; cin >> n >> k;
	auto ans = solve(n, k, 1);
	cout << ans << endl;
	
	return 0;
}