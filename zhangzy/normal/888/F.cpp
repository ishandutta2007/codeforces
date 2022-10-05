#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

inline void U(int &x,int y){
	if ((x+=y)>=mod) x-=mod;
}
int n,mp[517][517],f[517][517],g[517][517],ans,t;
int main(){
	scanf("%d",&n);
	register int i,j,k;
	for (i=1;i<=n;++i) for (int j=1;j<=n;++j) getchar(), mp[i][j]=getchar()=='1';
	for (int l=0;l<n;++l){
		for (i=1,j;(j=i+l)<=n;++i){
			if (i==j){ f[i][j]=1; continue; }
			t= f[i+1][j];
			for (k=i+1;k<j;++k) if (mp[i][k])
				U(t,(ll)g[i][k]*g[k][j]%mod);
			g[i][j]=t;
			t= mp[i][j]? g[i][j]: 0;
			for (k=i+1;k<j;++k) if (mp[i][k])
				U(t,(ll)g[i][k]*f[k][j]%mod);
			f[i][j]=t;
		}
	}
	for (i=1;i<n;i++) if (mp[n][i])
		U(ans,(ll)f[1][i]*g[i][n]%mod);
	printf("%d",ans);
}