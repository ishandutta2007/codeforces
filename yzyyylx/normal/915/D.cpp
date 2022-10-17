#include<iostream>
#include<cstdio>
#include<queue>
#define N 510
using namespace std;

int n,m,mm[N][N],ds[N],num[N],sum,now;
queue<int>que,dn;

int main()
{
	register int i,j,p,q;
	cin>>n>>m;
	for(i=1; i<=m; i++)
	{
		scanf("%d%d",&p,&q);
		mm[p][q]=1;
		ds[q]++;
	}
	for(i=1; i<=n; i++)
	{
		num[i]=ds[i];
		if(!ds[i]) que.push(i),sum++;
	}
	for(; !que.empty();)
	{
		p=que.front();
		que.pop();
		for(i=1; i<=n; i++)
		{
			if(mm[p][i])
			{
				ds[i]--;
				if(!ds[i]) que.push(i),sum++;
			}
		}
	}
	if(sum==n)
	{
		cout<<"YES";
		return 0;
	}
	now=sum;
	for(i=1; i<=n; i++)
	{
		num[i]=ds[i];
		if(ds[i]==1)
		{
			dn.push(i);
		}
	}
	
	for(; !dn.empty();)
	{
		p=dn.front();
		dn.pop();
		que.push(p);
		for(i=1; i<=n; i++)
		{
			ds[i]=num[i];
		}
		ds[p]--;
		sum=now;
		for(; !que.empty();)
		{
			q=que.front();
			que.pop();
			for(i=1; i<=n; i++)
			{
				if(!ds[i]) continue;
				if(mm[q][i])
				{
					ds[i]--;
					if(!ds[i])
					{
						que.push(i),sum++;
					}
				}
			}
		}
		if(sum==n-1)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}