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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve()
{
	int n; cin>>n;
	string a[111];
	set<string> S;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		S.insert(a[i]);
	}
	set<string> T;
	for(int i=0;i<n;i++)
	{
		if(T.find(a[i])!=T.end())
		{
			cnt++;
			string ori=a[i];
			bool pos=0;
			for(int j=0;j<4;j++)
			{
				for(int k=0;k<10;k++)
				{
					a[i][j]='0'+k;
					if(S.find(a[i])==S.end())
					{
						pos=1; break;
					}
					a[i]=ori;
				}
				if(pos) break;
			}
		}
		T.insert(a[i]); S.insert(a[i]);
	}
	cout<<cnt<<'\n';
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}