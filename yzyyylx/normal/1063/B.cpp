#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 2010
#define M 
using namespace std;

ll m,n,cnt[130],r,c,x,y,tt,sy[N][N],vis[N*N],ans;
bool mm[N][N];
char str[N];
struct Node
{
	P pos;
	ll size,x,y;
	set<P>to;
}node[N*N];
set<P>::iterator it;
queue<ll>que;

int main()
{
	ll i,j,t,p,q,a,b;
	cin>>m>>n;
	cin>>r>>c>>x>>y;
	for(i=1;i<=m;i++)
	{
		scanf("%s",str+1);
		for(j=1;j<=n;j++)
		{
			mm[i][j]=(str[j]=='*');
			if(!mm[i][j])
			{
				if(i==1 || mm[i-1][j])
				{
					node[++tt].pos=mp(i,j);
					node[tt].size=1;
					sy[i][j]=tt;
				}
				else
				{
					sy[i][j]=sy[i-1][j];
					node[sy[i-1][j]].size++;
				}
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<n;j++)
		{
			if(!mm[i][j] && !mm[i][j+1])
			{
				node[sy[i][j]].to.insert(mp(sy[i][j+1],1));
				node[sy[i][j+1]].to.insert(mp(sy[i][j],0));
			}
		}
	}
	t=sy[r][c];
	vis[t]=1;
	que.push(t);
	for(;!que.empty();)
	{
		q=que.front();
		que.pop();
		ans+=node[q].size;
		for(it=node[q].to.begin();it!=node[q].to.end();it++)
		{
			p=(*it).fi;
			if(vis[p]) continue;
			vis[p]=1;
			node[p].x=node[q].x;
			node[p].y=node[q].y;
			if((*it).se) node[p].y++;
			else node[p].x++;
			if(node[p].x>x || node[p].y>y) continue;
			que.push(p);
		}
	}
	cout<<ans;
}