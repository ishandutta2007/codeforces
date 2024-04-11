#include <bits/stdc++.h>
using namespace std;
const int N=1e3+20;
int a[N][N],b[N][N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int n,i,j,k,r=0;
		cin>>n;
		for (i=0;i<=n+1;i++) for (j=0;j<=n+1;j++) b[i][j]=0;
		for (i=1;i<=n;i++) for (j=1;j<=n;j++) cin>>a[i][j];
		for (j=1;j<=n;j++) b[1][j]=1,r^=a[1][j];
		for (i=2;i<=n;i++) for (j=1;j<=n;j++)
		{
			if (b[i-1][j-1]^b[i-2][j]^b[i-1][j+1]^1) b[i][j]=1,r^=a[i][j];
		}
		cout<<r<<'\n';
	}
}