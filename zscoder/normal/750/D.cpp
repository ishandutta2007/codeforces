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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int X = 500;
bool cover[2*X+10][2*X+10];
bool visited[8][2*X+10][2*X+10];
int t[31];
int n;
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, -1, -1, 1, 1};
ii ma[8];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ma[0]=mp(6,7);
	ma[1]=mp(4,5);
	ma[2]=mp(4,6);
	ma[3]=mp(5,7);
	ma[4]=mp(1,2);
	ma[5]=mp(1,3);
	ma[6]=mp(0,2);
	ma[7]=mp(0,3);
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>t[i];
	}
	queue<pair<ii,int> > q;
	for(int i = X; i < X + t[0]; i++)
	{
		cover[X][i]=1;
	}
	q.push(mp(mp(X,X+t[0]-1),0));
	for(int i = 1; i < n; i++)
	{
		vector<pair<int,ii> > visit;
		int cnter = q.size();
		ll iter=0;
		//cerr<<i<<' '<<cnter<<'\n';
		while(iter<cnter)
		{
			ii tmp = q.front().fi; int dir = q.front().se;
			int x = tmp.fi; int y = tmp.se;
			//cerr<<i<<' '<<x-X<<' '<<y-X<<' '<<dx[dir]<<' '<<dy[dir]<<'\n';
			q.pop();
			int dir1=ma[dir].fi;
			int dir2=ma[dir].se;
			for(int j = 1; j <= t[i]; j++)
			{
				cover[j*dx[dir1]+x][j*dy[dir1]+y]=1;
			}
			int x2=x+t[i]*dx[dir1];
			int y2=y+t[i]*dy[dir1];
			for(int j = 1; j <= t[i]; j++)
			{
				cover[j*dx[dir2]+x][j*dy[dir2]+y]=1;
			}
			int x3=x+t[i]*dx[dir2];
			int y3=y+t[i]*dy[dir2];
			if(!visited[dir1][x2][y2])
			{
				visited[dir1][x2][y2]=1;
				visit.pb(mp(dir1,mp(x2,y2)));
				q.push(mp(mp(x2,y2),dir1));
			}
			if(!visited[dir2][x3][y3])
			{
				visited[dir2][x3][y3]=1;
				visit.pb(mp(dir2,(mp(x3,y3))));
				q.push(mp(mp(x3,y3),dir2));
			}
			iter++;
		}
		for(int j =0; j < visit.size(); j++)
		{
			visited[visit[j].fi][visit[j].se.fi][visit[j].se.se]=0;
		}
	}
	ll ans=0;
	for(int i = 0; i < 2*X+10; i++)
	{
		for(int j = 0; j < 2*X+10; j++)
		{
			if(cover[i][j]) 
			{
				//cerr<<i-X<<' '<<j-X<<'\n';
				ans++;
			}
		}
	}
	cout<<ans;
}