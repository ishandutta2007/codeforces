#include<bits/stdc++.h>
#define db double
using namespace std;

int n,m,p[66][66],l,r,b,e,used[66]={0};
db f[8][66],g[8][66],now,ans=0.0;

int main(){
	scanf("%d",&n);
	m=1<<n;
	for (int i=0;i<m;i++){
		for (int j=0;j<m;j++){
			scanf("%d",&p[i][j]);
		}
	}
	for (int i=0;i<=n;i++){
		for (int j=0;j<=m;j++){
			f[i][j]=i==0?1.0:0.0;
			g[i][j]=0.0;
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			now=f[i][j];
			b=j/(1<<i);b^=1;
			l=b*(1<<i);r=l+(1<<i);
			for (int k=l;k<r;k++){
				f[i+1][j]+=now*f[i][k]*(db)p[j][k]/100.0;
			}
		}
	}
	
	for (int i=1;i<=n;i++){
		//printf(" %d::\n",i);
		for (int j=0;j<m;j++){
			b=j/(1<<(i-1));b^=1;
			l=b*(1<<(i-1));r=l+(1<<(i-1));
			for (int k=l;k<r;k++){
				g[i][j]=max(g[i][j],g[i-1][j]+g[i-1][k]+f[i][j]*(1<<(i-1)));
			}
			if (i==n){
				ans=max(ans,g[i][j]);
			}
			//	printf("  %d %.4lf\n",j,g[i][j]);
		}
	}
	printf("%.10lf\n",ans);
}