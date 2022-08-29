#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e5 + 7, M = 5e5 + 7, S = 1000;
int n, m, tp, arr[M], atot; 

vi vc[M];
bitset < N > bs[1000], cur, all;

struct node {
	int w;
	int f[6];
} h[N];

int col[N][6], rc[M]; 

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) {
		L(j, 1, m) cin >> h[i].f[j], arr[++atot] = h[i].f[j];
		cin >> h[i].w;
	}
	sort(h + 1, h + n + 1, [&] (node a, node b) {
		return a.w < b.w;
	});
	sort(arr + 1, arr + atot + 1);
	L(i, 1, n) L(j, 1, m) 
		h[i].f[j] = lower_bound(arr + 1, arr + atot + 1, h[i].f[j]) - arr, 
		vc[h[i].f[j]].emplace_back(i);
	L(i, 1, atot) {
		if(sz(vc[i]) > S) {
			++tp;
			rc[i] = tp;
			for(const int &u : vc[i]) 
				bs[tp].set(u);
		}
	}
	
	L(i, 1, n) all.set(i);
	
	int ns = 2e9 + 7;
	L(i, 1, n) {
		cur.reset();
		L(j, 1, m) {
			int c = h[i].f[j];
			if(sz(vc[c]) <= S) {
				for(const int &u : vc[c]) 
					cur[u] = true; 
			} else cur |= bs[rc[c]];
		}
		all.reset(i);
		cur &= all, cur ^= all;
		int u = cur._Find_first();
		if(u <= n) {
			ns = min(ns, h[i].w + h[u].w);
		}
	}
	if(ns > 2e9) {
		cout << -1 << '\n';
	} else {
		cout << ns << '\n';
	}
	return 0;
}