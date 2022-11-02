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
const int N=101000;
int n,l,x,y,a[N]={},ans[5]={},tot=0;
bool dx=false,dy=false;
int main()
{	
	scanf("%d%d%d%d",&n,&l,&x,&y);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		dx|=binary_search(a+1,a+n+1,a[i]+x);
		dy|=binary_search(a+1,a+n+1,a[i]+y);
	}
	if(dx && dy)
		printf("0\n");
	if(dx && !dy)
		printf("1\n%d\n",y);
	if(!dx && dy)
		printf("1\n%d\n",x);
	if(!dx && !dy)
	{
		int d=y-x;
		for(int i=1;i<=n;++i)
		{
			if(binary_search(a+1,a+n+1,a[i]+x+y))
			{
				printf("1\n%d\n",a[i]+x);
				return 0;
			}
			if(binary_search(a+1,a+n+1,a[i]+d))
			{
				if(a[i]-x>=0)
				{
					printf("1\n%d\n",a[i]-x);
					return 0;
				}
				if(a[i]+y<=l)
				{
					printf("1\n%d\n",a[i]+y);
					return 0;
				}
			}
		}
		printf("2\n%d %d\n",x,y);
	}
	return 0;
}