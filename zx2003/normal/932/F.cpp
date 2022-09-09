#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
vector<int>e[N];
ll min(const ll&a,const ll&b){return a<b?a:b;}
struct node{
	int l,r,k;ll b;
}t[8000000];
int xb;
void add(int&i,int l,int r,int k,ll b){
	if(!i){i=++xb;t[i].k=k,t[i].b=b;return;}
	ll v1=1ll*t[i].k*l+t[i].b,v2=1ll*t[i].k*r+t[i].b,v3=1ll*k*l+b,v4=1ll*k*r+b;
	if(v1<=v3 && v2<=v4)return;
	if(v1>=v3 && v2>=v4){t[i].k=k,t[i].b=b;return;}
	int m=(l+r)>>1;
	v1=1ll*m*t[i].k+t[i].b,v2=1ll*m*k+b;
	if(v1>v2){
		if(t[i].k>k)add(t[i].l,l,m,t[i].k,t[i].b);
			else add(t[i].r,m+1,r,t[i].k,t[i].b);
		t[i].k=k,t[i].b=b;
	}else{
		if(t[i].k>k)add(t[i].r,m+1,r,k,b);
			else add(t[i].l,l,m,k,b);
	}
}
ll query(int i,int l,int r,int x){
	if(!i)return 1ll<<60;
	ll ans=1ll*t[i].k*x+t[i].b;
	if(l==r)return ans;
	int m=(l+r)>>1;
	if(x<=m)return min(ans,query(t[i].l,l,m,x));
		else return min(ans,query(t[i].r,m+1,r,x));
}
int merge(int x,int y,int l,int r){
	if(!x || !y)return x|y;
	int m=(l+r)>>1;
	t[x].l=merge(t[x].l,t[y].l,l,m);
	t[x].r=merge(t[x].r,t[y].r,m+1,r);
	add(x,l,r,t[y].k,t[y].b);return x;
}
int a[N],b[N],n,i,u,v,rt[N],mi,ma;
ll f[N];
void dfs(int x,int fa){
	int i;for(i=0;i<(int)e[x].size();++i)if(e[x][i]!=fa){
		dfs(e[x][i],x);rt[x]=merge(rt[x],rt[e[x][i]],mi,ma);
	}
	if(e[x].size()>1 || x==1)f[x]=query(rt[x],mi,ma,a[x]);
	add(rt[x],mi,ma,b[x],f[x]);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin>>n;mi=1<<30;ma=-mi;
	for(i=1;i<=n;++i)cin>>a[i],a[i]<mi?mi=a[i]:0,a[i]>ma?ma=a[i]:0;
	for(i=1;i<=n;++i)cin>>b[i];
	for(i=1;i<n;++i){
		cin>>u>>v;
		e[u].push_back(v),e[v].push_back(u);
	}
	dfs(1,0);for(i=1;i<=n;++i)cout<<f[i]<<' ';
	return 0;
}