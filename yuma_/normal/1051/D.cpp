#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

long long  mod= 998244353;

int main() {
	int N,K;cin>>N>>K;
	vector<vector<vector<int>>>dp(N,vector<vector<int>>(2*N+1,vector<int>(4)));
	dp[0][1][0]=1;
	dp[0][2][1]=1;
	dp[0][2][2]=1;
	dp[0][1][3]=1;
	for (int i = 0; i < N-1; ++i) {
		for (int now_cost = 0; now_cost <=2*i+2; ++now_cost) {
			for (int f = 0; f < 4; ++f) {
				int now = dp[i][now_cost][f];

				for (int t = 0; t < 4; ++t) {
					int cost = 1;
					if (t == 1 || t == 2)cost = 2;

					for (int y = 0; y < 2; ++y) {
						int flag1 = !(f&(1 << y));
						int flag2 = !(t&(1 << y));
						if (flag1 == flag2)cost--;
					}
					if (t == 0 && f == 0)cost++;
					if (t == 3 && f == 3)cost++;
					dp[i + 1][now_cost+cost][t] +=now;
					if(dp[i+1][now_cost+cost][t]>=mod)dp[i+1][now_cost+cost][t]-=mod;
				}
			}
		}
		
	}
	long long int answer=0;
	for (int t = 0; t < 4; ++t) {
		answer+=dp[N-1][K][t];
		
	}
	answer%=mod;
	cout<<answer<<endl;
	return 0;
}