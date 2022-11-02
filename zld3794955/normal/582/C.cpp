#include<bits/stdc++.h>
using namespace std;
const int N=200200;
int n,m,a[N+N]={},s[N]={},maxv[N+N]={};
long long ans=0;
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	copy(a+1,a+n+1,a+n+1);
	for(int i=1;i<n;++i)
		if(n%i==0)
		{
			fill(maxv,maxv+i,0);
			for(int j=1,t=1%i;j<=n;++j,t=t==i-1 ? 0 : t+1)
				maxv[t]=max(maxv[t],a[j]);
			for(int j=i;j<=n+n;++j)
				maxv[j]=maxv[j-i];
			for(int j=1;j<=n/i;++j)
				s[j]=(__gcd(n/i,j)==1)+s[j-1];
			int now=0;
			for(int j=1;j<=n+n;++j)
			{
				now=(a[j]==maxv[j]) ? min(now+1,n) : 0;
				if(now==0 && j>=n)
					break;
				ans+=s[now/i]-s[max(0,j-n)/i];
			}
		}
	cout<<ans<<endl;
	cerr<<clock()<<endl;
	return 0;
}