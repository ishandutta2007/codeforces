#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cassert>
#include <bitset>
typedef long long ll ;
#define fi first
#define se second
#define mp make_pair
#define rep(i, a, b) for (int i = a; i < b; ++ i) 
const int N = 1e5 + 5, M = 1e5 ;
using namespace std ;
typedef pair<int,pair<ll,int> > state;

ll myrand() {
	return ((ll)(rand()&65535)<<32)+((ll)rand()<<16)+rand();
}
state st1[N],st2[N];
int vis[N],dis[N],off,pre[N],n,deg[N],deg2[N],u,v,ret[N];
vector<int> e[N],e2[N];
bitset<10100> adj[10100];
set<state> hs;
pair<int,int> E[N];

void del(int u) {
	off+=1;
	dis[u]=1;
	hs.erase(st1[u]);
	for (auto v:e[u]) if (!dis[v]) {
		hs.erase(st1[v]);
		st1[v].fi++;
		hs.insert(st1[v]);
	}
}

bool gao0() {
	rep(i,1,n+1) pre[i]=i;
	random_shuffle(pre+1,pre+n+1);
	rep(i,1,n) if (adj[pre[E[i].fi]][pre[E[i].se]]) return 0;
	rep(i,1,n+1) ret[pre[i]]=i;
	puts("Yes");
	rep(i,1,n+1) printf("%d ",ret[i]+n);
	puts("");
	return 1;
}
bool gao() {
	hs.clear(); off=0;
	rep(i,1,n+1) {
		st1[i]=mp(deg[i],mp(myrand(),i));
		st2[i]=mp(deg2[i],mp(myrand(),i));
		hs.insert(st1[i]);
		vis[i]=0; dis[i]=0;
	}

	rep(i,1,n+1) pre[i]=0;


	state val=st2[1];
	rep(i,2,n+1) val=min(val,st2[i]);

	priority_queue<state, vector<state>, greater<state> > q;
	
	q.push(val);
	pre[val.se.se]=hs.begin()->se.se;
	vis[val.se.se]=1;

	del(hs.begin()->se.se);
	while (!q.empty()) {
		state st=q.top(); q.pop();
		int u=st.se.se;
		int w=pre[u];
		for (auto v:e2[u]) if (!vis[v]) {
			st2[v].fi--; vis[v]=1;
			vector<state> tmp;
			while (1) {
				auto it=hs.lower_bound(mp(st2[v].fi+off,mp(-1,-1)));
				if (it==hs.end()) return 0;
				if (adj[w][it->se.se]) {
					tmp.push_back(*it);
					hs.erase(it);
				} else {
					pre[v]=it->se.se;
					for (auto p:tmp) hs.insert(p);
					del(it->se.se);
					q.push(st2[v]);
					break;
				}
			}
		}

	}
	rep(i,1,n+1) ret[pre[i]]=i;
	puts("Yes");
	rep(i,1,n+1) printf("%d ",ret[i]+n);
	puts("");
	return 1;
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) deg[i]=n-1;
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].push_back(v),e[v].push_back(u);
		adj[u][v]=adj[v][u]=1;
		deg[u]--; deg[v]--;
	}
	rep(i,1,n) {
		scanf("%d%d",&u,&v); u-=n; v-=n;
		e2[u].push_back(v); e2[v].push_back(u);
		E[i]=make_pair(u,v);
		deg2[u]++; deg2[v]++;
	}
	rep(i,1,n+1) if (deg[i]==0||deg2[i]==n-1) {
		puts("No");
		return 0;
	}
	while (1) {
		if (gao()) return 0;
		if (gao0()) return 0;
	}
	puts("No");
}