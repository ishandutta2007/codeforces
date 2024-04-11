#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,a[N];

queue<int>q;

int d[N];

void bfs()
{
	int p=1;
	q.push(1);
	d[1]=0;
	p++;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(p>n)
			continue;
		int now=a[p];
		d[now]=d[x]+1;
		q.push(now);
		p++;
		while(p<=n&&a[p]>now)
			now=a[p],d[now]=d[x]+1,q.push(now),p++;
		
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		bfs();
		printf("%d\n",*max_element(d+1,d+n+1));
	}
}