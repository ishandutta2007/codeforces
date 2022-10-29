#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

#define int long long
typedef long long LL;
typedef pair<int,int> pii;
const int MAX_N = 1e6 +6;
const LL INF = 1e17 +4;

bool O[MAX_N];
vector<int> prime;
LL v[MAX_N];
LL dp[3][MAX_N];
//dp[0] ==> no change
//dp[1] ==> change is last
//dp[2] ==> changed before
int n;
LL a,b;

void init() {
	O[0]=O[1]=true;
	for (int x=2;MAX_N>x;x++) {
		if (O[x]==false) {
			prime.push_back(x);
			for (LL y=(LL)x*x;MAX_N>y;y+=x) {
				O[y]=true;
			}
		}
	}
}

LL solve(int prime,int type) {
	for (int x=0;3>x;x++) {
		for (int y=0;MAX_N>y;y++) {
			dp[x][y] = INF;
		}
	}
	if (type <= 3) {
		if (type==2) dp[0][1] = 0;
		else dp[0][1] = b;
		for (int x=2;n>=x;x++) {
			//dp[0]
			if (v[x]%prime == 0) {
				dp[0][x] = dp[0][x-1];
			}
			else if ((v[x]+1)%prime == 0) {
				dp[0][x] = dp[0][x-1] + b;
			}
			else if ((v[x]-1)%prime == 0) {
				dp[0][x] = dp[0][x-1] + b;
			}
			else  {
				dp[0][x] = INF;
			}
			//dp[1]
			dp[1][x] = min(dp[0][x-1]+a,dp[1][x-1]+a);
			//dp[2]
			if (v[x]%prime == 0) {
				dp[2][x] = min(dp[1][x-1],dp[2][x-1]);
			}
			else if ((v[x]+1)%prime == 0) {
				dp[2][x] = min(dp[1][x-1],dp[2][x-1]) + b;
			}
			else if ((v[x]-1)%prime == 0) {
				dp[2][x] = min(dp[1][x-1],dp[2][x-1]) + b;
			}
			else {
				dp[2][x] = INF;
			}
			for (int tt=0;3>tt;tt++) {
				if (dp[tt][x] >= INF) dp[tt][x] = INF;
			}
		}
		return min(min(dp[0][n],dp[1][n]),dp[2][n]);
	}
	else {
		if (type==5)dp[0][n] = 0;
		else dp[0][n] = b;
		for (int x=n-1;x>=1;x--) {
			//dp[0]
			if (v[x]%prime == 0) {
				dp[0][x] = dp[0][x+1];
			}
			else if ((v[x]+1)%prime == 0) {
				dp[0][x] = dp[0][x+1] + b;
			}
			else if ((v[x]-1)%prime == 0) {
				dp[0][x] = dp[0][x+1] + b;
			}
			else  {
				dp[0][x] = INF;
			}
			//dp[1]
			dp[1][x] = min(dp[0][x+1]+a,dp[1][x+1]+a);
			//dp[2]
			if (v[x]%prime == 0) {
				dp[2][x] = min(dp[1][x+1],dp[2][x+1]);
			}
			else if ((v[x]+1)%prime == 0) {
				dp[2][x] = min(dp[1][x+1],dp[2][x+1]) + b;
			}
			else if ((v[x]-1)%prime == 0) {
				dp[2][x] = min(dp[1][x+1],dp[2][x+1]) + b;
			}
			else {
				dp[2][x] = INF;
			}
			for (int tt=0;3>tt;tt++) {
				if (dp[tt][x] >= INF) dp[tt][x] = INF;
			}
		}
		return min(min(dp[0][1],dp[1][1]),dp[2][1]);
	}
}

main () {
	init();
	while (scanf("%I64d %I64d %I64d",&n,&a,&b) != EOF) {
		for (int x=1;n>=x;x++) {
			scanf("%I64d",&v[x]);
		}
		LL ans=INF;
		for (int i=-1;1>=i;i++) {
			bool check=false;
			v[1] += i;
			for (auto iter=prime.begin();iter!=prime.end();iter++) {
				int tmp=*iter;
				if (v[1]%tmp == 0) {
					ans = min(ans,solve(tmp,i+2));
					check=true;
				}
				else if (tmp>v[1]) break;
			}
			if (!check && v[1] != 1) {
				ans = min(ans,solve(v[1],i+2));
			}
			v[1] -= i;
		}
		for (int i=-1;1>=i;i++) {
			v[n] += i;
			bool check=false;
			for (auto iter=prime.begin();iter!=prime.end();iter++) {
				int tmp=*iter;
				if (v[n]%tmp == 0) {
					ans = min(ans,solve(tmp,i+5));
					check=true;
				}
				else if (tmp>v[n]) break;
			}
			if (!check && v[n] != 1) {
				ans = min(ans,solve(v[n],i+5));
			}
			v[n] -= i;
		}
		printf("%I64d\n",ans);
	}
}