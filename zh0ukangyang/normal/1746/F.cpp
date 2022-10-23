#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 6e5 + 7, T = 50;
int n, q, f[N], arr[N], atot;
mt19937_64 orz(time(0) ^ (*new char));
struct nop {
	bool vis[N];
	int a[N + 1];
	void add (int x, int w) {
		for (; x <= N; x += x & -x) a[x] += w;
	}
	int query (int x) {
		int ret = 0;
		for (; x; x -= x & -x) ret += a[x];
		return ret;
	}
	int get (int l, int r) {
		if(l > r) return 0;
		return query (r) - query (l - 1);
	}
	void change(int p, int x, int y) {
		int o = (int) vis[y] - (int) vis[x];
		if(o) add(p, o);
	}
	void init() {
		L(i, 1, N - 7) vis[i] = orz() & 1;
		L(i, 1, n) {
			if(vis[f[i]]) {
				add(i, 1);
			}
		}
	} 
} t[T + 1];
map < int, int > mp;
int tot;
inline int getid(int x) {
	if(mp.count(x)) return mp[x];
	return mp[x] = ++tot;
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	L(i, 1, n) cin >> f[i], f[i] = getid(f[i]);
	L(i, 1, T) t[i].init();
	while(q--) {
		int op, x, y, k;
		cin >> op;
		if(op == 1) {
			cin >> x >> y, y = getid(y);
			L(i, 1, T) t[i].change(x, f[x], y);
			f[x] = y;
		} else {
			cin >> x >> y >> k;
			bool ok = true;
			L(i, 1, T) {
//				cout << "gt = " << t[i].get(x, y) << endl;
				if(t[i].get(x, y) % k) {
					ok = false;
					break ;
				} 
			}
			if(ok) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	} 
	return 0;
}