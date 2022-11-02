#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 100009;
LL a[maxn], b[maxn], f[maxn], g[maxn];
LL n, best = 1e18;

int main(){
	scanf("%I64d", &n);
	for (int i=1; i<=n; i++){
		scanf("%I64d", &a[i]); b[i] = a[i];
	}
	for (int i=2; i<=n; i++){
		if (a[i-1] >= a[i]){
			f[i] = f[i-1] + a[i-1]+1 - a[i];
			a[i] = a[i-1] + 1;
		}
		else f[i] = f[i-1];
	}
	for (int i=n-1; i>=1; i--){
		if (b[i+1] >= b[i]){
			g[i] = g[i+1] + b[i+1]+1 - b[i];
			b[i] = b[i+1] + 1;
		}
		else g[i] = g[i+1];
	}
	for (int i=0; i<=n; i++)
		best = min(best, f[i]+g[i+1]+(a[i] == b[i+1]));
	printf("%I64d\n", best);
	return 0;
}