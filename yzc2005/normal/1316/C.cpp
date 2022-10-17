#include <bits/stdc++.h>
//pray for me. 
using namespace std;
typedef long long ll;
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
int n, m, p, a[N], b[N];

int main() {
	rd(n), rd(m), rd(p);
	int pos = n;
	fu(i, 0, n - 1) {
		rd(a[i]);
		if(a[i] % p == 0) continue;
		ckmin(pos, i);
	}
	fu(i, 0, m - 1) {
		rd(b[i]);
		if(b[i] % p == 0) continue;
		cout << pos + i;
		exit(0);
	}
}