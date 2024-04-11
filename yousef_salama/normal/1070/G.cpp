#include <bits/stdc++.h>

using namespace std;

const int N=105;

vector<int> ans;
int arr[N],pos[N],h[N];
int cost[N];
int n,m;
int tmp[N],vis[N];

void calc(int x)
{
	cost[x]=tmp[x];
	for(int i=x+1;i<n;i++)
	{
		cost[i]=min(tmp[i],tmp[i]+cost[i-1]);
	}
	for(int i=x-1;i>=0;i--)
	{
		cost[i]=min(tmp[i],tmp[i]+cost[i+1]);
	}
}

void doit(int l,int r)
{
	if(l>r) swap(l,r);
	for(int i=l;i<=r;i++) tmp[i]=0;
}

int can(int x)
{
	ans.clear();
	for(int i=0;i<n;i++) tmp[i]=arr[i];
	for(int i=0;i<m;i++) vis[i]=0;
	calc(x);
	while(true)
	{
		int ok=0;
		for(int i=0;i<m;i++)
		{
			if(cost[pos[i]]+h[i]>=0&&vis[i]==0)
			{
				ok=1;
				doit(pos[i],x); ans.push_back(i);
				vis[i]=1; break;
			}
		}
		if(ans.size()==m) return 1;
		if(!ok) return 0;
		calc(x);
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&pos[i],&h[i]);
		pos[i]--;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(can(i))
		{
			printf("%d\n",i+1);
			for(int j:ans)
				printf("%d ",j+1);
			puts(""); return 0;
		}
	}
	puts("-1");
}