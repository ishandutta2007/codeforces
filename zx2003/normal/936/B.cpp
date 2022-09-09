#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int h[N],c[N],e[N<<1],n,m,i,j,k,x,f[N],nxt[N],xb,d[N];
int t,q[N*10],be[N],ww;
vector<int>g[N],b[N];
bool vi[N];
bool dfs(int x){
	if(vi[x])return 1;vi[x]=1;
	for(int i=h[x];i<h[x]+c[x];++i)if(dfs(e[i]))return 1;
	return vi[x]=0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;h[0]=1;
	for(i=1;i<=n;++i){
		cin>>c[i];h[i]=h[i-1]+c[i-1];
		for(j=0;j<c[i];++j)cin>>e[h[i]+j],g[e[h[i]+j]].push_back(i);
	}
	static int f0[N],f1[N],nxt0[N],nxt1[N];int w=0;
	for(i=1;i<=n;++i)if(!c[i])q[++w]=i,f1[i]=0,f0[i]=1;
	while(t<w){
		x=q[++t];
		for(i=0;i<g[x].size();++i){
			int y=g[x][i];
			if(f0[x] && !f1[y]){
				f1[y]=1;nxt1[y]=x;q[++w]=y;
			}
			if(f1[x] && !f0[y]){
				f0[y]=1;nxt0[y]=x;q[++w]=y;
			}
		}
	}
	int s;
	cin>>s;
	if(f1[s]){
		cout<<"Win"<<'\n';
		for(;s;){
			if(s)cout<<s<<' ';s=nxt1[s];
			if(s)cout<<s<<' ';s=nxt0[s];
		}cout<<'\n';
	}else puts(dfs(s)?"Draw":"Lose");
	return 0;
}