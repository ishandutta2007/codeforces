#include <bits/stdc++.h>
            
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, inf = (1<<30) + 123, LOG = 20;
const ll INF = 1e18;

unordered_map<int, int> sz, p, depth;
unordered_map<int, bool> was;
inline int getp(int v){
	if(p[v] == v)
		return v;
	int u = getp(p[v]);
	depth[v] ^= depth[p[v]];
	p[v] = u;
	return p[v];
}

inline void check(int v){
	if(was[v])
		return;
	p[v] = v;
	sz[v] = 1;
	depth[v] = 0;
	was[v] = 1;
}
inline void addE(int v, int u, int x){
	check(v);
	check(u);
	int pv = getp(v);
	int pu = getp(u);
	
	x ^= depth[v];
    v = pv;
	
	x ^= depth[u];
    u = pu;
	if(v == u)
		return;
	if(sz[v] < sz[u])
		swap(v, u);
	sz[v] += sz[u];
	p[u] = v;
	depth[u] = x;
}

inline int get(int l, int r){
	check(l);
	check(r + 1);
	if(getp(l) == getp(r + 1))
		return depth[l] ^ depth[r + 1];
	else
		return -1;
}

int main(){
	int q;
	int last = 0;
	scanf("%d", &q);
	
	sz.reserve(N);
	p.reserve(N);
	depth.reserve(N);
	
	while(q--){
		int t, l, r, x;
		scanf("%d%d%d", &t, &l, &r);
		l ^= last;
		r ^= last;
		if(l > r)
			swap(l, r);
		if(t == 1){
			scanf("%d", &x);
			x ^= last;
        	if(get(l, r) != -1)
        		continue;
			addE(l, r + 1, x);
		}else{
			last = get(l, r);
			printf("%d \n", last);
			if(last == -1)
				last = 1;
		}
	}
	return 0;
}