#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LL long long

int n,m;
int a[MAXN];
int f[MAXN][22],g[MAXN][22];
LL h[MAXN];

void rd()
{
	scanf("%d",&n);
	for(int i = 1; i < n; i ++)
		scanf("%d",&a[i]);
	for(int i = 1; i <= n; i ++)
	{
		f[i][0] = a[i];
		g[i][0] = i;
	}
	for(int j = 1; j <= 20; j ++)
		for(int i = 1; i <= n; i ++)
		if(i + (1<<j) - 1 <= n) {
			f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			if(f[i][j-1] > f[i+(1<<(j-1))][j-1])
				g[i][j] = g[i][j-1];
			else g[i][j] = g[i+(1<<(j-1))][j-1];
		}
}

int rmq(int l,int r)
{
	int o = log2(r-l+1);
	if(f[l][o] > f[r-(1<<o)+1][o]) return g[l][o];
	else return g[r-(1<<o)+1][o];
}

int main()
{
	rd();
	LL ans = 0;
	for(int i = n-1; i >= 1; i --) {
		int k = rmq(i+1,a[i]);
		if(a[i] >= n) {
			h[i] = n-i;
		} else {
			h[i]  = h[k] - (a[i] - k) + (n-i);
		}
		ans += h[i];
	}
	cout<<ans<<"\n";
	return 0;
}