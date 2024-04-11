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
#define V std::vector
#define H std::priority_queue
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int n, q, a[kN], s[kN];
std::multiset <int> st;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]), ++s[a[i]];
		for(int i = 1; i <= 1e5 + 5; ++i)
			if(s[i]) st.insert(s[i]);
		rd(q);
		while(q--) {
			char str[10];
			scanf("%s", str + 1);
			int w; rd(w);
			if(str[1] == '+') {
				std::multiset <int>::iterator it = st.find(s[w]);
				if(it != st.end()) st.erase(it);
				st.insert(++s[w]);
			} else {
				std::multiset <int>::iterator it = st.find(s[w]);
				if(it != st.end()) st.erase(it);
				st.insert(--s[w]);
			}
			std::multiset <int>::reverse_iterator it = st.rbegin();
			int x = 0, y = 0, z = 0;
			if(it != st.rend()) {
				x = *it;
				if((++it) != st.rend()) {
					y = *it;
					if((++it) != st.rend()) z = *it;
				}
			}
			if((x >= 8) || (x >= 6 && y >= 2) || (x >= 4 && y >= 2 && z >= 2) || (x >= 4 && y >= 4))
				printf("YES\n");
			else printf("NO\n");
		}
	} return 0;
}