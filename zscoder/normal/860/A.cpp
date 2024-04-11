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
typedef long double ld; 
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int dp[3111];
int par[3111];

bool isvow(char c)
{
	return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	int n=s.length();
	dp[0] = 0;
	memset(par,-1,sizeof(par));
	for(int i=1;i<n;i++)
	{
		string cur;
		dp[i] = dp[i-1]+1;
		par[i] = i - 1;
		cur+=s[i];
		for(int j=i-1;j>=0;j--)
		{
			cur+=s[j];
			if(cur.length()>=3)
			{
				char x[3];
				for(int z=0;z<3;z++)
				{
					x[z] = cur[int(cur.length()) - z - 1];
				}
				if(x[0]==x[1]&&x[1]==x[2])
				{
					
				}
				else
				{
					if(isvow(x[0])||isvow(x[1])||isvow(x[2]))
					{
						
					}
					else
					{
						break;
					}
				}
			}
			if(j==0)
			{
				dp[i]=0;
				par[i]=-1;
			}
			else
			{
				if(dp[j-1]+1<dp[i])
				{
					dp[i]=dp[j-1]+1;
					par[i]=j-1;
				}
			}
		}
	}
	int cur=n-1;
	vector<string> vec;
	while(cur>=0)
	{
		int p = par[cur];
		vec.pb(s.substr(p+1,cur-p));
		cur = p;
	}
	for(int i=int(vec.size())-1;i>=0;i--)
	{
		cout<<vec[i];
		if(i>0) cout<<' ';
	}
	cout<<'\n';
}