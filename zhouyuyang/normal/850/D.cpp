#include<bits/stdc++.h>
#define N 62
#define M 1832
using namespace std;
int n,m,a[N],f[N][N][M],g[N][N][M],d[N],u[N];
bool G[N][N];
int main(){
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	f[0][0][0]=1;
	for (int i=1;i<=m;i++)
		for (int j=i;j<N;j++)
			for (int k=i-1;k<j;k++){
				int y=k*(k-1)/2,x=(j-k)*a[i]+y;
				for (;x<M;x++,y++)
					if (f[i-1][k][y])
						f[i][j][x]=1,g[i][j][x]=j-k;
			}
	//f[i][j][k] ith num,x 1s,
	for (n=m;n<N&&!f[m][n][n*(n-1)/2];n++);
	if (n==N) return puts("=("),0;
	printf("%d\n",n);
	for (int i=m,j=n,k=n*(n-1)/2,x;i;i--){
		for (x=0;x<g[i][j][k];x++) d[j-x]=a[i];
		x=k; k-=g[i][j][x]*a[i]; j-=g[i][j][x];
	}
	sort(d+1,d+n+1);
	for (int i=1;i<=n;i++){
		u[i]=i-1;
		for (int j=1;j<i;j++)
			G[i][j]=1;
	}
	for (int i,j,k,x;;){
		for (i=1;i<=n&&d[i]<=u[i];i++);
		if (i>n) break;
		for (j=n;u[j]!=u[i];j--);
		for (k=1;d[k]>=u[k];k++);
		for (x=n;!(G[k][x]&&G[x][j]);x--);
		G[k][x]=0; G[x][k]=1; G[x][j]=0; G[j][x]=1;
		u[k]--; u[j]++;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			putchar(G[i][j]+'0');
		puts("");
	}
}