#include<cstdio>
#include<algorithm>

using namespace std;

long long f(long long x)
{
	long long minn=9,maxn=0,p=x;
	while(x)
	{
		long long t=x%10;minn=min(minn,t),maxn=max(maxn,t);
		x/=10;
	}
	return p+minn*maxn;
}

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		long long a=0,k=0;scanf("%lld%lld",&a,&k);
		long long ans=a;bool fl=false;
		for(long long i=1;i<k;i++)
		{
			ans=f(a);
			//printf("%lld\n",ans);
			if(ans==a){fl=true;printf("%lld\n",ans);break;}
			a=ans;
		}
		if(!fl)printf("%lld\n",ans);
	}
	return 0;
}