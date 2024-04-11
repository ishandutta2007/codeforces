#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,i,x,y,deg,pp[N],p[N];
int dep[N];
ll s,su;
inline void ini(int d){
	dep[1]=1;su=1;int i;
	for(i=2;i<=n;++i){
		pp[i]=(i+d-2)/d;
		su+=dep[i]=dep[pp[i]]+1;
	}	
}
inline int findd(){
	int l=2,r=n,mid;
	for(;l<r;){
		mid=(l+r)>>1;ini(mid);
		if(su>s)l=mid+1;else r=mid;
	}
	return l;
}
int son[N];
queue<int>q;
vector<int>e[N];
int xb;
void dfs(int x,int fa){
	int id=++xb;
	p[id]=fa;for(int i=0;i<e[x].size();++i)dfs(e[x][i],id);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	if(s>1ll*n*(n+1)/2 || s<n*2-1){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	if(s==1ll*n*(n+1)/2){
		for(i=2;i<=n;++i)cout<<i-1<<' ';
		return 0;
	}
	deg=findd();ini(deg);
	for(x=n;dep[x]==dep[n];--x);++x;
	for(i=2;i<=n;++i)++son[pp[i]];
	for(i=x;i;i=pp[i])son[i]=1<<30;
	for(i=n;i;--i)if(!son[i])q.push(i);
	for(;su<s;){
		y=q.front();q.pop();
		if(su+dep[x]+1-dep[y]>s)break;
		if(!--son[pp[y]])q.push(pp[y]);
		su+=dep[x]+1-dep[y];
		dep[y]=dep[x]+1;pp[y]=x;x=y;
	}
	if(su<s){
		for(;su+dep[x]+1-dep[y]>s;x=pp[x]);pp[y]=x;
	}
	for(i=2;i<=n;++i)e[pp[i]].push_back(i);
	dfs(1,0);
	for(i=2;i<=n;++i)cout<<p[i]<<' ';
	return 0;
}