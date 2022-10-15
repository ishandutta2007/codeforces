#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n;

#ifndef ONLINE_JUDGE
ll x[kN], y[kN];
void Input() {
	for(int i = 1; i <= n; ++i)
		rd(x[i], y[i]);
}
ll Abs(ll a) { return a < 0 ? -a : a; }
ll Query(int t, int i, int j, int k) {
	//printf("%d %d %d %d\n", t, i, j, k);
	ll ret = (x[i] - x[j]) * (y[i] - y[k]) - (y[i] - y[j]) * (x[i] - x[k]);
	//printf("%lld\n", ret);
	return t == 1 ? Abs(ret) : (ret < 0 ? -1 : 1);
}
#endif

#ifdef ONLINE_JUDGE
ll Query(int t, int i, int j, int k) {
	ll ret;
	printf("%d %d %d %d\n", t, i, j, k);
	fflush(stdout);
	rd(ret);
	return ret;
}
#endif

int s1[kN], s2[kN], s[kN], idx[kN];
ll A[kN];

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);// Input();
#ifndef ONLINE_JUDGE
	Input();
#endif
		int p1 = 2, p2 = 1;
		idx[1] = 1; idx[2] = 2;
		for(int i = 3; i <= n; ++i) {
			A[i] = Query(1, 1, 2, i);
			s1[i] = Query(2, 1, 2, i);
			if(s1[i] == 1 && A[i] > A[p1]) p1 = i;
			if(s1[i] == -1 && A[i] > A[p2]) p2 = i;
			idx[i] = i;
		}
		for(int i = 3; i <= n; ++i) {
			if(p1 == i || p2 == i) continue;
			s2[i] = Query(2, p2, p1, i);
			if(s1[i] == -1 && s2[i] == 1) s[i] = 1;
			else if(s1[i] == -1 && s2[i] == -1) s[i] = 2;
			else if(s1[i] == 1 && s2[i] == -1) s[i] = 3;
			else s[i] = 4;
		}
		s[1] = 1; s[2] = 3;
		s[p2] = 1; s[p1] = 3;
		A[p1] = A[p2] = kInfLL;
		//printf("%d %d\n", s1[4], s2[4]);
		std::sort(idx + 1, idx + n + 1, [&](const int &x, const int &y) {
			return s[x] != s[y] ? s[x] < s[y] : (s[x] % 2 == 0 ? A[x] > A[y] : A[x] < A[y]);
		});
	/*	printf("%d %d\n", p1, p2);
		for(int i = 1; i <= n; ++i) printf("%d ", s1[i]);
		printf("\n");
		for(int i = 1; i <= n; ++i)
			printf("%lld %d\n", A[i], s[i]);*/
		printf("0 ");
		/*for(int i = 1; i <= n; ++i)
			printf("%d ", s1[i]);
		printf("\n");
		printf("1 ");*/
		for(int i = 1; i <= n; ++i) {
			printf("%d ", idx[i]);
		}
		printf("\n");
	} return 0;
}