#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n)-1;i>=(a);i--)

const int MAX_N = int(1e6 + 10);

int n,m;

vector<int> E[MAX_N];
int selfLoop[MAX_N];

int deg[MAX_N];

bool vis[MAX_N];

void dfs(int u){
	if(vis[u]) return;
	vis[u] = 1;
	for(auto e: E[u]) dfs(e);
}

int main(){
	cin>>n>>m;

	if(m<2){
		cout<<0<<endl;
		return 0;
	}

	int nSelfLoop = 0;

	rep(it,0,m){
		int u,v;
		scanf("%d%d",&u,&v),--u,--v;
		E[u].push_back(v);
		E[v].push_back(u);
		deg[u]^=1;
		deg[v]^=1;

		if(u==v){
			++nSelfLoop;
			selfLoop[u] = 1;
		}
	}

	rep(i,0,n){
		if(E[i].size()){
			dfs(i);
			break;
		}
	}

	rep(i,0,n){
		if(E[i].size() && !vis[i]){
			cout<<0<<endl;
			return 0;
		}
	}

	long long ans = 0;
	rep(i,0,n) {
		int deg = E[i].size() - selfLoop[i] * 2;
		ans += 1LL * deg * (deg - 1) / 2;
	}

	//one selfloop
	ans += 1LL * nSelfLoop * (m-nSelfLoop);
	//two selfloop
	ans += 1LL * nSelfLoop * (nSelfLoop - 1) /2;
	cout<<ans<<endl;
	return 0;
}