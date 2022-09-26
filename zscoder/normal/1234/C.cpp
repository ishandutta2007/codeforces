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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

string a[2];
	
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		cin>>a[0];
		cin>>a[1];
		int x=0; int y=0; int dir=0; bool p=1;
		set<ii> S;
		while(x<2&&y<n)
		{
			int pos=a[x][y]-'0';
			if(S.find({x,y})!=S.end())
			{
				p=0; break;
			}
			S.insert({x,y});
			int ty=0;
			if(pos>=3) ty=1;
			if(ty==0)
			{
				if(dir!=0)
				{
					p=0; break;
				}
				y++;
			}
			else
			{
				if(x==0)
				{
					if(dir==0)
					{
						x++; dir=1;
					}
					else
					{
						y++; dir=0;
					}
				}
				else
				{
					if(dir==1)
					{
						y++; dir=0;
					}
					else
					{
						x--; dir=1;
					}
				}
			}
			
		}
		if(!(x==1&&y>=n)) p=0;
		if(p) cout<<"YES\n";
		else cout<<"NO\n";
	}
}