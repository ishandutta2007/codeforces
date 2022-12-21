#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
int a[10]={0,4,8,15,16,23,42};
int ans[10];
int now[10];
bool vis[10];
inline void dfs(int step)
{
	if(step==7)
	{
		bool ok=true;
		for(int i=1;i<=4;++i)
		{
			if(now[i]*now[i+1]!=ans[i])ok=false;
		}
		if(ok)
		{
			printf("! ");
			for(int i=1;i<=6;++i)
			{
				printf("%d ",now[i]);
			}
			printf("\n");
			exit(0); 
		}
	}
	else
	{
		for(int i=1;i<=6;++i)
		{
			if(!vis[i])
			{
				vis[i]=true;
				now[step]=a[i];
				dfs(step+1);
				vis[i]=false;
			}
		}
	}
}
int main()
{
	for(int i=1;i<=4;++i)
	{
		printf("? %d %d\n",i,i+1);
		fflush(stdout);
		scanf("%d",&ans[i]);
	}
	dfs(1);
	return 0;
}