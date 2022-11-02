#include<bits/stdc++.h>
using namespace std;
const int N=1000100;
int n,a,b,v[N]={};
long long ans=0,w[N]={};
void init()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;++i)
		scanf("%d",v+i);
	ans=(n-1)*1ll*a;
}
long long calc(int p)
{
	//cout<<"p="<<p<<endl;
	int l1=0,r1=-1;
	for(int i=3;i<=n;++i)
		if(l1==0 && abs((v[i]+1)%p-1)>1)
			l1=i;
	for(int i=n;i>=3;--i)
		if(r1==-1 && abs((v[i]+1)%p-1)>1)
			r1=i;
	//cout<<"l1="<<l1<<" r1="<<r1<<endl;
	if(l1)
	{
		long long s1=(n-r1)*1ll*a,s2=(l1-3)*1ll*a;
		int t=0;
		for(int i=r1+1;i<=n;++i)
			if(v[i]%p)
				++t;
		s1=min(s1,t*1ll*b);
		for(int i=r1+1;i<=n;++i)
			if(v[i]%p)
				s1=min(s1,(i-r1)*1ll*a+(--t)*1ll*b);
		for(int i=l1-1;i>=3;--i)
			if(v[i]%p)
				++t;
		s2=min(s2,t*1ll*b);
		for(int i=l1-1;i>=3;--i)
			if(v[i]%p)
				s2=min(s2,(l1-i)*1ll*a+(--t)*1ll*b);
		//cout<<"s1="<<s1<<" s2="<<s2<<endl;
		return s1+s2+(r1-l1+1)*1ll*a;
	}
	else
	{
		int t=0;
		for(int i=3;i<=n;++i)
			if(v[i]%p)
				++t;
		long long sum=t*1ll*b,now=0;
		for(int i=3;i<=n;++i)
		{
			now+=a;
			if(v[i]%p)
				now-=b;
			now=min(now,0ll);
			sum=min(sum,t*1ll*b+now);
		}
		//cout<<"sum="<<sum<<endl;
		return sum;
	}
}
long long calc()
{
	long long ans=1ll<<60;
	for(int x=v[1]-1;x<=v[1]+1;++x)
		for(int y=v[2]-1;y<=v[2]+1;++y)
		{
			long long sum=1ll<<60;
			int z=__gcd(x,y);
			for(int i=2;i*i<=z;++i)
				if(z%i==0)
				{
					sum=min(sum,calc(i));
					while(z%i==0)
						z/=i;
				}
			if(z>1)
				sum=min(sum,calc(z));
			ans=min(ans,sum+(x!=v[1])*b+(y!=v[2])*b);
		}
	return ans;
}
void work()
{
	if(n==1)
	{
		puts("0");
		return;
	}
	ans=min(calc(),ans);
	reverse(v+1,v+n+1);
	ans=min(calc(),ans);
	for(int i=v[1]-1;i<=v[1]+1;++i)
		for(int j=v[n]-1;j<=v[n]+1;++j)
			if(__gcd(i,j)>1)
				ans=min(ans,(n-2)*1ll*a+bool(i-v[1])*b+bool(j-v[n])*b);
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}