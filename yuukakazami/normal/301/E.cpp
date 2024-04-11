#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

const int MAX_N = 100 + 10;
const int MOD = 1000000007;

int N, M, K;

//F1,F2,Fn
//F1,F1+F2,F2+F3,Fn
//1,2,3,4
//n<m
//F1*2+F2*2+F3*3<=n

void addIt(int&x, int c) {
	x += c;
	if (x >= MOD)
		x -= MOD;
}
int dp[52][52][52][102]; //i,sum,last,way
int comb[102][102];
int ans;

int main() {
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= i; ++j) {
			comb[i][j] =
					(i == 0 || j == 0) ?
							1 : (comb[i - 1][j - 1] + comb[i - 1][j]);
			comb[i][j] = min(comb[i][j], 101);
		}
	}
	cin >> N >> M >> K;
	dp[0][0][0][1] = 1;
	for (int i = 0; i < M && i <= N / 2; ++i) {
		for (int s = 0; s <= N / 2; ++s) {
			for (int lst = 0; lst <= N / 2; ++lst) {
				for (int way = 1; way <= K; ++way) {
					int c = dp[i][s][lst][way];
					if (c == 0)
						continue;
					if (i > 0) {
						ans += 1LL * c * (M - i) % MOD;
						ans %= MOD;
					}
					for (int nxt = 1; nxt + s <= N / 2; ++nxt) {
						int nway = way * comb[lst + nxt - 1][nxt - 1];
						if (nway <= K)
							addIt(dp[i + 1][s + nxt][nxt][nway], c);
					}
				}
			}
		}
	}
	cout << ans << endl;
}