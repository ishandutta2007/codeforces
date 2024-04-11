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
#else
#define debug(...)
#define cerr if(0) cerr
#endif
const int LAYERS = 27;
struct node {
	node *l, *r;
	int cou;
	node() : l(nullptr), r(nullptr), cou(0) {}
};
node * root = new node();
void add(int val, node * r = root, int layer = LAYERS - 1) {
	r -> cou++;
	if (layer == -1)
		return;
	if (val & (1 << layer)) {
		if (!r -> r)
			r -> r = new node();
		add(val, r -> r, layer - 1);
	}
	else {
		if (!r -> l)
			r -> l = new node();
		add(val, r -> l, layer - 1);
	}
}
void rem(int val, node * r = root, int layer = LAYERS - 1) {
	r -> cou--;
	if (layer == -1)
		return;
	if (val & (1 << layer))
		rem(val, r -> r, layer - 1);
	else
		rem(val, r -> l, layer - 1);
}
int n_cou(node * r) {
	return r ? r -> cou : 0;
}
int ans(int mask, int bound, node * r = root, int layer = LAYERS - 1) {
	if (!r)
		return 0;
	if (layer == -1)
		return r -> cou;
	node *lower = r -> l, *higher = r -> r;
	if (mask & (1 << layer))
		swap(lower, higher);
	if (bound & (1 << layer))
		return n_cou(lower) + ans(mask, bound, higher, layer - 1);
	else
		return ans(mask, bound, lower, layer - 1);
}
int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x;
			scanf("%d", &x);
			add(x);
		}
		else if (t == 2) {
			int x;
			scanf("%d", &x);
			rem(x);
		}
		else {
			int m, b;
			scanf("%d%d", &m, &b);
			printf("%d\n", ans(m, b - 1));
		}
	}
}