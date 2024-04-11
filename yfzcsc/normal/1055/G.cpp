/*
r=0X1=(x1,y1),X2=(x2,y2)
X1+(-P),X2+(-P)

X2-X1 in P+(-P)? 
*/
#include<bits/stdc++.h>
#define maxn 101000
using namespace std;
typedef long long ll;
namespace WXHAK{
	struct edge{
		int r,nxt,w;
	}e[1010000];
	int head[1001000],q[1001000],l,r,S,T,esz,cur[1010000],dep[1001000];
	void adde(int u,int v,int w){
//		printf("[%d->%d]\n",u,v);
		e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;e[esz].w=w;
		e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;e[esz].w=0;
	}
	bool bfs(){
		for(int i=S;i<=T;++i)dep[i]=0,cur[i]=head[i];
		l=r=0,q[r++]=S,dep[S]=1;
		while(l<r){
			int u=q[l++];
			for(int t=head[u];t;t=e[t].nxt)if(e[t].w&&!dep[e[t].r])
				dep[e[t].r]=dep[u]+1,q[r++]=e[t].r;
		}
		return dep[T]!=0;
	}
	int find(int u,int flow){
		if(u==T)return flow;
		int used=0,a=0;
		for(int& t=cur[u];t;t=e[t].nxt)if(e[t].w&&dep[e[t].r]==dep[u]+1){
			a=find(e[t].r,min(flow-used,e[t].w)),e[t].w-=a,e[t^1].w+=a,used+=a;
			if(used==flow)return used;
		}
		return used;
	}
	void clr(int nS,int nT){
		for(int i=S;i<=T;++i)head[i]=0;
		S=nS,T=nT,esz=1;
	}
	int dinic(){
		int ans=0;
		while(bfs())ans+=find(S,1<<30);
		return ans;
	}
}
struct point{
	ll x,y;
	point(){}
	void scan(){scanf("%lld%lld",&x,&y);}
	point(ll x,ll y):x(x),y(y){}
	point operator+(const point& p)const{return point(x+p.x,y+p.y);}
	point operator-(const point& p)const{return point(x-p.x,y-p.y);}
	point neg(){return point(-x,-y);}
	int operator<(const point& p)const{return p.x==x?y<p.y:x<p.x;}
}O[maxn];
ll pf(ll x){return x*x;}
ll cross(point a,point b){return (ll)a.x*b.y-(ll)a.y*b.x;}
ll dist(point a,point b){return pf(a.x-b.x)+pf(a.y-b.y);}
ll dot(point a,point b){return (ll)a.x*b.x+(ll)a.y*b.y;}
int n,R[maxn],w,m;
vector<point> J(vector<point> P){
	vector<point> ret;
	int p=min_element(P.begin(),P.end())-P.begin();
	for(int i=0;i<P.size();++i)ret.push_back(P[(i+p)%P.size()]);
	return ret;
}
vector<point> sol(vector<point> P,vector<point> Q){
	P=J(P),Q=J(Q);
//	for(auto c:P)printf("[%lld,%lld]",c.x,c.y);puts("");
//	for(auto c:Q)printf("[%lld,%lld]",c.x,c.y);
	
	vector<point> a1(P.size()),a2(Q.size());
	for(int i=0;i<P.size();++i)a1[i]=P[(i+1)%P.size()]-P[i];
	for(int i=0;i<Q.size();++i)a2[i]=Q[(i+1)%Q.size()]-Q[i];
	vector<point> ret;
	ret.push_back(P[0]+Q[0]);
	int i=0,j=0;
	while(i<a1.size()||j<a2.size()){
		if(i==a1.size()){
			ret.push_back(a2[j++]+ret.back());
		} else if(j==a2.size()){
			ret.push_back(a1[i++]+ret.back());
		} else {
			ret.push_back((cross(a2[j],a1[i])>=0?a2[j++]:a1[i++])+ret.back());
		}
	}
//	for(auto d:ret)printf("[%lld,%lld]",d.x,d.y);
	return ret;
}
int onseg(point P,point L,point R){
	return cross(P-L,R-L)==0&&dot(L-P,R-P)<=0;
}
int chk(point P,vector<point>& p,ll r){
	for(auto c:p)if(dist(c,P)<r*r)return 1;
//	puts("OK");
	for(int i=0;i<p.size();++i){
		point L=p[i],R=p[i==p.size()-1?0:i+1];
		if(dot(P-L,R-L)>0&&dot(P-R,L-R)>0){
			ll x=abs(cross(P-L,R-L));
			if(x*x<r*r*dist(L,R))return 1;	
		}
	}
	
	for(int i=0;i<p.size();++i)
		if(onseg(P,p[i],p[i==p.size()-1?0:i+1]))return 1;
//	puts("OK");
	int flg=1;
	for(int i=0;i<p.size();++i)
		flg&=cross(P-p[i],p[i==p.size()-1?0:i+1]-p[i])<=0;
	return flg;
}
int main(){
//	printf("[%lld]",cross(point(0,1),point(1,0)));
	scanf("%d%d",&n,&w);
	vector<point>P(n),Q(n);
	for(int i=0;i<n;++i)P[i].scan();
	ll mnx=P[0].x,mxx=P[0].x;
	for(int i=0;i<n;++i)mnx=min(mnx,P[i].x),mxx=max(mxx,P[i].x);
	for(int i=0;i<n;++i)Q[i]=P[i].neg();
	auto c=sol(P,Q);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)O[i].scan(),scanf("%d",&R[i]);
	WXHAK::clr(0,m*2+2);
	for(int i=1;i<=m;++i){
		WXHAK::adde(i*2,i*2+1,1);
		if(mxx-mnx>O[i].x-R[i])WXHAK::adde(0,i*2,1<<30);
		if(mxx-mnx>w-O[i].x-R[i])WXHAK::adde(i*2+1,m*2+2,(1<<30));
	}
	for(int i=1;i<=m;++i)
		for(int j=i+1;j<=m;++j)
			if(chk(O[j]-O[i],c,R[i]+R[j]))
				WXHAK::adde(i*2+1,j*2,1<<30),
				WXHAK::adde(j*2+1,i*2,1<<30);//,printf("[%d,%d]",i,j);
	printf("%d",WXHAK::dinic());
}