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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<string> vec;
vector<vi> dist;
vector<vi> dist2;
int n,m; 
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

bool isvalid(int x, int y)
{
	return (x>=0&&x<n&&y>=0&&y<m);
}

const int INF = int(1e9);

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m; vec.resize(n+2);
	vec[0]=string(m+2,'.');
	for(int i=1;i<=n;i++)
	{
		string s; cin>>s; s="."+s+".";
		vec[i]=s;
	}
	vec[n+1]=vec[0];
	dist.resize(n+2);
	for(int i=0;i<=n+1;i++) dist[i].assign(m+2,int(1e9));
	n+=2; m+=2;
	queue<ii> q;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(vec[i][j]=='.')
			{
				dist[i][j]=0;
				q.push({i,j});
			}
		}
	}
	while(!q.empty())
	{
		int x=q.front().fi; int y=q.front().se; q.pop();
		for(int dir=0;dir<8;dir++)
		{
			int x2=x+dx[dir]; int y2=y+dy[dir];
			if(isvalid(x2,y2)&&dist[x2][y2]>=INF)
			{
				dist[x2][y2]=dist[x][y]+1;
				q.push({x2,y2});
			}
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<dist[i][j]<<' ';
		}
		cout<<'\n';
	}
	*/
	int lo=0; int hi=int(1e6)+10;
	int ans=0;
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		dist2.resize(n);
		for(int i=0;i<n;i++) dist2[i].assign(m,int(1e9));
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<m;j++)
			{
				if(dist[i][j]>mid) 
				{
					dist2[i][j]=0; q.push({i,j});
				}
			}
		}
		while(!q.empty())
		{
			int x=q.front().fi; int y=q.front().se; q.pop();
			for(int dir=0;dir<8;dir++)
			{
				int x2=x+dx[dir]; int y2=y+dy[dir];
				if(isvalid(x2,y2)&&vec[x2][y2]=='X'&&dist2[x2][y2]>=INF)
				{
					dist2[x2][y2]=dist2[x][y]+1;
					q.push({x2,y2});
				}
			}
		}
		/*
		cerr<<"MID: "<<mid<<'\n';
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cerr<<dist2[i][j]<<' ';
			}
			cerr<<'\n';
		}
		*/
		bool pos=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(vec[i][j]=='X'&&dist2[i][j]>mid)
				{
					pos=0; break;
				}
			}
			if(!pos) break;
		}
		if(pos)
		{
			ans=mid;
			lo=mid+1;
		}
		else hi=mid-1;
	}
	n-=2; m-=2;
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(dist[i][j]>ans)
			{
				cout<<'X';
			}
			else cout<<'.';
		}
		cout<<'\n';
	}
}