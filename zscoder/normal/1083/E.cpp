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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<pair<ii,ll> > vec;
ll X[1111111];
ll Y[1111111];
ll A[1111111];
ll dp[1111111];

const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return 1.0L * b - s->b < 1.0L *(s->m - m) * x;
    }
};
struct ConvexHull : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b)*1.0L*(z->m - y->m) >= (y->b - z->b)*1.0L*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};

int main()
{
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		ll x,y,a; scanf("%lld %lld %lld",&x,&y,&a);
		vec.pb(mp(mp(x,y),a));
	}
	vec.pb(mp(mp(0,0),0));
	sort(vec.begin(),vec.end());
	for(int i=0;i<=n;i++)
	{
		X[i]=vec[i].fi.fi; Y[i]=vec[i].fi.se; A[i]=vec[i].se;
	}
	ConvexHull ch;
	ll ans=0;
	ch.insert_line(-X[0],dp[0]);
	for(int i=1;i<=n;i++)
	{
		dp[i] = ch.eval(Y[i])-A[i]+X[i]*Y[i];
		ch.insert_line(-X[i],dp[i]);
		ans=max(ans,dp[i]);
	}
	cout<<ans<<'\n';
}