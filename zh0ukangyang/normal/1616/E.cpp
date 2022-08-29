#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
const ll inf = 1e18;
template < int N > struct fenwt {
	using F = long long ;
	int n;
	F a[N + 1];
	void add (int x, F w) {
		for (; x <= n; x += x & -x) a[x] += w;
	}
	F query (int x) {
		F ret = 0;
		for (; x; x -= x & -x) ret += a[x];
		return ret;
	}
	F get (int l, int r) {
		if(l > r) return 0;
		return query (r) - query (l - 1);
	}
	void clear () {
		L(i, 0, n) a[i] = 0;
	}
} ;
fenwt < N > S;
char s[N], t[N];
int n;
vi vc[26];
void Main () {
	cin >> n >> (s + 1) >> (t + 1);
	S.n = n;
	L(i, 1, n) S.add (i, 1);
	R(i, n, 1) vc[s[i] - 'a'].push_back(i);
	ll ns = inf, ret = 0;
	L(i, 1, n) {
		int r = t[i] - 'a';
		L(p, 0, r - 1) if(sz(vc[p])) 
//			cout << "eq : " << vc[p].back() << ' ' << S.query(vc[p].back()) << '\n', 
			ns = min(ns, ret + S.query(vc[p].back()) - 1);
		if(!sz(vc[r])) break;
		int nb = vc[r].back();
		vc[r].pop_back();
		S.add (nb, -1);
//		cout << "del " << nb << '\n';
		ret += S.query (nb);
	}
	if(ns == inf) cout << -1 << '\n';
	else cout << ns << '\n';
	S.clear ();
	L(i, 0, 25) vc[i].clear ();
//	ll l = 0, r = (ll) n * n, ns = -1;
//	while (l <= r) {
//		ll mid = (l + r) >> 1;
//		if(check(mid)) ns = mid, r = mid - 1;
//		else l = mid + 1;
//	}
//	cout << ns << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}