#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#define SIZE 100005

using namespace std;
typedef long long int ll;

ll in[SIZE];

int main()
{
	int n;
	ll l,x,y;
	scanf("%d %I64d %I64d %I64d",&n,&l,&x,&y);
	for(int i=0;i<n;i++) scanf("%I64d",&in[i]);
	bool X=false,Y=false,XY=false,XY2=false,XY3=false;
	int L,R,T;
	for(int i=0;i<n;i++)
	{
		int p=lower_bound(in,in+n,in[i]+x)-in;
		if(p<n&&in[p]==in[i]+x) X=true;
		p=lower_bound(in,in+n,in[i]+y)-in;
		if(p<n&&in[p]==in[i]+y) Y=true;
		p=lower_bound(in,in+n,in[i]+x+y)-in;
		if(p<n&&in[p]==in[i]+x+y)
		{
			XY=true;
			L=i;
		}
		p=lower_bound(in,in+n,in[i]+y-x)-in;
		if(p<n&&in[p]==in[i]+y-x&&in[i]+y<=l)
		{
			XY2=true;
			R=i;
		}
		else if(p<n&&in[p]==in[i]+y-x&&in[i]-x>=0)
		{
			XY3=true;
			T=i;
		}
	}
	if(X&&Y) puts("0");
	else
	{
		if(X)
		{
			puts("1");
			printf("%I64d\n",y);
		}
		else if(Y)
		{
			puts("1");
			printf("%I64d\n",x);
		}
		else if(XY)
		{
			puts("1");
			printf("%I64d\n",in[L]+x);
		}
		else if(XY2)
		{
			puts("1");
			printf("%I64d\n",in[R]+y);
		}
		else if(XY3)
		{
			puts("1");
			printf("%I64d\n",in[T]-x);
		}
		else
		{
			puts("2");
			printf("%I64d %I64d\n",x,y);
		}
	}
	return 0;
}