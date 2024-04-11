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
struct P{
	ll x,y;
	P(){}
	P(ll _x,ll _y){
		x=_x; y=_y;
	}
	P operator +(const P &a)const{
		return P(x+a.x,y+a.y);
	}
	P operator -(const P &a)const{
		return P(x-a.x,y-a.y);
	}
	ll operator *(const P &a)const{
		return 1ll*x*a.y-1ll*y*a.x; 
	}
	ll operator ^(const P &a)const{
		return 1ll*x*a.x+1ll*y*a.y; 
	}
	bool operator <(const P &a)const{
		return x^a.x?x<a.x:y<a.y;
	}
};
ll Dis(P x,P y){
	return (x-y)^(x-y);
}
vector<P> init(vector<P> p){
	vector<P> ans;
	int pos=min_element(p.begin(),p.end())-p.begin();
	For(i,0,p.size()-1) ans.PB(p[(i+pos)%p.size()]);
	return ans;
}
vector<P> merge(vector<P> p,vector<P> q){
	p=init(p); q=init(q);
	int szp=p.size(),szq=q.size();
	vector<P> d1(szp),d2(szq);
	For(i,0,szp-1) d1[i]=p[(i+1)%szp]-p[i];
	For(i,0,szq-1) d2[i]=q[(i+1)%szq]-q[i];
	vector<P> ans;
	ans.PB(p[0]+q[0]);
	int pos1=0,pos2=0; 
	for (;pos1<szp||pos2<szq;)
		if (pos2==szq) ans.PB(ans.back()+d1[pos1++]);
		else if (pos1==szp) ans.PB(ans.back()+d2[pos2++]);
		else ans.PB(ans.back()+(d2[pos2]*d1[pos1]>=0?d2[pos2++]:d1[pos1++]));
	return ans;
}
bool online(P p,P l,P r){
	return ((p-l)*(r-l))==0&&((l-p)^(r-p))<=0;
}
bool check(P p,ll r,vector<P> pp){
	for (auto i:pp) if (Dis(p,i)<r*r) return 1;
	For(i,0,pp.size()-1){
		P L=pp[i],R=pp[(i+1)%pp.size()];
		if (((p-L)^(R-L))>0&&((p-R)^(L-R))>0){
			ll x=abs((p-L)*(R-L));
			if (x*x<r*r*Dis(L,R)) return 1;
		}
	}
	For(i,0,pp.size()-1)
		if (online(p,pp[i],pp[(i+1)%pp.size()]))
			return 1;
	bool flag=1;
	For(i,0,pp.size()-1)
		flag&=(((p-pp[i])*(pp[(i+1)%pp.size()]-pp[i]))<=0);
	return flag;
}
const int N=255;
struct edge{
	int to,next,f;
}e[4*N*N];
int head[N*2],tot=1,S,T;
int dis[N*2],q[N*2];
void add(int x,int y,int v){
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
int dfs(int x,int flow){
	if (x==T) return flow;
	int k,rest=flow;
	for (int i=head[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,min(flow,e[i].f));
			e[i].f-=k; e[i^1].f+=k; rest-=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int n,W,m;
struct circle{
	ll x,y,r;
}o[N];
int main(){
	scanf("%d%d",&n,&W);
	vector<P> p(n),q(n);
	For(i,0,n-1){
		scanf("%lld%lld",&p[i].x,&p[i].y);
		q[i].x=-p[i].x; q[i].y=-p[i].y;
	}
	ll mn=p[0].x,mx=p[0].x;
	For(i,0,n-1){
		mn=min(mn,p[i].x);
		mx=max(mx,p[i].x);
	}
	p=merge(p,q);
	scanf("%d",&m);
	S=2*m+1; T=2*m+2;
	For(i,1,m) scanf("%lld%lld%lld",&o[i].x,&o[i].y,&o[i].r);
	For(i,1,m){
		add(i*2-1,i*2,1);
		if (mx-mn>o[i].x-o[i].r) add(S,i*2-1,1<<30);
		if (mx-mn>W-o[i].x-o[i].r) add(i*2,T,1<<30);
	}
	For(i,1,m) For(j,i+1,m)
		if (check(P(o[j].x-o[i].x,o[j].y-o[i].y),o[j].r+o[i].r,p)){
			add(i*2,j*2-1,1<<30);
			add(j*2,i*2-1,1<<30);
		}
	int ans=0;
	for (;bfs();ans+=dfs(S,1<<30));
	printf("%d\n",ans);
}
/*
2 10
0 0
2 0
*/