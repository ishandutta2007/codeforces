#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
const long long mod=1000000007;
long long n,x,a[100050]={},p=0,sum=0,l[100050]={},ans=0;
long long f(long long x,long long y)
{
	if(y==0)
		return 1;
	if(y==1)
		return x;
	long long a=f(x,y/2);
	if(y&1)
		return a*a%mod*x%mod;
	else
		return a*a%mod;
}
int main()
{	
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		sum+=a[i];
	for(int i=1;i<=n;++i)
		l[i]=sum-a[i];
	p=l[n];
	while(x<=n)
	{	
		int t=1;
		while(t<n && l[n-t]==l[n])
			++t;
		if(t%x==0)
		{
			++p;
			int o=t/x;
			for(int i=n-t+1;i<=n-t+o;++i)
				l[i]=l[n]+1;
			n=n-t+o;
		}
		else
			break;
	}
	p=min(sum,p);
	ans=f(x,p);
	cout<<ans<<endl;
	return 0;
}