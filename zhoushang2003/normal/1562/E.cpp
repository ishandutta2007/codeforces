#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5002;
int T,n,g[N][N],f[N],A;
string s;
signed main()
{
	cin>>T;
	while(T--&&cin>>n>>s)
	{
		s=" "+s,A=0;
		for(int i=1;i<=n+1;i++)
			for(int j=1;j<=n+1;j++)
				g[i][j]=0;
		for(int i=n;i>=1;i--)
			for(int j=i;j>=1;j--)
				if(s[i]==s[j])
					g[j][i]=g[j+1][i+1]+1;
		for(int i=1;i<=n;i++)
		{
			f[i]=n-i+1;
			for(int j=1;j<i;j++)
				if(s[i+g[j][i]]>s[j+g[j][i]])
					f[i]=max(f[i],n-i+1+f[j]-g[j][i]);
			A=max(A,f[i]);
		}
		cout<<A<<'\n';
	}
	return 0;
}