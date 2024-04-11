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
typedef long double ld; 
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int a[111];
bool used[1111111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		used[a[i]]=1;
	}
	int cnt=n;
	for(int i=1;i<=1010000;i++)
	{
		if(cnt<25&&!used[i])
		{
			used[i]=1;
			cnt++;
		}
	}
	int mx=0;
	for(int i=1;i<=1010000;i++)
	{
		if(used[i]) mx=max(mx,i);
	}
	cout<<mx-25<<'\n';
}