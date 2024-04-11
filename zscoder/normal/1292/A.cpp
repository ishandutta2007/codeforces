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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[2][111111];
int n,q; 

bool isvalid(int x, int y)
{
	return (x>=0&&x<2&&y>=0&&y<n);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>q;
	ll cnt=0;
	for(int i=0;i<q;i++)
	{
		int x,y; cin>>x>>y; x--; y--;
		for(int j=-1;j<=1;j++)
		{
			if(isvalid(x^1,y+j))
			{
				if(a[x][y]==1&&a[x^1][y+j]==1) cnt--;
			}
		}
		a[x][y]^=1;
		for(int j=-1;j<=1;j++)
		{
			if(isvalid(x^1,y+j))
			{
				if(a[x][y]==1&&a[x^1][y+j]==1) cnt++;
			}
		}
		cout<<(cnt==0?"Yes":"No")<<'\n';
	}
}