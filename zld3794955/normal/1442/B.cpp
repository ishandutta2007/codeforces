#include<bits/stdc++.h>
using namespace std;
const int N=200200,mod=998244353;
int T,n,k,a[N]={},b[N]={},t[N]={},p[N]={};
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		for(int i=1;i<=k;++i)
			scanf("%d",b+i);
		fill(t+1,t+n+1,0);
		fill(p+1,p+n+1,0);
		for(int i=1;i<=n;++i)
			p[a[i]]=i;
		for(int i=1;i<=k;++i)
			++t[b[i]];
		int ans=1;
		for(int i=1;i<=k;++i)
		{
			int pos=p[b[i]];
			//cout<<"i="<<i<<" pos="<<pos<<" ans="<<ans<<endl;
			ans=ans*((pos>=2 && !t[a[pos-1]])+(pos<=n-1 && !t[a[pos+1]]))%mod;
			--t[b[i]];
		}
		printf("%d\n",ans);
	}
}