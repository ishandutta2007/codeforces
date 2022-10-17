#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,a[N],vis[N],pos[N];

int tot;

vector<int>c[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>ans;

void dfs(int x)
{
	vis[x]=1;
	c[tot].push_back(x);
	if(!vis[a[x]])
		dfs(a[x]);
}

void move(int x,int y)
{
	x=abs(x),y=abs(y);
	swap(a[pos[x]],a[pos[y]]);
	swap(pos[x],pos[y]);
	ans.push_back(make_pair(pos[x],pos[y]));
	a[pos[x]]*=-1,a[pos[y]]*=-1;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),pos[a[i]]=i;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			++tot,dfs(i);
	if(tot>1)
	{
		for(int i=1;i+1<=tot;i+=2)
		{
			int x=i,y=i+1;
			move(c[x][0],c[y][0]);
			swap(c[x][0],c[y][0]);
			x=c[x][0],y=c[y][0];
			while(1)
			{
				if(abs(x)!=pos[abs(y)])
				{
					int t=a[x];
					move(x,a[abs(x)]);
					x=t;
				}
				else if(abs(y)!=pos[abs(x)])
				{
					int t=a[abs(y)];
					move(y,a[abs(y)]);
					y=t;
				}
				else
					break;
			}
			move(x,y);
		}
		if(tot&1)
		{
			int p=-1;
			for(int i=1;i<=n;i++)
				if(a[i]==i)
				{
					p=i;
					break;
				}
			move(p,c[tot][0]);
			int x=p,y=c[tot][0];
			while(1)
			{
				if(abs(x)!=pos[abs(y)])
				{
					int t=a[abs(x)];
					move(x,a[abs(x)]);
					x=-t;
				}
				else if(abs(y)!=pos[abs(x)])
				{
					int t=a[abs(y)];
					move(y,a[abs(y)]);
					y=-t;
				}
				else
					break;
			}
			move(x,y);
		}
	}
	else
	{
		int x=a[1],y=a[x];
		move(x,y);
		x=-x,y=-y;
		int res=n-2;
		while(1)
		{
			if(res==1)
				break;
			if(pos[abs(x)]!=abs(x))
			{
				int t=a[abs(x)];
				move(x,a[abs(x)]);
				x=-t;
				res--;
			}
			else if(pos[abs(y)]!=abs(y))
			{
				int t=a[abs(y)];
				move(y,a[abs(y)]);
				y=-t;
				res--;
			}
		}
		vector<int>v;
		for(int i=1;i<=n;i++)
			if(a[i]!=i)
				v.push_back(a[i]);
		assert(v.size()==3);
		int flag=1;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++)
					for(int x=0;x<3;x++)
						for(int y=0;y<3;y++)
							for(int z=0;z<3;z++)
							{
								if(!flag)
									continue;
								if(i==x||j==y||k==z)
									continue;
								move(v[i],v[x]);
								move(v[j],v[y]);
								move(v[k],v[z]);
								int ok=1;
								for(int i=1;i<=n;i++)
									ok&=a[i]==i;
								if(!ok)
								{
									move(v[k],v[z]);
									move(v[j],v[y]);
									move(v[i],v[x]);
									for(int t=0;t<6;t++)
										ans.pop_back();
								}
								else
								{
									flag=1;
								}
							}
	}
	printf("%d\n",ans.size());
	for(auto x:ans)
		printf("%d %d\n",x.first,x.second);
}