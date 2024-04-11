#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define PLL pair <LL, LL>
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define debug2(...) cerr << __VA_ARGS__
#else
#define debug(...)
#define debug2(...)
#endif
const int MN = 3e5 + 44, A = 26;
vector <pair <int, char> > graf[MN];
typedef unsigned LL hash_t;
const hash_t empty = 0;
hash_t keys[MN][A];
hash_t key(int i, char x) {
	int a = x - 'a';
	while (!keys[i][a]) {
		keys[i][a] = (hash_t)rand() | ((hash_t)rand() << 16) | ((hash_t)rand() << 32) | ((hash_t)rand() << 48);
	}
	return keys[i][a];
}
hash_t hash_up[MN];
int diff[MN];
set <hash_t> under[MN];
int size[MN];
int level[MN];
int ans[MN];
pair <int, int> dfs1(int x, int y = -1, int d = 0, hash_t up_hash = 0) {
	level[d]++;
	int dunder = 1, s = 1;
	for (auto v : graf[x])
		if (v.first != y) {
			pair <int, int> u = dfs1(v.first, x, d + 1, up_hash ^ key(d, v.second));
			maxi(dunder, u.first);
			s += u.second;
		}
	hash_up[x] = up_hash;
	size[x] = s;
	return make_pair(dunder + 1, s);
}
void dfs2(int x, int y = -1, int d = 0) {
	int M = 0, wh = 0;
	char letter;
	for (auto v : graf[x]) {
		if (v.first != y) {
			dfs2(v.first, x, d + 1);
			if (size[v.first] > M) {
				M = size[v.first];
				wh = v.first;
				letter = v.second;
			}
		}
	}
	if (M > 0) {
		swap(under[x], under[wh]);
		set <hash_t> other;
		for (auto v : graf[x])
			if (v.first != y && v.first != wh) {
				for (auto h : under[v.first]) {
					other.insert(h ^ key(d, v.second) ^ key(d, letter));
				}
			}
		ans[d + 1] += under[x].size() - 1;
		for (auto o : other) {
			if (under[x].find(o) == under[x].end()) {
				ans[d + 1]++;
			}
		}
		for (auto v : graf[x]) {
			if (v.first != y && v.first != wh) {
				for (auto h : under[v.first])
					under[x].insert(h);
			}
		}
	}
	under[x].insert(hash_up[x]);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		char c[2];
		scanf("%d%d%1s", &a, &b, c);
		graf[a].emplace_back(b, c[0]);
		graf[b].emplace_back(a, c[0]);
	}
	dfs1(1);
	for (int i = 1; i < n; ++i)
		ans[i] = ans[i - 1] + level[i - 1];
	dfs2(1);
	int opt = n, count = 0;
	for (int i = 1; i < n; ++i) {
		if (opt > ans[i]) {
			opt = ans[i];
			count = i;
		}
	}
	printf("%d\n%d\n", opt, count);
}