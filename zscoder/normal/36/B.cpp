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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

char ans[555][555];
char a[555][555];
int pw[55];

int n,k; 

void solve(int x1, int y1, int x2, int y2)
{
	int N = x2-x1+1;
	if(N==n)
	{
		for(int i=x1;i<=x2;i++)
		{
			for(int j=y1;j<=y2;j++)
			{
				ans[i][j]=a[i-x1][j-y1];
			}	
		}
		return ;
	}
	int dx = N/n;
	int lx = x1;
	int ly = y1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]=='.')
			{
				solve(lx,ly,lx+dx-1,ly+dx-1);
			}
			ly+=dx;
		}
		lx+=dx; ly=y1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	cin>>n>>k;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	
	pw[0]=1;
	for(int i=1;i<=k;i++) pw[i]=pw[i-1]*n;
	
	for(int i=0;i<pw[k];i++)
	{
		for(int j=0;j<pw[k];j++)
		{
			ans[i][j]='*';
		}
	}
	solve(0,0,pw[k]-1,pw[k]-1);
	for(int i=0;i<pw[k];i++)
	{
		for(int j=0;j<pw[k];j++)
		{
			cout<<ans[i][j];
		}
		cout<<'\n';
	}
}