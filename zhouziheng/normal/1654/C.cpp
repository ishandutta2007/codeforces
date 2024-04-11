#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

map<long long,long long> mp;
long long a[200000];

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);long long sum=0;for(int i=1;i<=n;i++)scanf("%lld",&a[i]),sum+=a[i],mp[a[i]]++;
		long long cnt1=1,cnt2=0;long long a=sum;
		while(a>0)
		{
			if(mp[a]){long long t=min(cnt1,mp[a]);cnt1-=t,mp[a]-=t;}
			if(mp[a+1]){long long t=min(cnt2,mp[a+1]);cnt2-=t,mp[a+1]-=t;}
			
			long long new1=0,new2=0;
			if(a%2==0)new1=2*cnt1+cnt2,new2=cnt2;
			else new1=cnt1,new2=2*cnt2+cnt1;
			cnt1=new1,cnt2=new2;
			a/=2;
		}
		long long t=min(cnt2,mp[1]);cnt2-=t;puts(cnt2?"NO":"YES");
		mp.clear();
	}
}