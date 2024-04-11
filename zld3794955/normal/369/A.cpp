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
int n,a,b,d,ans=0;
int main()
{	
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&d);
		if(d==1)
		{
			if(a==0)	
				++ans;
			else
				--a;
		}
		if(d==2)
		{
			if(b==0)
			{
				if(a==0)
					++ans;
				else
					--a;
			}
			else
				--b;
		}
	}
	printf("%d\n",ans);
	return 0;
}