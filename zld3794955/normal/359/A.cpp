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
int n,m,a[60][60]={};
int main()
{	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	if(a[1][1] || a[n][1] || a[1][m] || a[n][m])
		printf("1\n");
	else
	{
		bool b=false;
		for(int i=1;i<=n;++i)
			if(a[i][1] || a[i][m])
			{
				b=true;
				break;
			}
		for(int i=1;i<=m;++i)
			if(a[1][i] || a[n][i])
			{
				b=true;
				break;
			}
		if(b)
			printf("2\n");
		else
			printf("4\n");
	}
	return 0;
}