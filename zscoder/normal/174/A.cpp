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

ld a[222];
ld b[222];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ld x; cin>>n>>x; ld sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; sum+=a[i];
	}
	ld avg = (sum+x)/ld(n);
	for(int i=0;i<n;i++)
	{
		b[i]=avg-a[i];
		if(b[i]<=-ld(1e-10)) {cout<<-1<<'\n'; return 0;}
	}
	for(int i=0;i<n;i++)
	{
		cout<<fixed<<setprecision(10)<<b[i]<<'\n';
	}
}