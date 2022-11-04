#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
const int N=200005;
struct P{
	ll x,y;
	P operator +(const P &a)const{
		return (P){x+a.x,y+a.y};
	}
	P operator -(const P &a)const{
		return (P){x-a.x,y-a.y};
	}
	ll operator *(const P &a)const{
		return x*a.y-y*a.x;
	}
	ll V(int k)const{
		return x*k+y;
	}
}dis[N];
vector<pair<int,P> > e[N],E[N];
vector<P> l,r,all;
int n,m,rt,frt,sz[N];
bool vis[N];
void rebuild(int x,int fa){
	vector<pair<int,P> > son;
	for (auto i:e[x]) if (i.fi!=fa)
		son.PB(i),rebuild(i.fi,x);
	for (int i=0,t=x;i<son.size();i++){
		if (i&&i+1<son.size()){
			E[++n].EB(t,(P){0,0});
			E[t].EB(n,(P){0,0});
			t=n;
		}
		E[t].EB(son[i].fi,son[i].se);
		E[son[i].fi].EB(t,son[i].se);
	}
}
void findrt(int x,int fa,int Sz){
	sz[x]=1;
	for (auto i:E[x])
		if (i.fi!=fa&&!vis[i.fi]){
			findrt(i.fi,x,Sz);
			sz[x]+=sz[i.fi];
		}
	if (rt==-1||max(sz[rt],Sz-sz[rt])>max(sz[x],Sz-sz[x]))
		rt=x,frt=fa;
}
void init(int x,int fa,bool sub){
	if (sub) r.PB(dis[x]);
	else l.PB(dis[x]);
	for (auto i:E[x])
		if (i.fi!=fa&&!vis[i.fi]){
			dis[i.fi]=dis[x]+i.se;
			init(i.fi,x,sub||i.fi==rt);
		}
}
bool cmp(const P &a,const P &b){
	return a.x==b.x?a.y>b.y:a.x<b.x;
}
vector<P> convex(vector<P> v){
	vector<P> ans;
	sort(v.begin(),v.end(),cmp);
	int m=0;
	for (int i=0;i<v.size();i++){
		if (i&&v[i].x==v[i-1].x) continue;
		for (;m&&ans[m-1].y<=v[i].y;ans.pop_back(),m--);
		for (;m>1&&(v[i]-ans[m-2])*(ans[m-1]-ans[m-2])<=0;ans.pop_back(),m--);
		ans.push_back(v[i]),m++;
	}
	return ans;
}
void sum(vector<P> a,vector<P> b){
	all.PB(a[0]+b[0]);
	for (int i=0,j=0;i+1<a.size()||j+1<b.size();)
		if (j+1==b.size()||(i+1<a.size()&&(a[i+1]-a[i])*(b[j+1]-b[j])<0))
			all.PB(a[++i]+b[j]);
		else all.PB(a[i]+b[++j]);
}
void divide(int x,int Sz){
	if (Sz==1) return;
	rt=-1; findrt(x,0,Sz);
	int u=rt,v=frt,szu=sz[u],szv=Sz-szu;
	dis[v]=(P){0,0};
	l.clear(); r.clear();
	init(v,0,0);
	l=convex(l); r=convex(r);
	sum(l,r);
	vis[v]=1; divide(u,szu); vis[v]=0;
	vis[u]=1; divide(v,szv); vis[u]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	if (n==1){
		for (int i=0;i<m;i++)
			printf("0 ");
		return 0;
	}
	for (int i=1;i<n;i++){
		int x,y,a,b;
		scanf("%d%d%d%d",&x,&y,&a,&b);
		e[x].EB(y,(P){a,b});
		e[y].EB(x,(P){a,b});
	}
	rebuild(1,0);
	divide(1,n);
	all=convex(all);
	for (int i=0,j=0;i<m;i++){
		for (;j+1<all.size()&&all[j+1].V(i)>=all[j].V(i);j++);
		printf("%lld ",all[j].V(i));
	}
}