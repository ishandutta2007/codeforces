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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int life[1011][1011];
int a[1011][1011];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int n,m,t; 

bool valid(int x, int y)
{
	return (x>=0&&x<n&&y>=0&&y<m);
}

bool added[1011][1011];
ii Q[2][2011111]; //dk if it will explode in side lmao
int siz[2];
int cur=0;

void look(int x, int y)
{
	for(int d=0;d<4;d++)
	{
		int x2=x+dx[d]; int y2=y+dy[d];
		if(valid(x2,y2))
		{
			if(!added[x2][y2])
			{
				if(life[x2][y2]==-1)
				{
					Q[cur][siz[cur]]={x2,y2};
					siz[cur]++;
					added[x2][y2]=1;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m>>t;
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		for(int j=0;j<m;j++)
		{
			a[i][j]=s[j]-'0';
		}
	}
	memset(life,-1,sizeof(life));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int d=0;d<4;d++)
			{
				int x=i+dx[d]; int y=j+dy[d];
				if(valid(x,y)&&(a[x][y]==a[i][j]))
				{
					life[i][j]=1; //for t<life[i][j], the cell color never changes
				}
			}
			if(life[i][j]!=-1) look(i,j);
		}
	}
	int val=2;
	while(siz[cur]>0)
	{
		int pre=cur;
		cur^=1;
		siz[cur]=0; 
		for(int i=0;i<siz[pre];i++)
		{
			int x=Q[pre][i].fi; int y=Q[pre][i].se;
			if(life[x][y]!=-1) continue;
			life[x][y]=val;
			look(x,y);
		}
		for(int i=0;i<siz[cur];i++)
		{
			added[Q[cur][i].fi][Q[cur][i].se]=0;
		}
		val++;
	}
	while(t--)
	{
		int x,y; ll p; cin>>x>>y>>p;
		x--; y--;
		if(life[x][y]==-1)
		{
			cout<<a[x][y]<<'\n';
		}
		else
		{
			if(p<life[x][y]) cout<<a[x][y]<<'\n';
			else
			{
				p-=life[x][y]-1;
				p%=2;
				cout<<(a[x][y]^p)<<'\n';
			}
		}
	}
}