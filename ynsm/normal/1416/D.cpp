#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)5e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, m, q, k, a[N], b[N], type[N], val[N], ans[N], lim[N];
int p[N], sz[N];
set < pii > st[N];
bool skip[N], del[N], used[N];
pii t[N];
vector< int > vec[N];

int get(int v){
	if(p[v] == v)
		return v;
	return get(p[v]);
}
void Merge(int i){
	//cerr << i << " " ;
	if(used[i]){
	//	cerr << "- " << a[i] << " " << b[i] << " ";       
		if(skip[i]){
	//		cerr << "skip";
			skip[i] = 0;
		}else{
			k--;
			int v = t[k].f;
			int u = t[k].s;
			for(auto it : st[u])
				st[v].erase(it);
			sz[v] -= sz[u];
			p[u] = u;
		}	
	}else{
	//	cerr << "+ " << a[i] << " " << b[i] << " ";       
		int v = get(a[i]);
		int u = get(b[i]);
		if(v == u){
	//		cerr << "skip";
			skip[i] = 1;
		}else{
			if(sz[v] < sz[u])
				swap(v, u);
			for(auto it : st[u])
				if(!del[it.s])
					st[v].insert(it);
			sz[v] += sz[u];
			p[u] = v;
			t[k++] = {v, u};
		}
	}
	//cerr << endl;
	used[i] ^= 1;
} 
void fix(int v){
	while(!st[v].empty()){
		int i = st[v].begin() -> s;
		if(del[i])
			st[v].erase(st[v].begin());
		else
			break;
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for(int i = 1; i <= m; i++)
		scanf("%d%d", &a[i], &b[i]);
	for(int i = 1; i <= q; i++)
		scanf("%d%d", &type[i], &val[i]);
	for(int i = 1; i <= m; i++)
		lim[i] = q + 1;
	for(int i = 1; i <= q; i++)
		if(type[i] == 2)
			lim[val[i]] = i;
	for(int i = 1; i <= m; i++)
		vec[lim[i]].pb(i);
	for(int i = 1; i <= n; i++){
		st[i].insert({n - p[i], i});
		p[i] = i, sz[i] = 1;
	}
	for(int i = q + 1; i >= 1; i--)
		for(auto j : vec[i])
			Merge(j);
	for(int i = 1; i <= q; i++){
	    reverse(vec[i].begin(), vec[i].end());
		for(auto j : vec[i])
			Merge(j);
		if(type[i] != 1)
			continue;
		int v = val[i];
		v = get(v);
		fix(v);
		if(st[v].empty()){
			ans[i] = 0;
			printf("0\n");
		}else{
			ans[i] = st[v].begin() -> f;
			printf("%d\n", n - ans[i]);
			del[st[v].begin() -> s] = 1;
		}
	}
}