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

char a[55][55];
map<char,int> ma;
const string s="RW";

void solve()
{
	int n,m; cin>>n>>m;
	set<int> ty[2];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) 
		{
			cin>>a[i][j];
			if(a[i][j]!='.')
			{
				ty[ma[a[i][j]]].insert((i+j)&1);
			}
		}
	}
	if(ty[0].size()>=2){cout<<"NO\n"; return ;}
	if(ty[1].size()>=2){cout<<"NO\n"; return ;}
	if(ty[0].size()>0&&ty[1].size()>0&&(*ty[0].begin())==(*ty[1].begin())){cout<<"NO\n"; return ;}
	int col[2] = {0,1};
	if(ty[0].size()>0&&(*ty[0].begin())==1){col[0]=1;col[1]=0;}
	if(ty[1].size()>0&&(*ty[1].begin())==0){col[0]=1;col[1]=0;}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) 
		{
			for(int k=0;k<2;k++)
			{
				if(col[k]==((i+j)&1)) {a[i][j]=s[k]; break;}
			}
		}
	}
	cout<<"YES\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) 
		{
			cout<<a[i][j];
		}
		cout<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ma['R']=0; ma['W']=1;
	int t; cin>>t;
	while(t--) solve();
}