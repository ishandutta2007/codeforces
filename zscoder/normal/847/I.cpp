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
typedef long double ld; 
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int n,m; 
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool vis[252][252];
ll sc[252][252];
char a[252][252];

bool valid(int x, int y)
{
	return (x>=0&&x<n&&y>=0&&y<m&&a[x][y]!='*');
}

void bfs(int x, int y, ll Q)
{
	vector<ii> VIS;
	queue<pair<ii,int> > q;
	q.push(mp(mp(x,y),(a[x][y]-'A'+1)*Q));
	VIS.pb(mp(x,y)); vis[x][y]=1;
	while(!q.empty())
	{
		int x1 = q.front().fi.fi; int y1 = q.front().fi.se; int v = q.front().se; q.pop();
		sc[x1][y1]+=v;
		if(v>=2)
		{
			for(int i=0;i<4;i++)
			{
				int x2=x1+dx[i]; int y2=y1+dy[i];
				if(valid(x2,y2)&&!vis[x2][y2])
				{
					vis[x2][y2]=1;
					VIS.pb(mp(x2,y2));
					q.push(mp(mp(x2,y2),(v>>1)));
				}
			}
		}
	}
	for(int i=0;i<VIS.size();i++) 
	{
		vis[VIS[i].fi][VIS[i].se]=0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll q,p; cin>>n>>m>>q>>p;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]>='A'&&a[i][j]<='Z')
			{
				bfs(i,j,q);
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			//cout<<sc[i][j]<<' ';
			if(sc[i][j]>p)
			{
				ans++;
			}
		}
		//cout<<'\n';
	}
	cout<<ans<<'\n';
}