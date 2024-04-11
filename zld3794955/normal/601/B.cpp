#include<bits/stdc++.h>
using namespace std;
const int N=100100,Inf=1<<30;
int n,q,a[N]={},d[N]={},s[N]={},t=0;
void init()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<n;++i)
		d[i]=abs(a[i+1]-a[i]);
}
void work()
{
	int l,r;
	while(q--)
	{
		scanf("%d%d",&l,&r);
		s[0]=l-1;
		t=0;
		long long nows=0,ans=0;
		for(int j=l;j<r;++j)
		{
			while(t && d[j]>=d[s[t]])
			{
				nows-=d[s[t]]*1ll*(s[t]-s[t-1]);
				--t;
			}
			s[++t]=j;
			nows+=d[s[t]]*1ll*(s[t]-s[t-1]);
			ans+=nows;
		}
		cout<<ans<<endl;
	}
}
int main()
{	
	init();
	work();
	return 0;
}