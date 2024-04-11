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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll INF = (1ll << 60) + 123;
struct Fenwick
{
	vector<ll> t;
    Fenwick(int n)
    {
        t.assign(n+1,0);
    }
    void reset(int n)
    {
		t.assign(n+1, 0);
	}
    void update(int p, ll v)
    {
        for (; p < (int)t.size(); p += (p&(-p))) 
        {
			t[p] += v;
			if(t[p] > INF) t[p] = INF;
		}
    }
    ll query(int r) //finds [1, r] sum
    {                     
        ll sum = 0;
        for (; r; r -= (r&(-r))) 
        {
			sum += t[r];
			if(sum > INF) sum = INF;
		}
        return sum;
    }
    ll query(int l, int r) //finds [l, r] sum
    {
		if(l == 0) return query(r);
		return query(r) - query(l-1);
	}
};

Fenwick fen(300011);
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<ii> vec;
	ll T;
	vector<pair<ll,ll> > q;
	for(int i = 0; i < n; i++)
	{
		ll t, w; cin>>t>>w;
		if(i==0)
		{
			T = t;
		}
		else
		{
			vec.pb(mp(t,w));
		}
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	for(int i = 0; i < vec.size(); i++)
	{
		q.pb(mp(vec[i].se-vec[i].fi+1, i));
	}
	sort(q.begin(),q.end());
	//vector<ll> q;
	int best = 10000000;
	if(T >= vec[0].fi)
	{
		cout<<1;
		return 0;
	}
	pbds pos;
	for(int i = 0; i < vec.size(); i++)
	{
		ll diff = vec[i].se - vec[i].fi + 1;
		int l = lower_bound(q.begin(),q.end(),mp(diff,ll(i))) - q.begin();
		pos.insert(l);
		fen.update(l+1, diff);
		if(i + 1 < vec.size() && vec[i+1].fi == vec[i].fi) 
		{
			continue;
		}
		int lo = 1; int hi = i + 1;
		int answer = 0;
		ll nxt = 0;
		if(i+1<vec.size()) nxt = vec[i+1].fi;
		ll balloons = T - nxt;
		if(balloons < 0) continue;
		//cerr<<i<<' '<<balloons<<'\n';
		while(lo <= hi)
		{
			int mid = (lo+hi)>>1;
			int z = (*pos.find_by_order(mid-1));
			//cerr<<z<<'\n';
			if(fen.query(1, z+1) <= balloons)
			{
				answer = mid;
				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}
		//cerr<<i<<' '<<answer<<'\n';
		best = min(best, i + 2 - answer);
	}
	cout<<best;
}