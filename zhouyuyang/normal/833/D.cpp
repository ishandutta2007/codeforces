#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define BG begin
#define ED end

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

#define INF (1ll<<60)
#define sqr(x) ((x)*(x))
using namespace std;
const int mo=1000000007;
const int N=200005;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int T;
struct Tarr{
	int s[N*4],t[N*4],vis[N*4];
	void add(int x,int v){
		x+=N*2;
		for (;x<N*4;x+=x&(-x)){
			if (vis[x]!=T){
				vis[x]=T;
				s[x]=0; t[x]=1;
			}
			s[x]++;
			t[x]=1ll*t[x]*v%mo;
		}
	}
	void mul(int x,int &v1,int &v2){
		x+=N*2;
		for (;x;x-=x&(-x))
			if (vis[x]==T){
				v1=1ll*v1*t[x]%mo;
				v2+=s[x];
			}
	}
}T0,T1;
struct edge{
	int to,next,v,c;
}e[N*2];
int head[N],tot;
void add(int x,int y,int v,int c){
	e[++tot]=(edge){y,head[x],v,c};
	head[x]=tot;
}
int sz[N],vis[N];
int frt,rt,Sz,mn,n,ans;
void getrt(int x,int fa){
	sz[x]=1; int mx=0;
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]&&e[i].to!=fa){
			getrt(e[i].to,x);
			sz[x]+=sz[e[i].to];
			mx=max(mx,sz[e[i].to]);
		}
	mx=max(mx,Sz-sz[x]);
	if (mx<mn) mn=mx,rt=x,frt=fa;
}
struct data{
	int a,b,val;
}q[N];
int top;
void dfs2(int x,int fa,int a,int b,int v){
	q[++top]=(data){a*2-b,b*2-a,v};
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to])
			dfs2(e[i].to,x,a+e[i].c,b+(!e[i].c),1ll*v*e[i].v%mo);
}
void solve(int x){
	vis[x]=1; T++;
	T0.add(0,1); T1.add(0,1);
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]){
			top=0;
			dfs2(e[i].to,0,e[i].c,!e[i].c,e[i].v);
			For(j,1,top){
				int pi=1,t=0,s=0;
				T0.mul(q[j].a,ans,s);
				T1.mul(-q[j].b-1,pi,t);
				ans=1ll*ans*power(pi,mo-2)%mo;
				ans=1ll*ans*power(q[j].val,s-t)%mo;
			}
			For(j,1,top)
				T0.add(-q[j].a,q[j].val),
				T1.add(q[j].b,q[j].val);
		}
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]){
			mn=1e9; Sz=sz[e[i].to];
			getrt(e[i].to,x);
			sz[frt]=Sz-sz[rt];
			solve(rt);
		}
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y,v,c;
		scanf("%d%d%d%d",&x,&y,&v,&c);
		add(x,y,v,c);
		add(y,x,v,c);
	}
	ans=1; mn=1e9; Sz=n;
	getrt(1,0); 
	sz[frt]=Sz-sz[rt];
	solve(rt);
	printf("%d\n",ans);
}
/*
2*(r+R)>b+B
2*r-b>B-2*R
*/