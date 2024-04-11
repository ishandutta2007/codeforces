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

const int MAX_N = int(3e5 + 10);
int n,m;

vector<int> edge[MAX_N];

vector<int> col[MAX_N],vet[MAX_N];

int mark[MAX_N];

void dfs(int u, int fa){
	static int cur[MAX_N] = {}, T = 0;
	++T;

	for(auto e:col[u]){
		if(mark[e] != -1){
			cur[mark[e]] = T;
		}
	}

	int at = 0;

	for(auto e : col[u]){
		if(mark[e] == -1){
			while(cur[at] == T)
				++at;
			mark[e] = at;
			++at;
		}
	}

	for(auto i : edge[u]) if(i != fa)
		dfs(i,u);
}

int main(){
	scanf("%d%d",&n,&m);

	int ret = 0;
	rep(i,0,n){
		int s;scanf("%d",&s);
		rep(j,0,s){
			int x;scanf("%d",&x),--x;
			col[i].pb(x);
			vet[x].pb(i);
		}
		ret = max(ret,s);
	}
	rep(_,0,n-1){
		int a,b;scanf("%d%d",&a,&b),--a,--b;
		edge[a].pb(b); edge[b].pb(a);
	}

	memset(mark,-1,sizeof mark);

	dfs(0,-1);

	ret = max(ret,1);

	rep(i,0,m) if(mark[i] == -1) mark[i] = 0;

	cout<<ret<<endl;
	rep(i,0,m)
		cout<<mark[i]+1<<" ";
	cout<<endl;
}