#include <bits/stdc++.h>

template <typename T> inline void Read(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void Read(T& x, Args&... args) { Read(x); Read(args...); }
template <typename T> inline void Write(T x) { if(x / 10) Write(x / 10); putchar(x % 10 + 48); }
template <typename T, typename... Args> inline void Write(T x, Args... args) {
	Write(x); putchar(' '); Write(args...);
}
template<typename T> inline T Abs(T x) { return x > 0 ? x : -x; }

typedef long long ll;

const int kN = 60;

ll v[kN]; int sn[kN];

int main() {
	int t;
	Read(t);
	while(t--) {
		memset(sn, 0, sizeof(sn));
		bool flag = true;
		int n, m = 0; ll maxs = 1; ll x, k; Read(n, k);
		for(int i = 1; i <= n; ++i) Read(v[i]);
		for(; maxs <= 1e16; maxs *= k, ++m);
		for(int i = 1; i <= n; ++i)
			for(ll j = m, tmp = maxs; ~j; --j, tmp /= k)
				if(v[i] >= tmp && sn[j] < 1) v[i] -= tmp, ++sn[j];
		for(int i = 1; i <= n; ++i)
			if(v[i] != 0) flag = false;
		printf(flag ? "YES\n" : "NO\n");
	}
	return 0;
}