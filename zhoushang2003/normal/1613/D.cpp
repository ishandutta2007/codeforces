#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6,D=998244353;
int t,n,a[N],f[N][2],A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=0;i<=n+2;i++)
			f[i][0]=f[i][1]=0;
		A=0;
		for(int i=1;i<=n;i++)
		{
			(A+=f[a[i]+2][1])%=D,(f[a[i]+2][1]+=f[a[i]+2][1])%=D;
			if(a[i]==0)
				(A+=f[0][0]+1)%=D,(f[0][0]+=f[0][0]+1)%=D;
			else if(a[i]==1)
				(A+=f[1][1]+1)%=D,(f[1][1]+=f[1][1]+1)%=D,(A+=f[0][0]+f[1][0])%=D,(f[1][0]+=f[0][0]+f[1][0])%=D;
			else
				(A+=f[a[i]][1]+f[a[i]-2][0])%=D,(f[a[i]][1]+=f[a[i]][1]+f[a[i]-2][0])%=D,(A+=f[a[i]-1][0]+f[a[i]][0])%=D,(f[a[i]][0]+=f[a[i]-1][0]+f[a[i]][0])%=D;
		}
		cout<<A<<'\n';
	}
}