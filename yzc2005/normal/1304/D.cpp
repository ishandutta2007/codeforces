#include <bits/stdc++.h>
using namespace std;
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

const int N = 2e5 + 5;
int T, n, ans[N];
char s[N];

int main() {
	for(rd(T); T; --T) {
		rd(n), scanf("%s", s + 1);
		int l = n, r = 1, cnt = 0;
		while(l) {
			int l1 = l;
			while(l > 1 && s[l - 1] == '<') --l;
			fu(i, l, l1) ans[i] = ++cnt; 
			--l;
		} 
		fu(i, 1, n) printf("%d ", ans[i]);
		puts("");
		cnt = 0;
		while(r <= n) {
			int r1 = r;
			while(r < n && s[r] == '>') ++r;
			fd(i, r, r1) ans[i] = ++cnt;
			++r;
		}
		fu(i, 1, n) printf("%d ", ans[i]);
		puts("");
	}
}