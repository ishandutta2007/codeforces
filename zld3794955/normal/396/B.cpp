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
const int maxn=40000;
int T,n;
long long sa=1,sb=2;
int prime[20100]={},p=0;
bool b[40400]={};
void init()
{
	for(int i=2;i<=maxn;++i)
	{
		if(!b[i])
			prime[++p]=i;
		for(int j=1;j<=p && i*prime[j]<=maxn;++j)
		{
			b[i*prime[j]]=true;
			if(i%prime[j]==0)
				break;
		}
	}
}
bool check(long long p)
{
	for(int j=1;prime[j]*prime[j]<=p;++j)
		if(p%prime[j]==0)
			return false;
	return true;
}
long long gcd(long long a,long long b)
{
	return b==0 ? a : gcd(b,a%b);
}
void work()
{
	long long p=n+1,q=n;
	while(!check(p))
		++p;
	while(!check(q))
		--q;
	sa=p-2;
	sb=2;
	//cout<<"pre="<<sa<<'/'<<sb<<endl;
	long long da=1,db=q;
	da=p-n-1;
	//cout<<"dec="<<da<<'/'<<db<<endl;
	long long ea=sa*db-sb*da,eb=sb*db,k=gcd(ea,eb);
	ea/=k;
	eb/=k;
	eb*=p;
	k=gcd(ea,eb);
	ea/=k;
	eb/=k;
	cout<<ea<<'/'<<eb<<endl;
}
int main()
{	
	cin>>T;
	init();
	while(T--)
	{
		cin>>n;
		work();
	}
	return 0;
}