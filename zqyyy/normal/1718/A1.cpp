#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n, a[N];
inline void work() {
	n=read();
	for (int i=1; i<=n; i++) a[i]=read();
	int ans=n, sum=0; set<int>s; s.insert(0);
	for (int i=1; i<=n; i++) {
		sum^=a[i];
		if (s.find(sum)!=s.end()) s.clear(), sum=0, s.insert(0), ans--;
		else s.insert(sum);
	}
	printf("%d\n", ans);
}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	int test=read();
	while (test--) work();
	return 0;
}