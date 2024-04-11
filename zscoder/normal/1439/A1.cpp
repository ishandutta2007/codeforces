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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

string a[111];

vector<vector<int> > moves;
map<int,int> dp[4][4];

void perform(vector<int> v)
{
	for(int i=0;i<6;i+=2)
	{
		int x=v[i]; int y=v[i+1];
		if(a[x][y]=='1') a[x][y]='0';
		else a[x][y]='1';
	}
}

int b[5][5];

void perform2(vector<int> v)
{
	for(int i=0;i<6;i+=2)
	{
		int x=v[i]; int y=v[i+1];
		if(b[x][y]==1) b[x][y]=0;
		else b[x][y]=1;
	}
}

int getmask(int X, int Y)
{
	int mask=0;
	for(int i=0;i<X;i++)
	{
		for(int j=0;j<Y;j++)
		{	
			mask*=2; mask+=b[i][j];
		}
	}
	return mask;
}

bool visited[(1<<17)];

void dfs(int X, int Y)
{
	memset(visited,0,sizeof(visited));
	dp[X][Y][0]=0;
	vector<vector<int> > S;
	for(int i=0;i<X-1;i++)
	{
		for(int j=0;j<Y-1;j++)
		{
			vector<ii> lul;
			for(int z=0;z<2;z++)
			{
				for(int w=0;w<2;w++)
				{
					lul.pb({i+z,j+w});
				}
			}
			for(int z=0;z<4;z++)
			{
				vector<int> nw;
				for(int w=0;w<4;w++)
				{
					if(w==z) continue;
					nw.pb(lul[w].fi);
					nw.pb(lul[w].se);
				}
				S.pb(nw);
			}
		}
	}
	//cerr<<X<<' '<<Y<<' '<<S.size()<<'\n';
	queue<int> q;
	q.push(0); visited[0]=1;
	while(!q.empty())
	{
		int mask=q.front(); 
		int tmpmask=mask; q.pop();
		//cerr<<"Visited "<<X<<' '<<Y<<' '<<mask<<'\n';
		for(int i=X-1;i>=0;i--)
		{
			for(int j=Y-1;j>=0;j--)
			{
				b[i][j]=(tmpmask&1);
				tmpmask>>=1;
			}
		}
		for(int i=0;i<S.size();i++)
		{
			perform2(S[i]);
			int newmask = getmask(X,Y);
			if(!visited[newmask])
			{
				visited[newmask]=1;
				dp[X][Y][newmask]=dp[X][Y][mask]^(1<<i);
				q.push(newmask);
			}
			perform2(S[i]);
		}
	}
}

void brute(int x1, int y1, int x2, int y2)
{
	vector<vector<int> > S;
	for(int i=x1;i<x2;i++)
	{
		for(int j=y1;j<y2;j++)
		{
			vector<ii> lul;
			for(int z=0;z<2;z++)
			{
				for(int w=0;w<2;w++)
				{
					lul.pb({i+z,j+w});
				}
			}
			for(int z=0;z<4;z++)
			{
				vector<int> nw;
				for(int w=0;w<4;w++)
				{
					if(w==z) continue;
					nw.pb(lul[w].fi);
					nw.pb(lul[w].se);
				}
				S.pb(nw);
			}
		}
	}
	int X = x2-x1+1; int Y=y2-y1+1;
	int area = (y2-y1+1)*(x2-x1+1);
	int mask=0;
	for(int i=x1;i<=x2;i++)
	{
		for(int j=y1;j<=y2;j++)
		{
			mask*=2; mask+=a[i][j]-'0';
		}
	}
	int i = dp[X][Y][mask];
	for(int j=0;j<S.size();j++)
	{
		if(i&(1<<j))
		{
			moves.pb(S[j]);
			perform(S[j]);
		}
	}
	return ;
}

void solve()
{
	moves.clear();
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i+=2)
	{
		int x1 = i; int x2 = i+1;
		if(i+2==n-1) x2=i+2;
		for(int j=0;j<m;j+=2)
		{
			int y1 = j; int y2 = j+1;
			if(j+2==m-1) y2=j+2;
			//cerr<<"BRUTE "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<'\n';
			brute(x1,y1,x2,y2);
		}
	}
	cout<<moves.size()<<'\n';
	for(auto X:moves)
	{
		for(int i=0;i<X.size();i++)
		{
			cout<<X[i]+1<<' ';
		}
		cout<<'\n';
	}
	
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=2;i<=3;i++)
	{
		for(int j=2;j<=3;j++) dfs(i,j);
	}
	int t; cin>>t;
	while(t--) solve();
}