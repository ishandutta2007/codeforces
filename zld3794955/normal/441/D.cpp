#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=3030;
int n,a[N]={},m,num[N]={},size[N]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	scanf("%d",&m);
}
int calc()
{
	bool v[N]={};
	int sum=0,N=0;
	for(int i=1;i<=n;++i)
		if(!v[i])
		{
			++N;
			v[i]=true;
			int x=i;
			while(!v[x=a[x]])
			{
				++sum;
				v[x]=true;
			}
		}
	return sum;
}
void mark()
{
	bool v[N]={};
	int N=0;
	for(int i=1;i<=n;++i)
		if(!v[i])
		{
			int s=1;
			++N;
			v[i]=true;
			num[i]=N;
			int x=i;
			while(!v[x=a[x]])
				v[x]=true,num[x]=N,++s;
			size[N]=s;
		}
}
void inc(int t)
{
	while(t--)
	{
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(num[i]!=num[j])
				{
					swap(a[i],a[j]);
					mark();
					printf("%d %d ",i,j);
					goto out;
				}
		out:
			;
	}
	printf("\n");
}
void dec(int t)
{
	while(t--)
	{
		for(int i=1;i<=n;++i)
		{
			if(size[num[i]]==1)
				continue;
			for(int j=i+1;j<=n;++j)
				if(num[i]==num[j])
				{
					swap(a[i],a[j]);
					mark();
					printf("%d %d ",i,j);
					goto out;
				}
		}
		out:
			;
	}
	printf("\n");
}
void work()
{
	int start=calc(),d=start<m ? 1 : -1;
	int ans=(m-start)*d;
	printf("%d\n",ans);
	mark();
	if(start<m)
		inc(ans);
	else
		dec(ans);
}
int main()
{	
	init();
	work();
	return 0;
}