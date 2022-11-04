#include<bits/stdc++.h>
#define ll long long
#define P 300005
#define N 1005
using namespace std;
int g[27][N][N];
ll H[27][N][N];
int x1[P],x2[P];
int y1[P],y2[P];
char b[N][N],s[3];
int c[P],n,m,l;
ll ans;
ll getH(int x1,int y1,int x2,int y2,int c){
	return H[c][x2][y2]+H[c][x1-1][y1-1]
		  -H[c][x1-1][y2]-H[c][x2][y1-1];
}
int main(){
	scanf("%d%d%d",&n,&m,&l);
	for (int i=1;i<=n;i++)
		scanf("%s",b[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			b[i][j]-=96;
	for (int i=1;i<=l;i++){
		scanf("%d%d%d%d%s",&x1[i],&y1[i],&x2[i],&y2[i],s);
		c[i]=s[0]-96;
		g[c[i]][x1[i]][y1[i]]++;
		g[c[i]][x2[i]+1][y1[i]]--;
		g[c[i]][x1[i]][y2[i]+1]--;
		g[c[i]][x2[i]+1][y2[i]+1]++;
		g[0][x1[i]][y1[i]]--;
		g[0][x2[i]+1][y1[i]]++;
		g[0][x1[i]][y2[i]+1]++;
		g[0][x2[i]+1][y2[i]+1]--;
	}
	g[0][1][1]+=l;
	for (int i=0;i<=26;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=m;k++)
				g[i][j][k]+=g[i][j-1][k]
							+g[i][j][k-1]
							-g[i][j-1][k-1];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			int r=l,t=0;
			for (int k=1;k<=26;k++)
				t+=g[k][i][j]*(k-1);
			t+=g[0][i][j]*(b[i][j]-1);
			for (int k=1;k<=26;k++){
				H[k][i][j]=t;
				r=r-g[k][i][j];
				if (k==b[i][j])
					r=r-g[0][i][j];
				t=t-r+l-r;
			}
			H[0][i][j]=H[b[i][j]][i][j];
		}
	for (int i=0;i<=26;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=m;k++)
				H[i][j][k]+=H[i][j-1][k]
							+H[i][j][k-1]
							-H[i][j-1][k-1];
	ans=1e18;
	for (int i=1;i<=l;i++)
		ans=min(ans,H[0][n][m]-getH(x1[i],y1[i],x2[i],y2[i],0)
							  +getH(x1[i],y1[i],x2[i],y2[i],c[i]));
	printf("%lld\n",ans);
}