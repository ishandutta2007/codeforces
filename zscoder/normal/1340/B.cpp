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

const string digits[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int bit[10];
int a[2222];
bool dp[2222][2666];

int conv(string s)
{
	int x=0;
	for(int i=0;i<s.length();i++)
	{
		x*=2; x+=s[i]-'0';
	}
	return x;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	for(int i=0;i<10;i++) bit[i]=conv(digits[i]);
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		a[i]=conv(s);
	}
	dp[n][0]=1;
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<=k;j++)
		{
			if(dp[i][j])
			{
				for(int d=0;d<10;d++)
				{
					if((a[i-1]&bit[d])==a[i-1])
					{
						dp[i-1][j+(__builtin_popcount(a[i-1]^bit[d]))]=1;
					}
				}
			}
		}
	}
	if(!dp[0][k])
	{
		cout<<-1<<'\n';
		return 0;
	}
	string ans;
	int curk=k;
	for(int i=0;i<n;i++)
	{
		for(int d=9;d>=0;d--)
		{
			if((a[i]&bit[d])==a[i])
			{
				int diff = __builtin_popcount(a[i]^bit[d]);
				if(curk>=diff&&dp[i+1][curk-diff])
				{
					curk-=diff;
					ans+="$";
					ans[i]='0'+d;
					break;
				}
			}
		}
	}
	cout<<ans<<'\n';
}