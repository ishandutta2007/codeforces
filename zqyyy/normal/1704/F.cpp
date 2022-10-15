#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=5e5+7;
int n, sg[N];
char str[N];
inline void work() {
	n=read(), scanf("%s", str+1);
	int r=count(str+1, str+n+1, 'R'), b=count(str+1, str+n+1, 'B');
	if (r^b) {puts(r>b?"Alice":"Bob"); return;}
	int ans=0;
	for (int l=1, r=1; l<=n; l=r) {
		while (r<=n && (r-l+1)%2==(str[l]==str[r])) r++;
		ans^=sg[r-l];
	}
	puts(ans?"Alice":"Bob");
}
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	sg[0]=sg[1]=0, n=200;
	for (int i=2; i<=n; i++) {
		static bool vis[207];
		for (int j=0; j<=i-2; j++) vis[sg[j]^sg[i-2-j]]=true;
		while (vis[sg[i]]) sg[i]++;
		for (int j=0; j<i; j++) vis[j]=false;
	}
	for (int i=n+1; i<N; i++) sg[i]=sg[i-34];
	int test=read();
	while (test--) work();
	return 0;
}