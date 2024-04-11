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
int n,m,d[3030]={};
int main()
{	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d",&d[i]);
	sort(d+1,d+m+1);
	if(d[1]==1 || d[m]==n)
		printf("NO\n");
	else
	{
		for(int i=3;i<=m;++i)
			if(d[i]==d[i-1]+1 && d[i]==d[i-2]+2)
			{	
				printf("NO\n");
				goto end;
			}
		printf("YES\n");
	}
	end:
	return 0;
}