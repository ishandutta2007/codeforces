#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
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

const int N = 1000005;
int n, cnt, ans, i;
char s[N];

int main() {
	rd(n);
	scanf("%s", s + 1);
	for(i = 1; i <= n; ++i) {
		cnt += s[i] == ')' ? -1 : 1;
		if(cnt >= 0) continue;
		int lsti = i;
		while(i <= n && cnt < 0) cnt += s[++i] == ')' ? -1 : 1;
		if(i > n) puts("-1"), exit(0);
		ans += i - lsti + 1;
	}
	printf(cnt ? "-1" : "%d", ans);
	return 0;
}