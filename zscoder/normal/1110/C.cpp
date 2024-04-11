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

map<int,int> ma;
int solve(int n)
{
	int k = 1;
	while(n>(1<<k)-1) k++;
	if(n==(1<<k)-1)
	{
		if(ma.find(n)!=ma.end()) return ma[n];
		/*
		int ans=0;
		for(int i=1;i<n;i++)
		{
			ans=max(ans,__gcd((i&n),(i^n)));
		}
		return ans;
		*/
		int smallestfac=-1;
		for(int i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				smallestfac=i; break;
			}
		}
		int ans = 1;
		if(smallestfac!=-1) ans=n/smallestfac;		
		return (ma[n]=ans);
	}
	else
	{
		return (1<<k)-1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		int x; cin>>x; cout<<solve(x)<<'\n';
	}
}