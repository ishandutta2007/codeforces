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
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=10005;
struct edge{
	int to,next;
	ll f;
}e[N];
int head[N],tot,S,T;
int dis[N],q[N];
void add(int x,int y,ll v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(){
	For(i,1,T) dis[i]=-1;
	int t=1; dis[q[1]=S]=0;
	For(h,1,t) for (int i=head[q[h]];i;i=e[i].next)
		if (dis[e[i].to]==-1&&e[i].f){
			dis[e[i].to]=dis[q[h]]+1;
			if (e[i].to==T) return 1;
			q[++t]=e[i].to;
		}
	return 0;
}
ll dfs(int x,ll flow){
	if (x==T) return flow;
	ll k,rest=flow;
	for (int i=head[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,min(rest,e[i].f));
			e[i].f-=k; e[i^1].f+=k; rest-=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int x[N],y[N],n,m;
int a[N],b[N],c[N],d[N];
ll deg[N],LIM=100000000;
ll F(ll v){
	For(i,1,n+2) head[i]=deg[i]=0;
	S=n+1; T=n+2; tot=1;
	For(i,1,m){
		ll L=a[i]*v+b[i]*LIM;
		ll R=c[i]*v+d[i]*LIM;
		add(x[i],y[i],R-L);
		deg[y[i]]+=L;
		deg[x[i]]-=L;
	}
	ll ans=0;
	For(i,1,n)
		if (deg[i]>0) add(S,i,deg[i]),ans+=deg[i];
		else add(i,T,-deg[i]);
	for (;bfs();ans-=dfs(S,1ll<<60));
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m) scanf("%d%d%d%d%d%d",&x[i],&y[i],&a[i],&b[i],&c[i],&d[i]);
	int l=0,r=LIM;
	for (;r-l>=5;){
		int m1=l+(r-l)/3,m2=r-(r-l)/3;
		if (F(m1)<F(m2)) r=m2;
		else l=m1;
	}
	pll mn(8e18,8e18);
	For(i,l,r) mn=min(mn,pll(F(i),i));
	if (mn.fi) return puts("0"),0;
	l=mn.se+1; r=LIM;
	int ansr=mn.se;
	while (l<=r){
		int mid=(l+r)/2;
		if (!F(mid)) ansr=mid,l=mid+1;
		else r=mid-1;
	}
	l=0; r=mn.se-1;
	int ansl=mn.se;
	while (l<=r){
		int mid=(l+r)/2;
		if (!F(mid)) ansl=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%.10lf\n",1.0*(ansr-ansl)/LIM);
}