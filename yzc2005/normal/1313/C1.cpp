#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fail puts("NO"), exit(0)
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
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

const int N = 5e5 + 5;
int n, a[N], sta[N], tp, ansp, c[N], d[N], lstp[N], lsts[N];
ll pre[N], suf[N], ans;

int main() {
	rd(n);
	fu(i, 1, n) rd(a[i]);
	fu(i, 1, n) {
		while(tp && a[sta[tp]] > a[i]) --tp;
		int pos = sta[tp];
		pre[i] = pre[pos] + 1LL * (i - pos) * a[i];
		lstp[i] = pos;
		sta[++tp] = i;
	}
	reverse(a + 1, a + n + 1);
	tp = 0;
	fu(i, 1, n) {
		while(tp && a[sta[tp]] >= a[i]) --tp;
		int pos = sta[tp];
		suf[i] = suf[pos] + 1LL * (i - pos) * a[i];
		lsts[i] = pos;
		sta[++tp] = i;
	}
	reverse(suf + 1, suf + n + 1);
	fu(i, 0, n) if(ans < pre[i] + suf[i + 1]) ans = pre[i] + suf[i + 1], ansp = i;
	reverse(a + 1, a + n + 1);
	for(int p = ansp; p; p = lstp[p]) fu(j, lstp[p] + 1, p) c[j] = a[p];
	reverse(a + 1, a + n + 1);
	for(int p = n - ansp; p; p = lsts[p]) fu(j, lsts[p] + 1, p) d[j] = a[p];
	fu(i, 1, ansp) printf("%d ", c[i]);
	fd(i, n - ansp, 1) printf("%d ", d[i]);
	return 0;	
}