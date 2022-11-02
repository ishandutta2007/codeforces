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
int n,m;
int main()
{	
	scanf("%d%d",&n,&m);
	if(n>m+1 || (n+1)*2<m)
		puts("-1");
	else
	{
		if(n==m+1)
		{
			for(int i=1;i<=m;++i)
				printf("01");
			printf("0\n");
		}
		else if(n==m)
		{
			for(int i=1;i<=m;++i)
				printf("01");
			printf("\n");
		}
		else if(n==m-1)
		{
			for(int i=1;i<=n;++i)
				printf("10");
			printf("1\n");
		}
		else
		{
			int d=m-(n+1);
			printf("11");
			for(int i=1;i!=d;++i)
				printf("011");
			for(int i=d;i<=n;++i)
				printf("01");
			printf("\n");
		}
	}
	return 0;
}