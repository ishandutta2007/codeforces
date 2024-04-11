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

void solve()
{
	int n,k; cin>>n>>k;
	vi a(n);
	bool ex=0;
	vi vec;
	bool exnone=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==k) ex=1;
		else exnone=1;
		if(a[i]>=k) vec.pb(i);
	}
	if(!ex){cout<<"no\n"; return ;}
	if(!exnone){cout<<"yes\n"; return ;} //all already equal to k
	for(int i=0;i+1<vec.size();i++)
	{
		if(vec[i+1]-vec[i]<=2)
		{
			cout<<"yes\n"; return ;
		}
	}
	cout<<"no\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		solve();
	}
}