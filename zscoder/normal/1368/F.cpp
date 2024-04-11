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

int n,k;
int ans;
int a[1111];
int main()
{
	cin>>n;
	if(n<=3)
	{
		cout<<0<<'\n'; fflush(stdout); return 0;
	}
	ans=0;
	for(int i=2;i<=n;i++)
	{
		int res = (n/i-1)*(i-1)+max(0,(n%i)-1);
		if(res>ans)
		{
			ans=res; k=i;
		}
	}
	while(1)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=a[i];
		}
		if(sum>=ans){cout<<0<<'\n'; fflush(stdout); break;}
		vi vec; int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(i%k==0) continue;
			if(cnt>=k) break;
			if(!a[i])
			{
				vec.pb(i);
				cnt++; a[i]=1;
			}
		}
		cout<<vec.size()<<' ';
		for(int i=0;i<vec.size();i++)
		{
			cout<<vec[i]+1;
			if(i+1<vec.size()) cout<<' ';
		}
		cout<<'\n';
		fflush(stdout);
		int x; cin>>x;
		x--;
		for(int i=x;i<x+k;i++)
		{
			a[i%n]=0;
		}
	}
}