// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fbo find_by_order
#define ook order_of_key
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define MOD 1000000007 
#define MID (l+r)/2
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mx 300003
#define pc(x) putchar_unlocked(x);
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n, par[mx], u, v, level[mx], in[mx], out[mx], id[mx], idx, child[mx], depth[mx], sz[mx], mana[mx], bc[mx];
vector<int> g[mx], ve[mx];

void dfs(int now, int p, int lev = 0){
	par[now] = p;
	level[now] = lev;
	sz[now] = 1;
	for(int i : g[now]){
		if(i != p){
			dfs(i, now, lev + 1);
			sz[now] += sz[i];
			if(bc[now] == 0 || sz[bc[now]] < sz[i])
				bc[now] = i;
		}
	}
}

void DFS(int now, int p){
	if(bc[p] == now){
		mana[now] = mana[p];
	}
	else{
		mana[now] = ++idx;
	}
	ve[mana[now]].pb(now);
	for(int i : g[now]){
		if(i != p){
			DFS(i, now);
		}
	}
}

int hit = 0;

int D(int now){
	hit ++;
	assert(hit <= 36);
	cout << "d " << now << endl;
	int ret;
	cin >> ret;
	return ret;
}

int S(int now){
	hit ++;
	assert(hit <= 36);
	cout << "s " << now << endl;
	int ret;
	cin >> ret;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// cout.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	DFS(1, 0);
	int dist = D(1), now = 1;
	if(dist == 0){
		cout << "! " << 1 << endl;
		return 0;
	}
	while(1){
		int aa = D(ve[mana[now]].back());
		if(aa == 0){
			cout << "! " << ve[mana[now]].back() << endl;
			return 0;
		}
		// else if(aa == dist + level[ve[mana[now]].back()] - 2 * level[now]){
		// 	now = S(now);
		// }
		else{
			int lca = dist - aa + level[ve[mana[now]].back()];
			assert(lca % 2 == 0);
			lca /= 2;
			if(lca == dist){
				bool ada = false;
				for(int i : ve[mana[now]]){
					if(level[i] == dist){
						ada = true;
						cout << "! " << i << endl;
						return 0;
					}
				}
				assert(ada);
			}
			bool ada = false;
			for(int i : ve[mana[now]]){
				if(level[i] == lca){
					now = i;
					ada = true;
					break;
				}
			}
			assert(ada);
			// debug(lca);
			now = S(now);
		}
	}
	assert(false);
}