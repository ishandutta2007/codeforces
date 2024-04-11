#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=107;
int n, tot, a[N], fib[N], lst[N];
bool v[N][N];
ll sum[N];
inline void work() {
	n=read(); ll Sum=0;
	for (int i=1; i<=n; i++) Sum+=a[i]=read();
	if (Sum>2e9) {puts("No"); return; }
	int p=lower_bound(sum+1, sum+tot+1, Sum)-sum;
	if (sum[p]!=Sum) {puts("No"); return; }
	for (int i=1; i<=n; i++) {
		int x=a[i]; v[i][p+1]=false;
		for (int j=p; j; j--)
			if (x>=fib[j] && !v[i][j+1]) v[i][j]=true, x-=fib[j], lst[i]=j;
			else v[i][j]=false;
		if (x) {puts("No"); return;}
	}
	for (int j=p; j; j--) {
		int pos=0;
		for (int i=1; i<=n; i++)
			if (v[i][j]) {
				if (!pos || lst[pos]==j) pos=i;
				else if (lst[i]!=j) {puts("No"); return;}
			}
		if (!pos) {puts("No"); return;}
		v[pos][j]=false;
		for (int i=1; i<=n; i++)
			if (v[i][j] && pos!=i) {
				assert(lst[i]==j);
				if (j&1) {puts("No"); return;}
				v[i][j]=false;
				for (int k=1; k<=j; k+=2) v[i][k]=true;
			}
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=p; j++) assert(!v[i][j]);
	puts("Yes");
}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	fib[1]=fib[2]=1, sum[1]=1, sum[2]=2, tot=2;
	while (fib[tot]<=1e9) {
		tot++, fib[tot]=fib[tot-1]+fib[tot-2];
		sum[tot]=sum[tot-1]+fib[tot];
	}
	sum[tot--]=0;
	int test=read();
	while (test--) work();
	return 0;
}