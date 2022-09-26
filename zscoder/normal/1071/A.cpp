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

int x[1111111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll a,b; cin>>a>>b;
	ll s=a+b;
	ll sum=0; ll id=0;
	for(int i=1;i<=1000000;i++)
	{
		if(sum+i<=s)
		{
			sum+=i;
		}
		else break;
		id=i;
	}
	for(int i=id;i>=1;i--)
	{
		if(a>=i)
		{
			a-=i; x[i]=1;
		}
	}
	vi L,R;
	for(int i=1;i<=id;i++)
	{
		if(x[i]) L.pb(i);
		else R.pb(i);
	}
	cout<<L.size()<<'\n';
	for(int i=0;i<L.size();i++)
	{
		cout<<L[i];
		if(i+1<L.size()) cout<<' ';
	}
	cout<<'\n';
	cout<<R.size()<<'\n';
	for(int i=0;i<R.size();i++)
	{
		cout<<R[i];
		if(i+1<R.size()) cout<<' ';
	}
	cout<<'\n';
}