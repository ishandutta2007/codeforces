#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 2e5 + 10;
typedef double db;

struct Seg {
	bool o[N << 2];
	void Mdf(int x, int l, int r, int s, int v) {
		if (l == r) return o[x] = v, void();
		int mid = (l + r) >> 1;
		if (s <= mid) Mdf(x << 1, l, mid, s, v);
		else if (s > mid) Mdf(x << 1 | 1, mid + 1, r, s, v);
		o[x] = o[x << 1] & o[x << 1 | 1];
	}
	int Qry(int x, int l, int r, int tl, int tr) {
		if (tl > tr || tr < l || tl > r) return 1;
		if (tl <= l && r <= tr) return o[x];
		int mid = (l + r) >> 1;
		if (tr <= mid) return Qry(x << 1, l, mid, tl, tr);
		if (tl > mid) return Qry(x << 1 | 1, mid + 1, r, tl, tr);
		return Qry(x << 1, l, mid, tl, tr) & Qry(x << 1 | 1, mid + 1, r, tl, tr);
	}
}	s1, s2, s3;

int n, m, a[N], k[N], mr[N];
vector <int> b[N];
ll sum[N];
db av[N];

void solve() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= m; i++) {
		read(k[i]); b[i].clear(); sum[i] = 0;
		for (int j = 0, x; j < k[i]; j++)
			read(x), b[i].push_back(x), sum[i] += x;
		av[i] = sum[i] * 1.0 / k[i];
	}
	sort (a + 1, a + n + 1);
	sort (av + 1, av + m + 1);
	/*
	cout << "A" << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;

	cout << "Av" << endl;
	for (int i = 1; i <= m; i++)
		cout << av[i] << " ";
	cout << endl;
	*/
	for (int i = 1; i <= m; i++) {
		mr[i] = n - (lower_bound(a + 1, a + n + 1, av[i]) - a) + 1;
		s1.Mdf(1, 1, m, i, mr[i] >= m - i + 1);
		s2.Mdf(1, 1, m, i, mr[i] >= m - (i + 1) + 1);
		s3.Mdf(1, 1, m, i, mr[i] >= m - (i - 1) + 1);
	}
	/*
	cout << "Mr" << endl;
	for (int i = 1; i <= m; i++)
		cout << mr[i] << " ";
	cout << endl;

	cout << "S" << endl;
	for (int i = 1; i <= m; i++)
		cout << s1.Qry(1, 1, m, i, i) << " ";
	cout << endl;
	for (int i = 1; i <= m; i++)
		cout << s2.Qry(1, 1, m, i, i) << " ";
	cout << endl;
	for (int i = 1; i <= m; i++)
		cout << s3.Qry(1, 1, m, i, i) << " ";
	cout << endl;
	*/
	vector <int> ans;
	for (int i = 1; i <= m; i++) {
		int rk = lower_bound(av + 1, av + m + 1, sum[i] * 1.0 / k[i]) - av;
		for (int j = 0; j < k[i]; j++) {
			db nval = (sum[i] - b[i][j]) * 1.0 / (k[i] - 1);
			//cout << k[i] - 1 << " " << b[i][j] << endl;
			int nrk = lower_bound(av + 1, av + m + 1, nval) - av;
			int nmr = n - (lower_bound(a + 1, a + n + 1, nval) - a) + 1;
			int flag = -1, go = nrk;
			if (go > rk) go--;
			//cout << rk << " " << nval << " " << nrk << " " << nmr << " " << go << endl;
			if (nmr < (m - go + 1)) flag = 0;
			else {
				if (go == rk) flag = s1.Qry(1, 1, m, 1, go - 1) & s1.Qry(1, 1, m, go + 1, m);
				else if (go < rk) flag = s1.Qry(1, 1, m, 1, go - 1) & s2.Qry(1, 1, m, go, rk - 1) & s1.Qry(1, 1, m, rk + 1, m);
				else flag = s1.Qry(1, 1, m, 1, rk - 1) & s3.Qry(1, 1, m, rk + 1, go) & s1.Qry(1, 1, m, go + 1, m);
			}
			ans.push_back(flag);
		}
	}
	for (int i : ans) print(i); puts("");
}

int T;

int main() {
	for (read(T); T; T--) solve();
	return 0;
}