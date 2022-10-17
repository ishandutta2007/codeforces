#include<bits/stdc++.h>
using namespace std;

const int N=5e6+1e3+7;

int n,a[N],cnt[N];

vector<int>pos[N];

int v[N][2],use[N],vis[N],id[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),pos[a[i]].push_back(i);
	vector<int>last;
	for(int i=1;i<=5000000;i++)
	{
		if(pos[i].size()>=4)
		{
			puts("YES");
			printf("%d %d %d %d\n",pos[i][0],pos[i][1],pos[i][2],pos[i][3]);
			return 0;
		}
		else if(pos[i].size()>=2)
		{
			if(!last.size())
				last=pos[i];
			else
			{
				puts("YES");
				printf("%d %d ",last[0],pos[i][0]);
				printf("%d %d \n",last[1],pos[i][1]);
				return 0;
			}
		}
	}
	vector<int>b;
	if(last.size())
	{
		for(auto x:last)
			use[x]=1;
		int val=a[last[0]]*2;
		b.push_back(val>>1);
		id[0]=last[0];
		for(int i=1;i<=n;i++)
			if(!use[i])
			{
				if(a[i]>val)
					continue;
				if(vis[val-a[i]])
				{
					puts("YES");
					printf("%d %d %d %d\n",last[0],last[1],vis[val-a[i]],i);
					return 0;
				}
				vis[a[i]]=i;
			}
	}
	for(int i=1;i<=n;i++)
		if(!use[i])
			b.push_back(a[i]),id[b.size()-1]=i;
	int t=b.size();
	for(int i=0;i<t;i++)
		for(int j=i+1;j<t;j++)
		{
			int x=b[i]+b[j];
			if(!v[x][0])
			{
				v[x][0]=id[i];
				v[x][1]=id[j];
			}
			else
			{
				puts("YES");
				printf("%d %d %d %d\n",v[x][0],v[x][1],id[i],id[j]);
				return 0;
			}
		}
	puts("NO");
}