#include<bits/stdc++.h>
using namespace std;
const int N=100010,D=40;
int T,n,a[N]={},d[D]={};
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			for(int j=0;j<=30;++j)
				if((1<<j)<=a[i] && a[i]<(2<<j)) // j=30 is dangerous but out of data range
					++d[j];
		}
		long long ans=0;
		for(int i=0;i<=30;++i)
			ans+=(d[i]*1ll*(d[i]-1))/2;
		cout<<ans<<endl;
	}
}