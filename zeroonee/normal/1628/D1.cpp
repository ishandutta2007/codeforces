#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef unsigned long long ll;
#define all(x) (x).begin(),(x).end()
const int N=2e3+2;
const ui p=1e9+7;
ui ksm(ui x,ui y)
{
	ui r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;y>>=1;
	}
	return r;
}
ui f[N][N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,k;
		cin>>n>>m>>k;
		for (i=0;i<=n;i++) for (j=0;j<=n;j++) f[i][j]=0;
		for (i=1;i<=n;i++)
		{
			f[i][i]=(ll)k*i%p;
			for (j=1;j<i;j++) if ((f[i][j]=f[i-1][j]+f[i-1][j-1])&1) f[i][j]=(f[i][j]+p>>1)%p; else f[i][j]>>=1;
			for (j=i+1;j<=n;j++) f[i][j]=f[i][i];
		}
		cout<<f[n][m]<<'\n';
	}
}