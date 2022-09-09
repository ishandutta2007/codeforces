#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int>V;
const int N=2e5+5;
V e[N];
int n,t[N],h[N],x,y,i;ll f[N][2];
void dfs(int x,int fa){
	V ve;int c0=0,c1=0;ll s0=0,s1=0;
	for(int y:e[x])if(y!=fa){
		dfs(y,x);
		if(h[y]<h[x])++c0,s0+=f[y][0];
		if(h[y]==h[x])ve.push_back(y);
		if(h[y]>h[x])++c1,s1+=f[y][1];
	}
	sort(ve.begin(),ve.end(),[&](int x,int y){return f[x][1]-f[x][0]<f[y][1]-f[y][0];});
	ll v=s0+s1;for(int y:ve)v+=f[y][0];
	f[x][0]=f[x][1]=1ll<<60;
	for(i=0;i<=ve.size();++i){
		int cc1=c1+i,cc0=c0+ve.size()-i;
		if(cc1)f[x][1]=min(f[x][1],v+1ll*t[x]*(1+max(cc1-1,cc0)));
		if(cc0)f[x][0]=min(f[x][0],v+1ll*t[x]*(1+max(cc1,cc0-1)));
		f[x][1]=min(f[x][1],v+1ll*t[x]*((fa?1:0)+max(cc1,cc0)));
		f[x][0]=min(f[x][0],v+1ll*t[x]*((fa?1:0)+max(cc1,cc0)));
		if(i<ve.size())v+=f[ve[i]][1]-f[ve[i]][0];
	}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",t+i);
	for(i=1;i<=n;++i)scanf("%d",h+i);
	for(i=1;i<n;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);printf("%lld\n",min(f[1][0],f[1][1]));
}