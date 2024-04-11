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

int largestfact[555555];
int cnt=1;
int ans[555555];
int n; 

void relax(int x)
{
	for(int i=2*x;i<=n;i+=x)
	{
		if(largestfact[i]==x)
		{
			ans[++cnt]=x;
		}
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j+=i)
		{
			if(j!=i) largestfact[j]=max(largestfact[j],i);
		}
	}
	for(int i=1;i<=n;i++) relax(i);
	for(int i=2;i<=n;i++)
	{
		cout<<ans[i];
		if(i+1<=n) cout<<' ';
	}
	cout<<'\n';
}