#include<bits/stdc++.h>
using namespace std;
namespace CF1439B {
const int N=100010,M=100010,BarK=450;//BarK^2/2>M
int n,m,k,d[N]={},del[N]={};
set<int> snei[N];
vector<int> nei[N];
bool check(int now)
{
	int l[BarK]={};
	int t=0;
	l[++t]=now;
	for(auto p:nei[now])
		if(!del[p])
			l[++t]=p;
	if(t<k)
		return false;
	assert(t==k);
	for(int i=1;i<=t;++i)
		for(int j=1;j<i;++j)
			if(!snei[l[i]].count(l[j]))
				return false;
	return true;
}
int start()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		//n=100000;
		//m=100000;
		for(int i=1;i<=n;++i)
			nei[i].clear();
		for(int i=1,u,v;i<=m;++i)
		{
			//u=rand()+1;
			//v=rand()+1;
			scanf("%d%d",&u,&v);
			nei[u].push_back(v);
			nei[v].push_back(u);
		}
		if(k==1)
		{
			printf("2\n1\n");
			continue;
		}
		if(k>=BarK || k*(k-1)/2>m)
		{
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;++i)
		{
			d[i]=nei[i].size();
			del[i]=false;
		}
		queue<int> q;
		for(int i=1;i<=n;++i)
			if(d[i]<k-1)
			{
				q.push(i);
				del[i]=true;
			}
		while(!q.empty())
		{
			int now=q.front();
			q.pop();
			for(auto p:nei[now])
				if(--d[p]<k-1 && !del[p])
				{
					q.push(p);
					del[p]=true;
				}
		}
		int tot=0;
		for(int i=1;i<=n;++i)
			snei[i].clear();
		for(int i=1;i<=n;++i)
		{
			if(del[i])
				continue;
			++tot;
			for(auto p:nei[i])
				if(!del[p])
					snei[i].insert(p);
			if(d[i]==k-1)
				q.push(i);
		}
		bool clique=false;
		while(!q.empty())
		{
			int now=q.front();
			q.pop();
			//cout<<"now="<<now<<endl;
			if(check(now))
			{
				clique=true;
				puts("2");
				printf("%d",now);
				for(auto p:nei[now])
					if(!del[p])
						printf(" %d",p);
				puts("");
				break;
			}
			else
			{
				--tot;
				del[now]=true;
				for(auto p:nei[now])
					if(--d[p]==k-1)
						q.push(p);
			}
		}
		if(tot)
		{
			if(clique)
				continue;
			printf("1 %d\n",tot);
			for(int i=1;i<=n;++i)
				if(!del[i])
					printf("%d ",i);
			printf("\n");
		}
		else
			puts("-1");
	}
	return 0;
}
}
int main()
{
	return CF1439B::start();
}