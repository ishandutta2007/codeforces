#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 5002;
const LL mod = 1e9+7;

int dp[MAX_N][MAX_N];
int nxt[MAX_N][MAX_N];  //assume  nxt[i][j]=x, that means d[i+x] != d
char c[MAX_N+10];
int d[MAX_N];
int n;

inline bool check(int i,int j) {
	return !(d[i]==0);
}

bool Greater(int a1,int a2,int b1,int b2) {
	if (b2>n) return false;
	int t=nxt[a1][b1];
	if (b1+t>b2) return false;
	else if (d[a1+t]<d[b1+t]) return true;
	else return false;
}

int main () {
	while (scanf("%d",&n) != EOF) {
		getchar();
		scanf("%s",c);
		for (int i=1;n>=i;i++) {
			d[i] = c[i-1]-'0';
		}
		for (int j=n;j>=1;j--) {
			if (j == n) {
				for (int i=1;n>=i;i++) {
					if (d[i] == d[j]) {
						nxt[i][j]=1;
					}
					else {
						nxt[i][j]=0;
					}
				}
				continue;
			}
			for (int i=j;i>=1;i--) {
				if (d[i]==d[j]) nxt[i][j] = nxt[i+1][j+1] + 1;
				else nxt[i][j]=0;
			}
		}
		memset(dp,0,sizeof(dp));
		for (int j=n;j>=1;j--) {
			if (j==n) {
				for (int i=1;n>=i;i++) {
					if (check(i,j)) {
						dp[i][j]=1;
					}
				}
				continue;
			}
			LL cnt=0;
			for (int i=j+2;n>=i;i++) {
				cnt += dp[j+1][i];
				cnt %= mod;
			}
			for (int i=j;i>=1;i--) {
				if (!check(i,j)) dp[i][j] = 0;
				else {
					dp[i][j] = cnt%mod;
					if (Greater(i,j,j+1,2*j-i+1)) {
						dp[i][j] += dp[j+1][2*j-i+1];
						dp[i][j] %= mod;
					}
				}
				if (2*j-i+2 <= n) {
					cnt -= dp[j+1][2*j-i+2];
					cnt += mod;
					cnt %= mod;
				}
			}
		}
		LL ans=0;
		for (int i=1;n>=i;i++) {
			ans += dp[1][i];
			ans %= mod;
		}
		printf("%I64d\n",ans);
	}
}