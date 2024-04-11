#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<list>
using namespace std;
typedef long long ll;
list<int> l[1000010];
priority_queue<int> q;
int num[100010];
int ans[100010];
int main()
{
	memset(num,0,sizeof num);
	int n,m;
	scanf("%d%d",&n,&m);
	int i,x,y;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		l[y].push_back(x);
		num[x]++;
	}
	for(i=1;i<=n;i++)
		if(!num[i])
			q.push(i);
	for(i=n;i>=1;i--)
	{
		int v=q.top();
		q.pop();
		for(auto nxt:l[v])
		{
			num[nxt]--;
			if(!num[nxt])
				q.push(nxt);
		}
		ans[v]=i;
	}
	for(i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}