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

string a[222];
int n,m; 

bool valid(int x, int y)
{
	return (x>=0&&x<n&&y>=0&&y<m&&a[x][y]!='.');
}

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	char c;
	cin>>n>>m>>c;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	set<char> lul;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]!=c) continue;
			for(int dir=0;dir<4;dir++)
			{
				int x2=i+dx[dir]; int y2=j+dy[dir];
				if(valid(x2,y2)) 
				{
					cerr<<i<<' '<<j<<' '<<x2<<' '<<y2<<' '<<a[x2][y2]<<'\n';
					lul.insert(a[x2][y2]);
				}
			}
		}
	}
	lul.erase(c);
	cout<<lul.size()<<'\n';
}