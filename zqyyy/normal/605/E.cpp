#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1007;
int n;
double f[N],p[N][N],g[N];
bool vis[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			p[i][j]=read()/100.;
	if(n==1)puts("0"),exit(0);
	vis[n]=1;
	for(int i=1;i<n;i++)
		f[i]=1,g[i]=1-p[i][n];
	f[0]=1e18;
	for(int i=1;i<=n;i++){
		int k=0;
		for(int j=1;j<=n;j++)
			if(!vis[j] && f[j]/(1-g[j])<f[k]/(1-g[k]))
				k=j;
		if(k==1)printf("%.10lf\n",f[k]/(1-g[k])),exit(0);
		vis[k]=1;
		for(int j=1;j<=n;j++)
			if(!vis[j])f[j]+=f[k]/(1-g[k])*p[j][k]*g[j],g[j]*=(1-p[j][k]);
	}
	return 0;
}