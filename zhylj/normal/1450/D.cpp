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
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, a[kN], b[kN], cnt[kN]; std::deque <int> que;
bool Check(int mid) {
	que.clear();
	for(int i = 1; i <= mid; ++i) {
		while(que.size() && a[que.back()] > a[i]) que.pop_back();
		que.push_back(i);
	}
	for(int i = 1; i <= n - mid + 1; ++i) {
		while(que.size() && que.front() < i) que.pop_front();
		b[i] = a[que.front()];
		while(que.size() && a[que.back()] > a[i + mid]) que.pop_back();
		que.push_back(i + mid);
	}
	for(int i = 1; i <= n - mid + 1; ++i) cnt[i] = 0;
	for(int i = 1; i <= n - mid + 1; ++i) ++cnt[b[i]];
	for(int i = 1; i <= n - mid + 1; ++i) if(cnt[i] != 1) return false;
	return true;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		int L = 2, R = n + 1;
		while(L < R) {
			int mid = (L + R) >> 1;
			if(Check(mid)) R = mid;
			else L = mid + 1;
		}
		printf("%d", (int)Check(1));
		for(int i = 2; i <= n; ++i) printf("%d", (int)i >= L);
		printf("\n");
	} return 0;
}