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

int a[222222];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	deque<int> dq;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		dq.pb(x);
	}
	for(int i=0;i<n;i++) dq.pb(dq[i]);
	for(int i=0;i+1<2*n;i++)
	{
		if(dq[i]<=dq[i+1]) a[i]=1;
		else a[i]=0;
	}
	vi vec;
	int cnt=0;
	for(int i=0;i<n-1;i++)
	{
		cnt+=a[i];
	}
	if(cnt==n-1) vec.pb(0);
	for(int i=n-1;i+1<2*n;i++)
	{
		cnt-=a[i-(n-1)];
		cnt+=a[i];
		if(cnt==n-1) vec.pb((n-1)-(i-(n-1)));
	}
	sort(vec.begin(),vec.end());
	if(vec.empty()) cout<<-1<<'\n';
	else cout<<vec[0]<<'\n';
}