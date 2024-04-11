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
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int MOD = (1e9 + 7);
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}

const int INF=int(1e9);
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	set<int> L,R,M;
	int ans=1;
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		int mxl = (L.empty()?-INF:(*prev(L.end())));
		int mnr = (R.empty()?INF:(*R.begin()));
		if(s.length()>4) //ACCEPT
		{
			int x; cin>>x;
			if(x>mnr||x<mxl)
			{
				cout<<0<<'\n'; return 0;
			}
			if(x==mxl)
			{
				L.erase(mxl);
				while(!M.empty())
				{
					R.insert((*M.begin())); M.erase(M.begin());
				}
			}
			else if(x==mnr)
			{
				R.erase(mnr);
				while(!M.empty())
				{
					L.insert((*M.begin())); M.erase(M.begin());
				}
			}
			else
			{
				for(auto z:M)
				{
					if(z<x) L.insert(z);
					else if(z>x) R.insert(z);
				}
				ans=mult(ans,2);
				M.clear();
			}
		}
		else //ADD
		{
			int x; cin>>x;
			if(x>mnr)
			{
				R.insert(x);
			}
			else if(x<mxl)
			{
				L.insert(x);
			}
			else
			{
				M.insert(x);
			}
		}
	}
	ans=mult(ans,int(M.size())+1);
	cout<<ans<<'\n';
}