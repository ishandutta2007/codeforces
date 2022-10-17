#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define N 200100
using namespace std;

int n,sum,ans,size,t,as[N],aa;
struct Node
{
	int time_need,most,pos;
	bool operator < (const Node &u) const
	{
		return time_need<u.time_need;
	}
} node[N];
priority_queue<Node>pq;

inline bool cmp(Node u,Node v)
{
	return u.most>v.most||u.most==v.most&&u.time_need<v.time_need;
}

int main()
{
	int i,j;
	cin>>n>>t;
	for(i=1; i<=n; i++)
	{
		scanf("%d%d",&node[i].most,&node[i].time_need);
		node[i].pos=i;
	}
	sort(node+1,node+n+1,cmp);
	for(i=1; i<=n; i++)
	{
		if(node[i].most<=size)
		{
			printf("%d\n%d\n",size,size);
			for(; !pq.empty(); pq.pop())
			{
				printf("%d " ,pq.top().pos);
			}
			return 0;
		}
		if(sum+node[i].time_need<=t)
		{
			pq.push(node[i]);
			size++;
			sum+=node[i].time_need;
		}
		else if(!pq.empty()&&node[i].time_need<pq.top().time_need)
		{
			sum-=pq.top().time_need-node[i].time_need;
			pq.pop();
			pq.push(node[i]);
		}
	}
	printf("%d\n%d\n",size,size);
	for(; !pq.empty(); pq.pop())
	{
		printf("%d ",pq.top().pos);
	}
}