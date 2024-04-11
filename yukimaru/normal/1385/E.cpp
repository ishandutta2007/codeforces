/*********************************************************************
    > File Name: 1385_E.cpp
    > Author: yuki
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=200005;

struct node
{
	int to, tt;
};

int n, m;
vector<node> edge[maxn];
int in[maxn];
vector<int> topov;
bool vis[maxn];

bool topo_sort()
{
	queue<int> q;
	for(int i=1; i<=n; i++)
		if(in[i] == 0) q.push(i);
	while(!topov.empty()) topov.clear();
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		topov.push_back(u);
		for(auto v : edge[u])
			if((v.tt==1) && !(--in[v.to])) q.push(v.to);
	}
/*	for(int i=0; i<(int)topov.size(); i++)
		printf("%d ", topov[i]);
	printf("\n"); */
	if((int)topov.size() == n) return true;
	else return false;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++)
		{
			in[i]=0;
			vis[i]=0;
			edge[i].clear();
		}
		int tt, u, v;
		for(int i=1; i<=m; i++)
		{
			scanf("%d%d%d", &tt, &u, &v);
			edge[u].push_back(node{v, tt});
			if(tt == 1) in[v]++;
		}
		bool f=topo_sort();
		if(!f)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=0; i<(int)topov.size(); i++)
		{
			vis[topov[i]]=1;
			for(auto j : edge[topov[i]])
			{
				if((j.tt==0) && vis[j.to])
					printf("%d %d\n", j.to, topov[i]);
				else printf("%d %d\n", topov[i], j.to);
			}
		}
	}
	return 0;
}