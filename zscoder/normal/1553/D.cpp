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

int nxt[111111][27][2];

void solve()
{
	string s; cin>>s;
	int n=s.length();
	for(int i=0;i<=n+12;i++) 
	{
		for(int j=0;j<26;j++) 
		{
			for(int k=0;k<2;k++)
			{
				nxt[i][j][k]=n+5;
			}
		}
	}
	for(int i=n-2;i>=0;i--)
	{
		for(int j=0;j<26;j++)
		{
			for(int k=0;k<2;k++)
			{
				nxt[i][j][k]=nxt[i+1][j][k];
			}
		}
		nxt[i][s[i+1]-'a'][(i+1)&1]=i+1; //the next guy with parity k
	}
	
	string t; cin>>t;
	int m=t.length();
	int opt[2] = {-1,-1}; //last letter used
	for(int i=0;i<m;i++)
	{
		int c = t[i]-'a';
		int nopt[2] = {n+5,n+5};
		for(int j=0;j<2;j++)
		{
			//what is the optimal letter used?
			if(opt[j]==-1)
			{
				//check if 0 works
				if((s[0]-'a'==c)&&(j==0)) //end at an even square
				{
					nopt[j] = 0; //can go to 0
				}
				else
				{
					nopt[j] = nxt[0][c][j];
				}
			}
			else
			{
				if(opt[j^1]>=n) continue; //die le
				nopt[j] = nxt[opt[j^1]][c][j]; //last parity's optimal, followed by new opt
			}
		}
		opt[0]=nopt[0]; opt[1]=nopt[1];
		//cerr<<i<<": "<<opt[0]<<' '<<opt[1]<<'\n';
	}
	for(int i=0;i<2;i++)
	{
		if(opt[i]<n&&((n-opt[i])&1))
		{
			cout<<"YES\n"; return ;
		}
	}
	cout<<"NO\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}