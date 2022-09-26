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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

pair<ii,ii> combine(pair<ii,ii> a, pair<ii,ii> b)
{
	return mp(mp(max(a.fi.fi,b.fi.fi),max(a.fi.se,b.fi.se)),mp(min(a.se.fi,b.se.fi),min(a.se.se,b.se.se)));
}

bool valid(pair<ii,ii> x)
{
	return (x.fi.fi<=x.se.fi&&x.fi.se<=x.se.se);
}

pair<ii,ii> a[222222];
pair<ii,ii> t[2 * 222222];
int n;
void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}
const int INF=int(1e9)+10;
pair<ii,ii> query(int l, int r) {  // sum on interval [l, r)
  pair<ii,ii> res = mp(mp(-INF,-INF),mp(INF,INF));
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = combine(res, t[l++]);
    if (r&1) res =combine(res,t[--r]);
  }
  return res;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
		a[i] = mp(mp(x1,y1),mp(x2,y2));
	}
	for(int i=n;i<2*n;i++) t[i]=a[i-n];
	build();
	for(int i=0;i<n;i++)
	{
		pair<ii,ii> ans = mp(mp(-INF,-INF),mp(INF,INF));
		ans = combine(ans,query(0,i));
		ans = combine(ans,query(i+1,n));
		if(valid(ans))
		{
			cout<<ans.fi.fi<<' '<<ans.fi.se<<'\n'; return 0;
		}
	}
}