#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=120100;
VI vec[N];
int a[N],b[N],c[N],n,p[N],vis[N];
namespace oula {
	const int M=4010000;
	vector<PII> pth;
	int tot,nxt[M],fst[M],y[M],h[M],n;
	void init(int m) {
		tot=1; n=m;
		for (int i=0;i<m;i++) fst[i]=0;
	}
	void add(int u,int v) {
		tot++; nxt[tot]=fst[u]; fst[u]=tot; y[tot]=v; h[tot]=1;
		tot++; nxt[tot]=fst[v]; fst[v]=tot; y[tot]=u; h[tot]=1;
	}
	void dfs(int u) {
		for (int j=fst[u];j;j=fst[u]) {
			fst[u]=nxt[j];
			if (h[j]) {
				h[j]=h[j^1]=0;
				int v=y[j]; dfs(v);
				pth.pb(mp(y[j],y[j^1]));
			}
		}
	}
	vector<PII> solve() {
		pth.clear();
		rep(i,0,n) dfs(i);
		return pth;
	}
}
int main() {
	scanf("%d",&n);
	rep(i,0,4*n) {
		scanf("%d%d%d",a+i,b+i,c+i);
		vec[b[i]].pb(i); vec[c[i]].pb(i);
	}
	oula::init(8*n);
	rep(i,0,4*n) rep(j,0,8) oula::add(i,vec[a[i]][j]+4*n);
	for (int rd=0;rd<3;rd++) {
		vector<PII> e=oula::solve();
		oula::init(8*n);
		for (int j=0;j<SZ(e);j+=2) {
			oula::add(e[j].fi,e[j].se);
		}
	}
	vector<PII> e=oula::solve();
	rep(j,0,SZ(e)) {
		if (e[j].fi>e[j].se) swap(e[j].fi,e[j].se);
		p[e[j].fi]=e[j].se-4*n;
	}
	puts("YES");
	rep(j,0,4*n) if (!vis[j]) {
		int x=j;
		while (1) {
			printf("%d ",x+1);
			vis[x]=1; x=p[x];
			if (x==j) break;
		}
	}
	puts("");
}