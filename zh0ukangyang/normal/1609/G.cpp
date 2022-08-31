#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
#define uint unsigned int 
using namespace std;
const int N = 1 << 20;
int n, m, q;
struct segt { 
	ll a[N], b[N];
	inline void ad (int p, ll w) {
		ll cw = w * p;
		for (int x = p; x <= m; x += x & -x) a[x] += w, b[x] += cw;
	}
	void add (int l, int r, ll w) {
		ad (r + 1, -w), ad (l, w);
	}
	inline ll Pre (int p) {
		ll ret = 0;
		for (int x = p; x; x -= x & -x) ret += (p + 1) * a[x] - b[x];
		return ret;
	}
	ll query (int l, int r) {
		return Pre (r) - Pre (l - 1);
	}
	void clear () {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}
} A;
ll a[N], b[N], prb[N], sum;
ll tag[N], mn[N];
int pos[N];
void add (int x, int L, int R, int l, int r, ll w) {
	if (l <= L && R <= r) return mn[x] += w, tag[x] += w, void ();
	int mid = (L + R) >> 1;
	if(l <= mid) add (x << 1, L, mid, l, r, w);
	if(r > mid) add (x << 1 | 1, mid + 1, R, l, r, w);
	mn[x] = min(mn[x << 1], mn[x << 1 | 1]) + tag[x]; 
}
int query (int x, int L, int R, ll w) {
	if(L == R) return L;
	w -= tag[x];
	int mid = (L + R) >> 1;
	if(mn[x << 1 | 1] < w) return query (x << 1 | 1, mid + 1, R, w);
	else return query (x << 1, L, mid, w);
}
int main() { 
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> n >> m >> q;
	L(i, 1, n) cin >> a[i];
	L(i, 1, m) cin >> b[i];
	R(i, n, 1) a[i] -= a[i - 1];
	R(i, m, 1) b[i] -= b[i - 1];
	L(i, 2, m) sum += b[i] * (m - i + 1), A.add(i, i, b[i]), add (1, 1, m, i, i, b[i]); 
	while (q--) {
		int ty, k, d;
		cin >> ty >> k >> d;
		if(ty == 1) L(i, n - k + 1, n) a[i] += d;
		else {
			add (1, 1, m, m - k + 1, m, d);
			if (m == k) 
				b[1] += d;
			A.add(m - k + 1, m, d);
			int r = min(m - 1, k);
			sum += (ll) r * (r + 1) / 2 * d;
		}
		ll ns = (ll) (a[1] + b[1]) * (n + m - 1);
		pos[1] = 1;
		L(i, 2, n) {
			pos[i] = query (1, 1, m, a[i]);
			ns += (ll) (n - i + m - pos[i] + 1) * a[i];
		}
		L(i, 2, n) ns += (ll) (n - i + 1) * A.query(pos[i - 1] + 1, pos[i]); 
		ns += sum;
		cout << ns << '\n';
	}
	return 0;
}