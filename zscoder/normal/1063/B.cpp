#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

char a[2222][2222];
ii dist[2222][2222];
int n,m;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
const int INF = int(1e9)+7;

bool valid(int x, int y)
{
	return (x>=0&&x<n&&y>=0&&y<m&&a[x][y]!='*');
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	int r,c; cin>>r>>c; r--; c--;
	int L,R; cin>>L>>R;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			dist[i][j]=mp(INF,INF);
		}
	}
	deque<ii> q;
	dist[r][c]=mp(0,0);
	q.pb(mp(r,c));
	while(!q.empty())
	{
		int x=q.front().fi; int y=q.front().se; q.pop_front();
		for(int i=0;i<2;i++)
		{
			int x2=x+dx[i]; int y2=y+dy[i];
			int newL = dist[x][y].fi; int newR = dist[x][y].se;
			if(valid(x2,y2)&&dist[x2][y2].fi+dist[x2][y2].se>newL+newR)
			{
				if(newL<=L&&newR<=R)
				{
					dist[x2][y2]=mp(newL,newR); q.push_front(mp(x2,y2));
				}
			}
		}
		for(int i=2;i<4;i++)
		{
			int x2=x+dx[i]; int y2=y+dy[i];
			int newL = dist[x][y].fi; int newR = dist[x][y].se;
			if(i==2) newR++;
			else newL++;
			if(valid(x2,y2)&&dist[x2][y2].fi+dist[x2][y2].se>newL+newR)
			{
				if(newL<=L&&newR<=R)
				{
					dist[x2][y2]=mp(newL,newR); q.push_back(mp(x2,y2));
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(dist[i][j].fi<=L&&dist[i][j].se<=R)
			{
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}