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

int n, a[N], p[N], ct, Max;
ll ans[N];

struct ST {
	ll s[300010]; int n;
	void Mdf(int x, int v) {
		for (; x <= n; x += x & (-x)) s[x] += v;
	}
	ll Qry(int x) {
		ll ret = 0;
		for (; x; x -= x & (-x))
			ret += s[x];
		return ret;
	}
}	s[3];

struct Q {
	int op, x, y; ll z;
}	q[10000000];

inline int operator < (Q A, Q B) {
	if (A.x == B.x) {
		if (A.y == B.y) return A.op > B.op;
		return A.y < B.y;
	}
	return A.x < B.x;
}

inline int cmp(int x, int y) {
	return a[p[x]] < a[p[y]];
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]), p[i] = i;
		Max = max(Max, a[i]);
	}
	s[0].n = n, s[1].n = Max, s[2].n = Max;
	sort (p + 1, p + n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = a[p[i]]; j <= Max; j += a[p[i]])
			q[++ct] = (Q){1, j, p[i], a[p[i]]};
	for (int i = 1; i <= n; i++)
		q[++ct] = (Q){2, a[p[i]], p[i], 0};
	sort (q + 1, q + ct + 1);
	for (int i = 1; i <= ct; i++) {
		int op = q[i].op, x = q[i].x, y = q[i].y;
		ll z = q[i].z;
		//cout << op << " " << x << " " << y << " " << z << endl;
		if (op == 1) s[0].Mdf(y, z);
		else ans[y] -= s[0].Qry(y);
	}
	//for (int i = 1; i <= n; i++)
	//	cout << ans[i] << " ";
	//cout << endl;
	for (int i = 1; i <= n; i++) {
		ans[i] += 1ll * s[1].Qry(a[i]) * a[i];
		ans[i] += s[2].Qry(a[i]);
		//cout << s[1].Qry(Max) - s[1].Qry(a[i]) <<endl;
		ans[i] += 1ll * (s[1].Qry(Max) - s[1].Qry(a[i])) * a[i];
		//cout << s[2].Qry(Max) - s[2].Qry(a[i]) << endl;
		ans[i] += s[2].Qry(Max) - s[2].Qry(a[i]);
		for (int j = a[i]; j <= Max; j += a[i])
			ans[i] -= 1ll * a[i] * (s[1].Qry(Max) - s[1].Qry(j - 1));
		s[1].Mdf(a[i], 1);
		s[2].Mdf(a[i], a[i]);
	}
	//for (int i = 1; i <= n; i++)
	//	cout << ans[i] << " ";
	//cout << endl;
	for (int i = 1; i <= n; i++)
		ans[i] += ans[i - 1];
	for (int i = 1; i <= n; i++)
		print(ans[i], " \n"[i == n]);
	return 0;
}