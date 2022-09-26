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
int a[211111];
int t[411111];

const int INF = int(1e9)+7;
vector<vi> ans;
int n;

void modify(int p, int va) 
{  // set value at position p
  for (t[p += (n+1)] = va; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = INF;
  for (l += n+1, r += n+1; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res, t[l++]);
    if (r&1) res = min(res, t[--r]);
  }
  return res;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<411111;i++) t[i]=INF;
	for(int i=0;i<n;i++)
	{
		int lo = 0; int hi = int(ans.size()) - 1;
		int res = int(ans.size());
		while(lo<=hi)
		{
			int mid=(lo+hi)>>1;
			int v = query(0,mid+1);
			//cerr<<v<<' '<<mid<<' '<<i<<' '<<a[i]<<'\n';
			if(v<a[i])
			{
				res=mid;
				hi=mid-1;
			}
			else
			{
				lo=mid+1;
			}
		}
		if(res>=int(ans.size()))
		{
			ans.pb(vi());
			ans.back().pb(a[i]);
		}
		else
		{
			ans[res].pb(a[i]);
		}
		//cerr<<res<<' '<<ans[res].back()<<'\n';
		modify(res,ans[res].back());
	}
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j];
			if(j+1<ans[i].size()) cout<<' ';
		}
		cout<<'\n';
	}
}