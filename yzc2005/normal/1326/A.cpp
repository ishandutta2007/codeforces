#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> PI;
#define fi first
#define se second
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

int t, n;

int main() {
	for(rd(t); t; --t) {
		rd(n);
		if(n == 1) puts("-1");
		else {
			printf("8");
			fu(i, 1, n - 1) printf("9");
			puts("");
		}
	}
	return 0;
}