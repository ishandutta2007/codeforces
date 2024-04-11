#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=41;
int t,n,k,v[N][N];
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>k)
	{
		if((n+1)/2<k)
		{
			cout<<-1<<'\n';
			continue;
		}
		memset(v,0,sizeof(v));
		for(int i=1;i<=k;i++)
			v[2*i-1][2*i-1]=1;
		for(int i=1;i<=n;i++,cout<<'\n')
			for(int j=1;j<=n;j++)
				cout<<(v[i][j]?'R':'.');
	}
}