#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

int n, sa[N], ea[N], sb[N], eb[N];

struct node {
	int id, t, opt;
	inline friend bool operator < (const node &n1, const node &n2) {
		if(n1.t == n2.t) return n1.opt < n2.opt;
		return n1.t < n2.t;
	}
} event[N << 1];

inline bool check(int sa[], int ea[], int sb[], int eb[]) {
	int cnt = 0; multiset <int> S, E;
	fu(i, 1, n) event[++cnt] = (node) {i, sa[i], 0}, event[++cnt] = (node) {i, ea[i], 1};
	sort(event + 1, event + cnt + 1);
	fu(i, 1, cnt) {
		int id = event[i].id; 
		if(event[i].opt) S.erase(sb[id]), E.erase(eb[id]);
		else {
			if((!E.empty() && *E.begin() < sb[id]) || (!S.empty() && *S.rbegin() > eb[id])) return 0;
			S.insert(sb[id]), E.insert(eb[id]);
		}
	}
	return 1;
}

int main() {
	rd(n);
	fu(i, 1, n) rd(sa[i]), rd(ea[i]), rd(sb[i]), rd(eb[i]);
	if(check(sa, ea, sb, eb) && check(sb, eb, sa, ea)) puts("YES");
	else puts("NO");
	return 0;
}