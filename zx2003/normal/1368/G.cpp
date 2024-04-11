#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string c[N];
int n,m,i,j,U;
inline int idx(int x,int y){return x*m+y;}
vector<int>e[N];int fa[N];
int be[N],en[N],dcnt;
void dfs(int x){
	be[x]=++dcnt;
	for(int y:e[x]){
assert(!be[y]);
		dfs(y);
	}
	en[x]=dcnt;
}
struct node{
	int lb,rb,md;
	int mn,cnt,ad;
}t[N*3];
inline void upd(int i){
	t[i].mn=min(t[i<<1].mn,t[i<<1|1].mn);
	t[i].cnt=(t[i<<1].mn==t[i].mn?t[i<<1].cnt:0)+(t[i<<1|1].mn==t[i].mn?t[i<<1|1].cnt:0);
	t[i].mn+=t[i].ad;
}
void build(int i,int l,int r){
	t[i]=(node){l,r,l+r>>1,0,r-l+1,0};if(l==r)return;
	build(i<<1,l,t[i].md);build(i<<1|1,t[i].md+1,r);
}
void mdy(int i,int l,int r,int v){
	if(l<=t[i].lb && t[i].rb<=r){t[i].ad+=v;t[i].mn+=v;return;}
	if(l<=t[i].md)mdy(i<<1,l,r,v);if(t[i].md<r)mdy(i<<1|1,l,r,v);upd(i);
}
struct opt{int l,r,v;};
vector<opt>ve[N];
inline void addrec(int x1,int x2,int y1,int y2){
	if(x1>y1)swap(x1,y1),swap(x2,y2);
	ve[x1].push_back((opt){y1,y2,1});ve[x2+1].push_back((opt){y1,y2,-1});
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;U=n*m;
	for(i=0;i<n;++i)cin>>c[i];
	memset(fa,-1,U<<2);
	for(i=0;i<n;++i)for(j=0;j<m;++j){
		if(c[i][j]=='L' && j+2<m)fa[idx(i,j)]=idx(i,j+2);
		if(c[i][j]=='R' && j-2>=0)fa[idx(i,j)]=idx(i,j-2);
		if(c[i][j]=='U' && i+2<n)fa[idx(i,j)]=idx(i+2,j);
		if(c[i][j]=='D' && i-2>=0)fa[idx(i,j)]=idx(i-2,j);
	}
	for(i=0;i<U;++i)if(fa[i]!=-1)e[fa[i]].push_back(i);
	for(i=0;i<U;++i)if(fa[i]==-1)dfs(i);
for(i=0;i<U;++i)assert(be[i]);
	for(i=0;i<n;++i)for(j=0;j<m;++j){
		if(c[i][j]=='L')addrec(be[idx(i,j)],en[idx(i,j)],be[idx(i,j+1)],en[idx(i,j+1)]);
		if(c[i][j]=='U')addrec(be[idx(i,j)],en[idx(i,j)],be[idx(i+1,j)],en[idx(i+1,j)]);
	}
	long long ans=0;
	build(1,1,U);
	for(i=1;i<=dcnt;++i){
		for(auto u:ve[i])mdy(1,u.l,u.r,u.v);
		ans+=U-t[1].cnt;
	}
	cout<<ans<<endl;
}