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
int n,m;
const int MAX_N = int(3e5) + 10;
vector<int> adj[MAX_N];
vector<int> vec[MAX_N];

int cnt;
set<int> edge[MAX_N];
int id[MAX_N];

int d[MAX_N];

int main(){
	cin>>n>>m;
	rep(_,0,m){
		int u,v;
		scanf("%d%d",&u,&v);
		--u,--v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i,0,n) adj[i].pb(i);

	rep(i,0,n) sort(adj[i].begin(), adj[i].end());

	rep(i,0,n) vec[i] = adj[i];
	sort(vec,vec+n);
	cnt = unique(vec,vec+n) - vec;

	rep(i,0,n){
		id[i] = lower_bound(vec,vec+cnt,adj[i]) - vec;
	}

	rep(i,0,n) for(auto j : adj[i])
		if(id[i] != id[j]){
			edge[id[i]].insert(id[j]);
			edge[id[j]].insert(id[i]);
		}

	//check if it is a chain

	rep(i,0,cnt) if(edge[i].size() > 2){
		puts("NO");
		return 0;
	}

	int start = -1;

	rep(i,0,cnt) if(edge[i].size() <= 1){
		start = i;
		break;
	}

	vector<int> chain;
	if(start == -1){
		puts("NO");
		return 0;
	}

	int prev = -1;
	int cur = start;
	int num = 0;

	for(;;){
		chain.pb(cur);
		d[cur] = ++num;

		int next = -1;
		for(auto i : edge[cur]) if(i != prev){
			next = i;
			break;
		}

		prev = cur;
		cur = next;

		if(next == -1) break;
	}

	if(num < cnt){
		puts("NO");
	} else {
		puts("YES");
		rep(i,0,n)
			printf("%d ",d[id[i]]);
		puts("");
	}
	return 0;
}