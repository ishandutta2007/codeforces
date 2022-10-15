#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=1e5+7;
int n;
char s[N], t[N];
inline void work() {
	n=read(), scanf("%s%s", s+1, t+1);
	reverse(t+1, t+n+1);
	map<pair<int, int>, int>mp;
	for (int i=1; i<=n; i++) {
		int x=s[i]-'a', y=t[i]-'a';
		if (x>y) swap(x, y);
		mp[{x, y}]++;
	}
	int cnt=0;
	for (auto &[a, b]:mp)
		if (b&1) {
			cnt++;
			if (a.fi!=a.se) {puts("NO"); return;} 
		}
	puts(cnt<=1?"YES":"NO");
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	for (int T=read(); T; T--) work();
	return 0;
}