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

deque<bool> dq[311][311];
deque<bool> fin[311][311];
vector<pair<ii,ii> > moves;
vector<pair<ii,ii> > moves2;
void add_move(int x1, int y1, int x2, int y2, bool mode=0)
{
	assert(!dq[x1][y1].empty());
	//cerr<<"ADD "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<'\n';
	assert(x1==x2||y1==y2);
	assert(x1!=x2||y1!=y2);
	int x = dq[x1][y1].back(); dq[x1][y1].pop_back();
	dq[x2][y2].push_front(x); 
	if(mode) 
	{
		moves.pb(mp(mp(x2,y2),mp(x1,y1)));
	}
	else
	{
		moves.pb(mp(mp(x1,y1),mp(x2,y2)));
	}
}

void out()
{
	cout<<moves.size()<<'\n';
	for(int i=0;i<moves.size();i++)
	{
		cout<<moves[i].fi.fi+1<<' '<<moves[i].fi.se+1<<' '<<moves[i].se.fi+1<<' '<<moves[i].se.se+1<<'\n';
	}
}

int n,m; 
void solve(int mode=0)
{
	while(!dq[0][m-1].empty())
	{
		add_move(0,m-1,0,0,mode);
	}
	while(!dq[n-1][0].empty())
	{
		add_move(n-1,0,n-1,m-1,mode);
	}
	for(int i=1;i<m-1;i++)
	{
		while(!dq[0][i].empty())
		{
			add_move(0,i,0,0,mode);
		}
		while(!dq[n-1][i].empty())
		{
			add_move(n-1,i,n-1,m-1,mode);
		}
	}
	for(int i=1;i<n-1;i++)
	{
		while(!dq[i][0].empty())
		{
			add_move(i,0,0,0,mode);
		}
		while(!dq[i][m-1].empty())
		{
			add_move(i,m-1,n-1,m-1,mode);
		}
	}
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<m-1;j++)
		{
			while(!dq[i][j].empty())
			{
				int x=dq[i][j].back();
				if(x) add_move(i,j,n-1,j,mode);
				else add_move(i,j,0,j,mode);
			}
		}
	}
	for(int i=0;i<m-1;i++)
	{
		while(!dq[0][i].empty())
		{
			int x=dq[0][i].back();
			if(!x) add_move(0,i,0,m-1,mode);
			else add_move(0,i,n-1,0,mode);
		}
	}
	for(int i=1;i<m;i++)
	{
		while(!dq[n-1][i].empty())
		{
			int x=dq[n-1][i].back();
			if(!x) add_move(n-1,i,0,m-1,mode);
			else add_move(n-1,i,n-1,0,mode);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	int sum[2]={0,0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			string s; cin>>s;
			for(char c:s)
			{
				sum[c-'0']++;
				dq[i][j].pb(c-'0');
			}
			//dqtmp[i][j]=dq[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			string s; cin>>s;
			for(char c:s)
			{
				sum[c-'0']--;
				fin[i][j].pb(c-'0');
			}
		}
	}
	assert(sum[0]==0&&sum[1]==0);
	solve();
	moves2=moves; moves.clear();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			dq[i][j]=fin[i][j];
			reverse(dq[i][j].begin(),dq[i][j].end());
		}
	}
	solve(1);
	reverse(moves2.begin(),moves2.end());
	for(auto x:moves2) moves.pb(x);
	reverse(moves.begin(),moves.end());
	out();
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			dq[i][j]=dqtmp[i][j];
			for(int v:dq[i][j])
			{
				cout<<v;
			}
			cout<<' ';
		}
		cout<<'\n';
	}
	int ms=moves.size();
	for(int i=0;i<ms;i++)
	{
		auto x = moves[i];
		add_move(x.fi.fi,x.fi.se,x.se.fi,x.se.se);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			assert(dq[i][j]==fin[i][j]);
		}
		//cout<<'\n';
	}
	*/
}