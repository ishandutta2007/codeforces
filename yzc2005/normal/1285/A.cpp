#include <bits/stdc++.h>
using namespace std;
#define rg register
#define fu(i, a, b) for(rg int i = a; i <= b; ++i)
#define fd(i, a, b) for(rg int i = a; i >= b; --i)
#define go(u) for(rg int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
inline void read(int &x) {
	x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - 48, ch = getchar();
} 

int n;
string s;

int main() {
	cin >> n >> s;
	printf("%d\n", n + 1);
	return 0;
}