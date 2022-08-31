#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#define SIZE 100005

using namespace std;
typedef long long int ll;

ll mpow(ll m,ll t,ll p)
{
	if(t==0) return 1;
	ll ret=mpow(m,t/2,p);
	ret=ret*ret%p;
	if(t%2==1) ret=ret*m%p;
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		puts("YES");
		puts("1");
		return 0;
	}
	if(n==4)
	{
		puts("YES");
		puts("1");
		puts("3");
		puts("2");
		puts("4");
		return 0;
	}
	if(n==2)
	{
		puts("YES");
		puts("1");
		puts("2");
		return 0;
	}
	for(int i=2;i<n;i++)
	{
		if(n%i==0)
		{
			puts("NO");
			return 0;
		}
	}
	vector <int> div;
	for(int i=2;i<n-1;i++)
	{
		if((n-1)%i==0)
		{
			div.push_back(i);
		}
	}
	int g=-1;
	for(int i=2;i<n;i++)
	{
		bool ok=true;
		for(int j=0;j<div.size();j++)
		{
			if(mpow(i,div[j],n)==1)
			{
				ok=false;
				break;
			}
		}
		if(ok)
		{
			g=i;
			break;
		}
	}
	puts("YES");
	for(int i=1;i<=n-1;i++)
	{
		if(i==1) puts("1");
		else
		{
			if(i%2==0) printf("%d\n",(int) mpow(g,i-1,n));
			else printf("%d\n",(int) mpow(g,n-i,n));
		}
	}
	printf("%d\n",n);
	return 0;
}