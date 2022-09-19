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
const int MN = 1e5 + 44;
int l[MN], r[MN], v[MN];
map <int, int> V;
int values[MN], amount[MN];
int calc(int x, int low, int high) {
	if (x == -1) {
		int r = 0;
		for (int i = low; i <= high; ++i)
			r += amount[i];
		return r;
	}
	if (low > high)
		return 0;
	int V = v[x];
	for (int i = low, k = high; ; i++, k--) {
		if (values[i] > V)
			return calc(l[x], low, i - 1) + calc(r[x], i, high);
		else if (values[i] == V)
			return calc(l[x], low, i - 1) + calc(r[x], i + 1, high);
		else if (values[k] < V)
			return calc(l[x], low, k) + calc(r[x], k + 1, high);
		else if (values[k] == V)
			return calc(l[x], low, k - 1) + calc(r[x], k + 1, high);
	}
}
bool non_root[MN];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", v + i, l + i, r + i);
		V[v[i]]++;
		non_root[l[i]] = non_root[r[i]] = true;
	}
	int cou = 0;
	for (auto x : V) {
		values[cou] = x.f;
		amount[cou] = x.s;
		cou++;
	}
	for (int i = 1; i <= n; ++i)
		if (!non_root[i])
			printf("%d\n", calc(i, 0, cou - 1));
}