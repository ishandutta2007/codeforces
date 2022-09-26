#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n,m;
string a[1111];
bool vis[1111][1111];

bool valid(int x, int y)
{
	return (x>=0&&x<n&&y>=0&&y<m&&a[x][y]!='.'&&(!vis[x][y]));
}

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	int emptyrow=0;
	for(int i=0;i<n;i++)
	{
		int l=int(1e9); int r=0;
		int cnt=0;
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='#')
			{
				l=min(l,j); r=max(r,j);
				cnt++;
			}
		}	
		if(cnt>0&&cnt!=r-l+1)
		{
			cout<<-1<<'\n'; return 0;
		}
		if(cnt==0) emptyrow++;
	}
	int emptycol=0;
	for(int j=0;j<m;j++)
	{
		int l=int(1e9); int r=0;
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(a[i][j]=='#')
			{
				l=min(l,i); r=max(r,i);
				cnt++;
			}
		}	
		if(cnt>0&&cnt!=r-l+1)
		{
			cout<<-1<<'\n'; return 0;
		}
		if(cnt==0) emptycol++;
	}
	if(emptycol>0&&emptyrow==0)
	{
		cout<<-1<<'\n'; return 0;
	}
	if(emptycol==0&&emptyrow>0)
	{
		cout<<-1<<'\n'; return 0;
	}
	int cc=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(valid(i,j))
			{
				cc++;
				queue<ii> q;
				q.push({i,j});
				while(!q.empty())
				{
					int x=q.front().fi; int y=q.front().se; q.pop();
					for(int dir=0;dir<4;dir++)
					{
						int x2=x+dx[dir]; int y2=y+dy[dir];
						if(valid(x2,y2))
						{
							q.push({x2,y2}); vis[x2][y2]=1;
						}
					}
				}
			}
		}
	}
	cout<<cc<<'\n';
}