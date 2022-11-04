#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int inf=(1<<30);
const int N=201000;
int n,m,f[N],u,v,w,dep[N],ret[N];
vector<VI> E,Ew;
vector<PII> e[N];
int mark[N],p[N][20],pe[N][20],pid[N];
void dfs(int u,int f) {
	dep[u]=dep[f]+1;
	for (auto w:e[u]) {
		int v=w.fi;
		if (v==f) continue;
		p[v][0]=u;
		pid[v]=w.se;
		pe[v][0]=Ew[pid[v]][0];
		dfs(v,u);
	}
}
int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
#define LOGN 18

int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	int mv=0;
	per(i,0,LOGN) if (dep[p[v][i]]>=dep[u]) mv=max(mv,pe[v][i]),v=p[v][i];
	if (u==v) return mv;
	per(i,0,LOGN) if (p[v][i]!=p[u][i]) mv=max(mv,max(pe[u][i],pe[v][i])),u=p[u][i],v=p[v][i];
	return max(mv,max(pe[u][0],pe[v][0]));
}


int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) f[i]=i;
	rep(i,0,m) {
		scanf("%d%d%d",&u,&v,&w);
		E.pb(VI{w,u,v,i});
		Ew.pb(VI{w,u,v,i});
	}
	sort(all(E));
	rep(i,0,m) {
		int id=E[i][3],u=E[i][2],v=E[i][1];
		if (find(u)!=find(v)) {
			mark[id]=1;
			e[u].pb(mp(v,id)); e[v].pb(mp(u,id));
			f[find(u)]=find(v);
		}
	}
	dfs(1,0);
	rep(j,1,LOGN) {
		rep(i,1,n+1) {
			p[i][j]=p[p[i][j-1]][j-1];
			pe[i][j]=max(pe[i][j-1],pe[p[i][j-1]][j-1]);
		}
	}
	rep(i,1,n+1) f[i]=i;
	rep(i,0,m) ret[i]=inf;
	rep(i,0,m) {
		int id=E[i][3],u=E[i][2],v=E[i][1];
		if (!mark[id]) {
			ret[id]=lca(u,v);
			while (1) {
				u=find(u);
				v=find(v);
				if (u==v) break;
				if (dep[v]>dep[u]) swap(u,v);
				ret[pid[u]]=E[i][0];
				f[u]=find(p[u][0]);
			}
		}
	}
	rep(i,0,m) {
		if (ret[i]==inf) ret[i]=0;
		printf("%d\n",ret[i]-1);
	}
}