#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, m, a, b, p[N], sz[N], A[N], B[N];
int pp(int v){
	if(p[v] == v)
		return v;
	return p[v] = pp(p[v]);
}
int main()
{
	int q;
	scanf("%d", &q);
	while(q--){
		scanf("%d%d%d%d", &n, &m, &a, &b);
		for(int i = 1; i <= n; i++)
			p[i] = i, sz[i] = 1, A[i] = 0, B[i] = 0;
		vector< pii > e;
		for(int i = 0; i < m; i++){
			int v, u;
			scanf("%d%d", &v, &u);
			if(v == a || v == b || u == a || u == b){
				e.pb({v, u});
			}else{
				v = pp(v);
				u = pp(u);
				if(v != u)
					p[v] = u, sz[u] += sz[v];				
			}
		}
		set< pii > st;
		for(int i = 0; i < e.size(); i++){
			int v = pp(e[i].f);
			int u = pp(e[i].s);
			if(v < u)
				swap(v, u);
			if(st.find({v, u}) != st.end())
				continue;
			st.insert({v, u});
			if(v != a && v != b){
				if(u == a)
					A[v] = 1;		     
				if(u == b)
					B[v] = 1;		     
			}
			if(u != a && u != b){
				if(v == a)
					A[u] = 1;		     
				if(v == b)
					B[u] = 1;		     
			}
		}
		ll AA = 0, BB = 0;
		for(int i = 1; i <= n; i++){
			if(pp(i) == i){
				if(A[i] && !B[i])
					AA += sz[i];						
				if(!A[i] && B[i])
					BB += sz[i];						
			}
		}
		printf("%lld\n", AA * BB);
	}
	return 0;
}