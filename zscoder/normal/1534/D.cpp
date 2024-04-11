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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int d[2222][2222];
int n; 
bool used[2222];

void query(int u)
{	
	if(used[u]) return ;
	used[u]=1;
	cout<<"? "<<u+1<<'\n'; fflush(stdout);
	for(int i=0;i<n;i++)
	{
		cin>>d[u][i];
		d[i][u]=d[u][i];
	}	
}

int main()
{
	memset(d,-1,sizeof(d));
	cin>>n;
	query(0);
	vi A[2];
	for(int i=1;i<n;i++)
	{
		A[d[0][i]&1].pb(i);
	}
	if(A[0].size()>A[1].size()) swap(A[0],A[1]);
	for(int v:A[0]) query(v);
	set<ii> edges;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(d[i][j]==1) edges.insert({i,j});
		}
	}
	cout<<"!\n";
	fflush(stdout);
	for(auto x:edges)
	{
		cout<<x.fi+1<<' '<<x.se+1<<'\n';
		fflush(stdout);
	}
}