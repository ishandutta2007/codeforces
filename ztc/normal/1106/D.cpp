#include<stdio.h>
#include<queue>
#include<stack>
#define Min(a,b) (a<b?a:b)
int n,m;
bool a[100002];
int Last[100002],Next[200002],End[200002],t,i;
std::priority_queue<int,std::vector<int>,std::greater<int>>Q;
main()
{
	scanf("%d%d",&n,&m);
	a[1]=1;Q.push(1);
	for(i=1;i<=m*2;i+=2)
	{
		scanf("%d%d",&End[i+1],&End[i]);
		Next[i]=Last[End[i+1]];Last[End[i+1]]=i;
		Next[i+1]=Last[End[i]];Last[End[i]]=i+1;
	}
	while(!Q.empty())
	{
		printf("%d ",t=Q.top());
		Q.pop();i=Last[t];
		while(i)
		{
			if(!a[End[i]])
			{
				Q.push(End[i]);
				a[End[i]]=1;
			}
			i=Next[i];
		}
	}
}