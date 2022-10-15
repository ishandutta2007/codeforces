#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=55;
int n, m;
char s[N], t[N];
inline void work() {
	n=read(), m=read(), scanf("%s%s", s+1, t+1);
	int p=n-m+1;
	for (int i=p+1; i<=n; i++) if (s[i]!=t[i-p+1]) {puts("NO"); return;}
	for (int i=1; i<=p; i++) if (s[i]==t[1]) {puts("YES"); return;}
	puts("NO");
}
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=read();
	while (test--) work();
	return 0;
}