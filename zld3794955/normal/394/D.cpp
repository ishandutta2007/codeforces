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
const int MAXN=1020;
int n,a[MAXN]={},l[MAXN]={},r[MAXN]={},low=0,step=0,w=0;
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
}
bool check(int mid)
{
	for(int i=1;i<=n;++i)
		l[i]=a[i]-mid,r[i]=a[i]+mid;
	int maxd=0x7fffffff;
	for(int i=1;i<n;++i)
		maxd=min(maxd,r[i+1]-l[i]);
	for(int d=0;d<=maxd;++d)
	{
		int L=l[1],R=r[1];
		bool b=true;
		for(int i=2;i<=n;++i)
		{
			L=max(L,l[i]-d*(i-1));
			R=min(R,r[i]-d*(i-1));
			if(L>R)
			{	
				b=false;
				break;
			}
		}
		if(b)
		{
			low=L;
			step=d;
			return true;
		}
	}
	return false;
}
void work()
{
	int l=0,r=10000;
	while(l!=r)
	{
		int mid=l+r>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	check(l);
	printf("%d\n%d %d\n",l,low,step);
}
int main()
{	
	init();
	work();
	return 0;
}