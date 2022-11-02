#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=5e2+2;
int a[N][N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,i,j,m;
		ll ans=0;
		cin>>n;m=n<<1;
		for (i=1;i<=m;i++) for (j=1;j<=m;j++) cin>>a[i][j];
		for (i=n+1;i<=m;i++) ans=accumulate(a[i]+n+1,a[i]+m+1,ans);
		cout<<ans+min({a[n+1][1],a[m][1],a[n+1][n],a[m][n],a[1][n+1],a[1][m],a[n][n+1],a[n][m]})<<'\n';
	}
}