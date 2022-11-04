#include<bits/stdc++.h>
using namespace std;
const int N=2005;
char s[N];
bool a[N][N],b[N][N];
bool up[N][N],dn[N][N];
int n,m;
long long ans;
void solve(bool a[N][N],int n,int m,int w){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			up[i][j]=up[i-1][j]|a[i][j];
	for (int i=n;i;i--)
		for (int j=1;j<=m;j++)
			dn[i][j]=(i==n?a[i][j]:dn[i+1][j]|a[i][j]);
	for (int i=2;i<n;i++){
		int v=0;
		if (!a[i][1]&&w)v=1;
		up[i][1]=dn[i][1]=1;
		for (int j=2;j<m;j++){
			if (a[i][j]){
				v=0; continue;
			}
			ans+=((!up[i][j])+(!dn[i][j]))*v;
			ans+=(!up[i][j]&&!dn[i][j-1])+(!dn[i][j]&&!up[i][j-1]);
			v+=(!up[i][j-1])+(!dn[i][j-1]);
		}
		if (!a[i][m]&&w)
			ans+=v+(!up[i][m-1])+(!dn[i][m-1]);
	}
	if (w){
		for (int j=2;j<m;j++)
			ans+=(!up[n][j]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++)
			a[i][j]=b[j][i]=(s[j]=='#');
	}
	solve(a,n,m,1);
	solve(b,m,n,0);
	printf("%lld\n",ans);
}