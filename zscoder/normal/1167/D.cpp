#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

int ans[222222];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int n; cin>>n; string s; cin>>s;
	int H[2]={0,0};
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
		{
			if(H[0]<H[1])
			{
				ans[i]=0;
				H[0]++;
			}
			else
			{
				ans[i]=1;
				H[1]++;
			}
		}
		else
		{
			if(H[0]>H[1])
			{
				ans[i]=0;
				H[0]--;
			}
			else
			{
				ans[i]=1;
				H[1]--;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
	}
	cout<<'\n';
}