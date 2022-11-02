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
bool b[110][110]={};
int n,m,a;
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&m);
		for(int j=1;j<=m;++j)
		{	
			scanf("%d",&a);
			b[i][a]=true;
		}
	}
	for(int i=1;i<=n;++i)
	{	
		bool flag=true;
		for(int j=1;j<=n;++j)
		{	
			bool f=(i==j);
			for(int k=1;k<=100;++k)
				if(b[j][k] && !b[i][k])
					f=true;
			if(!f)
			{
				puts("NO");
				flag=false;
				break;
			}
		}
		if(flag)
			puts("YES");
	}
	return 0;
}