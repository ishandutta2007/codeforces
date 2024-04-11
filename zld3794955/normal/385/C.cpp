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
const int maxn=20020000;
int b[20200000]={};
int prime[1400000]={},p=0,t[1400000]={};
int n,x[1010000]={},m;
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&x[i]);
	for(int i=2;i<=maxn;++i)
	{
		if(b[i]!=-1)
			prime[++p]=i,b[i]=p;
		for(int j=1;j<=p && i*prime[j]<=maxn;++j)
		{
			b[i*prime[j]]=-1;
			if(i%prime[j]==0)
				break;
		}
	}
}
inline int lowbit(int x)
{
	return x&(-x);
}
inline void add(int s)
{
	for(int i=s;i<=p;i+=lowbit(i))
		++t[i];
}
inline long long prefix(int s)
{
	long long sum=0;
	for(int i=s;i;i-=lowbit(i))
		sum+=t[i];
	return sum;
}
void work1()
{
	for(int i=1;i<=n;++i)
	{
		int y=x[i];
		//cout<<i<<":";
		for(int j=1;y!=1 && prime[j]*prime[j]<=x[i] && j<=p;++j)
		{	
			if(y%prime[j]==0)
			{
				add(j);
				while(y%prime[j]==0)
					y/=prime[j];
				//cout<<j<<' ';
			}
		}
		//cout<<endl;
		if(y!=1)
			add(b[y]);
	}
}
void work2()
{
	scanf("%d",&m);
	int l,r;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&l,&r);
		int pos1=lower_bound(prime+1,prime+p+1,l)-prime;
		int pos2=lower_bound(prime+1,prime+p+1,r)-prime;
		//cout<<pos1<<' '<<pos2<<endl;
		long long ans1=0,ans2=0;
		if(prime[pos2]==r)
			ans2=prefix(pos2);
		else
			ans2=prefix(pos2-1);
		ans1=prefix(pos1-1);
		//cout<<ans2<<' '<<ans1<<endl;
		if(ans2-ans1<0)
			printf("0\n");
		else
			printf("%I64d\n",ans2-ans1);
	}
}
int main()
{	
	init();
	work1();
	work2();
	return 0;
}