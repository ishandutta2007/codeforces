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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int a[1000001];
const int C =1100000;
int cnt[3000001];
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		a[i]--;
	}
	ll ans=0; int idx=0;
	int neg = 0; int pos = 0;
	for(int i=0;i<n;i++)
	{
		ans+=abs(a[i]-i);
		cnt[a[i]-i+C]++;
		if(a[i]-i>0) pos++;
		else neg++;
	}
	ll cur=ans;
	for(int i = 1; i < n; i++)
	{
		ll res = cur;
		//p[n - i] changes
		int v = a[n-i]-(n-i);
		res-=abs(v-(i-1));
		if(v-(i-1)<=0) neg--;
		else pos--;
		res+=abs(v+n-(i-1));
		if(v+n-(i-1)<=0) neg++;
		else pos++;
		cnt[v+C]--;
		cnt[v+n+C]++;
		res+=neg-pos;
		neg+=cnt[i+C];
		pos-=cnt[i+C];
		if(res<ans)
		{
			ans=res;
			idx=i;
		}
		cur=res;
	}
	printf("%lld %d\n",ans,idx);
}