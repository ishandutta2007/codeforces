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

ll b[222222];
ll a[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	ll curmx=0;
	for(int i=0;i<n;i++)
	{
		a[i]=b[i]+curmx;
		curmx=max(curmx,a[i]);
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}