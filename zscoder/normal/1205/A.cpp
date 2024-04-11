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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	if(n%2==0)
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
		vi v;
		for(int i=0;i<n;i++)
		{
			v.pb(i*2+1);
			if(i%2==1) v.back()++;
		}
		for(int i=0;i<n;i++)
		{
			v.pb(((v[i]-1)^1)+1);
		}
		for(int i=0;i<2*n;i++)
		{
			cout<<v[i];
			if(i+1<2*n) cout<<' ';
		}
		cout<<'\n';
		/*
		for(int i=0;i<2*n;i++)
		{
			int sum=0;
			for(int j=i;j<i+n;j++)
			{
				sum+=v[j%(2*n)];
			}
			cout<<sum<<'\n';
		}
		cout<<'\n';
		*/
	}
}