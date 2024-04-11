#include <iostream>
#include <stdio.h>
using namespace std;

#define int long long
typedef long long LL;
const int MAX_N = 103;
const LL INF = 1e17 + 6;

int c[MAX_N];
LL p[MAX_N][MAX_N];
LL dp[MAX_N][MAX_N][MAX_N];
//dp[i][j][k] ==> first i last j has k group

main () {
	int n,m,K;
	while (scanf("%I64d %I64d %I64d",&n,&m,&K) != EOF) {
		for (int x=1;n>=x;x++) {
			scanf("%I64d",&c[x]);
		}
		for (int x=1;n>=x;x++) {
			for (int y=1;m>=y;y++) {
				scanf("%I64d",&p[x][y]);
			}
		}
		for (int x=0;MAX_N>x;x++) {
			for (int y=0;MAX_N>y;y++) {
				for (int z=0;MAX_N>z;z++) {
					dp[x][y][z] = INF;
					if (x==0 && z==0) dp[x][y][z] = 0;
				}
			}
		}
		for (int i=1;1>=i;i++) {
			if (c[i] != 0) {
				dp[i][c[i]][1] = 0;
			}
			else {
				for (int j=1;m>=j;j++) {
					dp[i][j][1] = p[i][j];
				}
			}
		}
		dp[0][0][0] = 0;
		for (int i=1;n>=i;i++) {
			if (c[i]==0) {
				for (int j=1;m>=j;j++) {
					for (int k=1;n>=k;k++) {
						dp[i][j][k] = min(dp[i-1][j][k]+p[i][j] , dp[i][j][k]);
						for (int x=1;m>=x;x++) {
							if (x==j) continue;
							dp[i][j][k] = min(dp[i][j][k],dp[i-1][x][k-1] + p[i][j]);
						}
					}
				}
			}
			else {
				for (int x=1;m>=x;x++) {
					for (int k=1;n>=k;k++) {
						if (x==c[i]) {
							dp[i][c[i]][k] = min(dp[i][c[i]][k],dp[i-1][x][k]);
						}
						else {
							dp[i][c[i]][k] = min(dp[i][c[i]][k],dp[i-1][x][k-1]);
						}
					}
				}
			}
		}
//		for (int x=1;n>=x;x++) {
//			for (int y=1;m>=y;y++) {
//				for (int z=1;n>=z;z++) {
//					cout<<"dp["<<x<<"]["<<y<<"]["<<z<<"] = "<<dp[x][y][z]<<endl;
//				}
//			}
//		}
		LL mn=INF;
		for (int j=1;m>=j;j++) {
			mn = min(mn,dp[n][j][K]);
		}
		printf("%I64d\n",(mn >= INF ? -1 : mn));
	}
}