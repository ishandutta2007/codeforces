#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define pb push_back
#define inf 200000
struct pa {
	int x,y,ans;
}dis[N][24][2];
#define P 998244353
int Q[N];
vector<int>A[N],B[N];
int n,m,x,y;
inline bool check(pa x,pa y) {
	int f1=(x.x>=22),f2=(y.x>=22);
	if (f1&&f2) {
		if (x.x!=y.x) return x.x>y.x;
		return x.y>y.y;
	}
	if (f1!=f2) return f1>f2;
	return x.ans>y.ans;
}
inline bool equ(pa x,pa y) {
	return (x.x==y.x&&x.y==y.y);
}
struct node {
	int x,v,f;
	pa p;
};
struct cmp {
	inline bool operator ()(node x,node y) {
		//printf("%d %d %d\n",x.p.x,y.p.x,equ(x.p,y.p));
		if (equ(x.p,y.p)) {
			if (x.x!=y.x)
				return x.x<y.x;
			if (x.v!=y.v)
				return x.v<y.v;
			return x.f<y.f;
		}
		return !check(x.p,y.p);
	}
};
set<node,cmp>G;
inline pa work(pa x,int a,int b) {
	x.x+=a;
	x.y+=b;
	x.ans=(Q[x.x]+x.y)%P;
	x.ans=(x.ans+P-1)%P;
	return x;
}
inline bool check(pa x,pa y,int a,int b) {
	return check(x,work(y,a,b));
}
int main() {
	//freopen("0.in","r",stdin);
	Q[0]=1;
	for (int i=1;i<=200000;i++) Q[i]=Q[i-1]*2%P;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		A[x].pb(y);
		B[y].pb(x);
	}
	for (int i=1;i<=n;i++)
	for (int j=0;j<=23;j++) 
	for (int k=0;k<=1;k++) {
		dis[i][j][k]=pa{inf,inf,P};
	}
	dis[1][0][0]=pa{0,0,0};
	G.insert(node{1,0,0,dis[1][0][0]});
	while (!G.empty()) {
		node now=(*G.begin());
		//printf("%d %d %d %d\n",now.x,now.v,now.f,now.p.ans);
		G.erase(G.begin());
		if (now.x==n) {
			printf("%d\n",now.p.ans);
			return 0;
		}
		if (now.f==0) {
			for (auto p:A[now.x]) {
				if (check(dis[p][now.v][now.f],now.p,0,1)) {
					if (dis[p][now.v][now.f].x!=inf)
					G.erase(node{p,now.v,now.f,dis[p][now.v][now.f]});
					dis[p][now.v][now.f]=work(now.p,0,1);
					G.insert(node{p,now.v,now.f,dis[p][now.v][now.f]});
				}
			}
			for (auto p:B[now.x]) {
				int nv=now.v+1;
				if (nv>23) nv=22;
				if (check(dis[p][nv][now.f^1],now.p,1,1)) {
					if (dis[p][nv][now.f^1].x!=inf)
					G.erase(node{p,nv,now.f^1,dis[p][nv][now.f^1]});
					dis[p][nv][now.f^1]=work(now.p,1,1);
					G.insert(node{p,nv,now.f^1,dis[p][nv][now.f^1]});
				}
			}
		}
		else {
			for (auto p:B[now.x]) {
				if (check(dis[p][now.v][now.f],now.p,0,1)) {
					if (dis[p][now.v][now.f].x!=inf)
					G.erase(node{p,now.v,now.f,dis[p][now.v][now.f]});
					dis[p][now.v][now.f]=work(now.p,0,1);
					G.insert(node{p,now.v,now.f,dis[p][now.v][now.f]});
				}
			}
			for (auto p:A[now.x]) {
				int nv=now.v+1;
				if (nv>23) nv=22;
				if (check(dis[p][nv][now.f^1],now.p,1,1)) {
					if (dis[p][nv][now.f^1].x!=inf)
					G.erase(node{p,nv,now.f^1,dis[p][nv][now.f^1]});
					dis[p][nv][now.f^1]=work(now.p,1,1);
					G.insert(node{p,nv,now.f^1,dis[p][nv][now.f^1]});
				}
			}
		}
	}
}