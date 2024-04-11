#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1<<16;
int f[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n>>m;
		if (n==4&&m==3) {cout<<"-1\n";continue;}
		for (i=0;i<n;i++) f[i]=n-1-i;
		if (m!=n-1)
		{
			f[m]=n-1;f[n-1]=m;
			f[0]=n-m-1;f[n-m-1]=0;
			int ans=0;
			for (i=0;i<n;i++) if (i<f[i]) cout<<i<<' '<<f[i]<<'\n',ans+=i&f[i];
			assert(ans==m);
		}
		else
		{
			f[n-1]=n-2;f[n-2]=n-1;
			f[0]=n-3;f[n-3]=0;
			f[1]=3;f[3]=1;
			f[2]=n-4;f[n-4]=2;
			int ans=0;
			for (i=0;i<n;i++) if (i<f[i]) cout<<i<<' '<<f[i]<<'\n',ans+=i&f[i];
			assert(ans==m);
		}
	}
}