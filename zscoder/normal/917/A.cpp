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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int dp[5111];
short Amin[5011][5011];
short A[5011][5011];
short Bmin[5011][5011];
short B[5011][5011];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	int n=s.length();
	ll ans = 0;
	for(int i=0;i<n;i++)
	{
		int cur=0; int mn=0;
		for(int j=i;j<n;j++)
		{
			if(s[j]==')')
			{
				cur--;
			}
			else
			{
				cur++;
			}
			mn=min(mn,cur);
			A[i][j]=cur; Amin[i][j]=mn;
		}
		cur=0; mn=0;
		for(int j=i;j<n;j++)
		{
			if(s[j]=='(')
			{
				cur++;
			}
			else
			{
				cur--;
			}
			mn=min(mn,cur);
			B[i][j]=cur; Bmin[i][j]=mn;
		}
	}
	for(int i=0;i<n;i++)
	{
		memset(dp,0,sizeof(dp));
		int op = 0; 
		vi Q;
		Q.pb(i-1);
		for(int j=i;j<n;j++)
		{
			if(s[j]=='?')
			{
				Q.pb(j);
			}
			if(s[j]=='(')
			{
				op++;
			}
			if((j-i)&1)
			{
				int half = (j - i + 1)/2; 
				if(op>half) continue;
				int res = half - op; int pos = -1;
				if(res>=0&&res<int(Q.size()))
				{
					pos = Q[res];
				}
				else continue;
				if(pos>j) continue;
				ii L = mp(Amin[i][pos], A[i][pos]);
				ii R = mp(Bmin[pos+1][j], B[pos+1][j]);
				if(L.se+R.se==0&&L.fi>=0&&L.se+R.fi>=0)
				{
					ans++;
				}
			}
		}
	}
	cout<<ans<<'\n';
}