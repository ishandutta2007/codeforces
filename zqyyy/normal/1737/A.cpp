#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+c-48, c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}

int n, K, cnt[26];
char str[207];
inline void work() {
	n=read(), K=read(), scanf("%s", str+1), fill(cnt, cnt+26, 0);
	for (int i=1; i<=n; i++) cnt[str[i]-'a']++;
	K=n/K;
	for (int i=1; i<=n/K; i++) {
		int p=0;
		while (cnt[p] && p<K) p++;
		putchar(p+'a');
		for (int j=0; j<p; j++) cnt[j]--;
	}
	putchar(10);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=read();
	while (test--) work();
	return 0;
}