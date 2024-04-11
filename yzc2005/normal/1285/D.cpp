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
vector<int>a;

int solve(int p, vector<int>a) {
	if(p == -1) return 0;
	vector<int> on, off; on.clear(), off.clear();
	fu(i, 0, a.size() - 1) (a[i] >> p) & 1 ? on.push_back(a[i]) : off.push_back(a[i]);
	if(on.empty() || off.empty()) return solve(p - 1, a);
	return min(solve(p - 1, on), solve(p - 1, off)) + (1 << p);
}

int main() {
	read(n);
	a.resize(n);
	fu(i, 0, n - 1) read(a[i]);
	printf("%d\n", solve(30, a));
	return 0;
}