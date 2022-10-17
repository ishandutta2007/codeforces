#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
typedef long long ll;
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void read(T &x) {
	x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
}
#define rint register int
#define fu(i, a, b) for(rint i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rint i = a, I = (b) - 1; i > I; --i)

int n, a[N], mu[N], cnt[N];
vector<int> d[N];
stack<int> stk;
bool b[N];

inline void prework(int A) {
	mu[1] = 1;
	fu(i, 1, A) for(rint j = i << 1; j <= A; j += i) mu[j] -= mu[i];
	fu(i, 1, A) for(rint j = i; j <= A; j += i) d[j].push_back(i);
} 

inline int cal(int x) {
	int ret = 0;
	fu(i, 0, d[x].size() - 1) {
		int fac = d[x][i];
		ret += mu[fac] * cnt[fac];
	}
	return ret; 
}

inline void update(int x, int v) {
	fu(i, 0, d[x].size() - 1) {
		int fac = d[x][i];
		cnt[fac] += v;
	} 
} 

int main() {
	read(n); ll ans = 0; 
	fu(i, 1, n) {
		read(a[i]);
		b[a[i]] = 1;
		ckmax(ans, 1LL * a[i]);
	}
	int A = *max_element(a + 1, a + n + 1);	prework(A);
	fu(g, 1, A) {
		fd(v, A / g, 1) {
			if(!b[v * g]) continue;
			while(!stk.empty()) {
				int lst = cal(v);
				if(!lst) break;
				int y = stk.top();
				stk.pop(), update(y, -1);
				int tot = cal(v);
				if(!tot) ckmax(ans, 1LL * v * y * g);
			}
			stk.push(v); update(v, 1);
		}
		while(!stk.empty()) update(stk.top(), -1), stk.pop();
	} 
	printf("%lld", ans); return 0;
}