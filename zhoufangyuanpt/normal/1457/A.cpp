#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,m,x,y;scanf("%d%d%d%d",&n,&m,&x,&y);
		int ss=0;
		if(ss<n-x+m-y)ss=n-x+m-y;
		if(ss<x-1+m-y)ss=x-1+m-y;
		if(ss<x-1+y-1)ss=x-1+y-1;
		if(ss<n-x+y-1)ss=n-x+y-1;
		printf("%d\n",ss);
	}
	return 0;
}