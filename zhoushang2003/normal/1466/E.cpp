#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+1,D=1e9+7;
int T,n,a[N],c[61],A,x,y;
signed main()
{
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--&&cin>>n)
	{
		memset(c,0,sizeof(c)),A=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=0;j<60;j++)
				if((a[i]>>j)&1)
					c[j]++;
		for(int i=1;i<=n;i++)
		{
			x=y=0;
			for(int j=0;j<60;j++)
				if((a[i]>>j)&1)
					(x+=n*((1ll<<j)%D))%=D;
				else
					(x+=c[j]*((1ll<<j)%D))%=D;
			for(int j=0;j<60;j++)
				if((a[i]>>j)&1)
					(y+=c[j]*((1ll<<j)%D))%=D;
			(A+=x*y)%=D;
		}
		cout<<A<<'\n';
	}
	return 0; 
}