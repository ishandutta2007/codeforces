#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int MAX_N = 306;
const LL INF = 1e17 + 6;

LL w[MAX_N][MAX_N];
LL dp[MAX_N][MAX_N]; //times,last -->best //have last
LL mn[MAX_N][MAX_N];

int main () {
	int n,m,K;
	while (scanf("%d %d %d",&n,&m,&K) != EOF) {
		for (int x=0;n+1>=x;x++) {
			for (int y=0;n+1>=y;y++) {
				w[x][y] = INF;
				dp[x][y]= INF;
				mn[x][y]= INF;
				if (x==0) mn[x][y]=dp[x][y] = 0;
			}
		}
		for (int x=0;m>x;x++) {
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			w[a][b] = min(w[a][b],LL(c));
		}
		for (int i=n-1;i>=0;i--) {
			//i means lenght
			for (int j=1;n>=j+i;j++) {
				w[j][j+i] = min(min(w[j][j+i+1],w[j-1][j+i]),w[j][j+i] );
			}
		}
		for (int i=1;n>=i;i++) {
			for (int j=i+1;n>=j;j++) {
				for (int k=i;j>k;k++) {
					w[i][j] = min(w[i][j],w[i][k] + w[k+1][j]);
				}
			}
		}
//		for (int i=1;n>=i;i++) {
//			for (int j=i;n>=j;j++) {
//				cout<<"w["<<i<<"]["<<j<<"] = "<<w[i][j]<<endl;
//			}
//		}
		LL ans=INF;
		for (int i=1;n>=i;i++) {
			for (int j=i;n>=j;j++) {
				for (int k=1;n>=k;k++) {
					if (i-k<0) break;
					dp[i][j] = min(dp[i][j],mn[i-k][j-k] + w[j-k+1][j]);
					if (i>=K) ans=min(ans,dp[i][j]);
				}
				mn[i][j] = min(mn[i][j-1],dp[i][j]);
			}
		}
		if (ans<INF) printf("%I64d\n",ans);
		else puts("-1");
	}
}