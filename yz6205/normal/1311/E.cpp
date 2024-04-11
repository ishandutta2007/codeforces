#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
bool checkMax(int& a, int b) { return a<b ? a=b,1 : 0; }
bool checkMin(int& a, int b) { return a>b ? a=b,1 : 0; }
#ifdef __LOCALE__
#define ses(a) cout << #a << "=" << a << ' '
#define see(a) cout << #a << "=" << a << endl
#else
#define ses(a)
#define see(a)
#endif

const int N = 5005;
int dep[N], fa[N];
vector <int> le;

void solve() {
	le.clear();
	int n, d; scanf("%d%d", &n, &d);
	int pos = 0;
	dep[1] = 0;
	for (int i=2;i<=n;i++) { 
		dep[i] = dep[i/2] + 1; fa[i] = i/2;
		pos += dep[i]; }
	if (pos > d) { puts("NO"); return; }
	if (n*(n-1)/2 < d) { puts("NO"); return; }
	ses(pos);see(d);
	for (int i=1;i<=n;i*=2) { le.push_back(i); }
	for (int i=n;i>=2;i--) {
		if ((i & (i-1)) == 0) { continue; }
		if (pos == d) { break; } 
		int del = d - pos;
		int up = min(del, (int)(le.size())-dep[i]);
		fa[i] = le[dep[i]+up-1];
		le.push_back(i);
		pos += up; }
	puts("YES");
	for (int i=2;i<=n;i++) { printf("%d%c", fa[i], " \n"[i==n]); }
}

int main() {
	int T; scanf("%d",&T);
	while (T--) { solve(); }
	return 0;
}