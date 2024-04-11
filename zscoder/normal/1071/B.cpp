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

int n,m;

bool valid(int x, int y)
{
	return (x>=0&&y>=0&&x<n&&y<m);
}

char a[2011][2011];
int dist[2011][2011];
int dx[2] = {1,0};
int dy[2] = {0,1};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n; m = n; int k; cin>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j]; dist[i][j]=int(1e9);
		}
	}
	deque<ii> dq;
	dist[0][0]=(a[0][0]!='a');
	dq.pb(mp(0,0));
	while(!dq.empty())
	{
		int x=dq.front().fi; int y=dq.front().se; dq.pop_front();
		for(int i=0;i<2;i++)
		{
			int x2=x+dx[i]; int y2=y+dy[i];
			if(valid(x2,y2)&&dist[x2][y2]>=int(1e9))
			{
				int cost = (a[x2][y2]!='a');
				dist[x2][y2]=dist[x][y]+cost;
				if(cost) dq.pb(mp(x2,y2));
				else dq.push_front(mp(x2,y2));
			}
		}
	}
	int mxpos = -1; vector<ii> V;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(dist[i][j]<=k)
			{
				if(i+j>mxpos)
				{
					mxpos=i+j; V.clear(); V.pb(mp(i,j));
				}
				else if(i+j==mxpos)
				{
					V.pb(mp(i,j));
				}
			}
		}
	}
	string s;
	for(int i=0;i<=mxpos;i++) s+='a';
	if(mxpos==-1)
	{
		s+=a[0][0];
		V.pb(mp(0,0));
		mxpos=0;
	}
	for(int i=mxpos;i<n+m-2;i++)
	{
		vector<ii> nxt; char c = 'z'+1;
		for(ii pos:V)
		{
			for(int j=0;j<2;j++)
			{
				int x1=pos.fi+dx[j]; int y1 = pos.se+dy[j];
				if(valid(x1,y1))
				{
					if(a[x1][y1]<c)
					{
						c=a[x1][y1]; nxt.clear(); nxt.pb(mp(x1,y1));
					}
					else if(a[x1][y1]==c)
					{
						nxt.pb(mp(x1,y1));
					}
				}
			}
		}
		sort(nxt.begin(),nxt.end()); nxt.erase(unique(nxt.begin(),nxt.end()),nxt.end());
		s+=c;
		V=nxt;
	}
	cout<<s<<'\n';
}