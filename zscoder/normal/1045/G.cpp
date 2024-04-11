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
        for (; p < (int)t.size(); p += (p&(-p))) t[p] += v;
    }
    ll query(int r) //finds [1, r] sum
    {                     
        ll sum = 0;
        for (; r; r -= (r&(-r))) sum += t[r];
        return sum;
    }
    ll query(int l, int r) //finds [l, r] sum
    {
		if(l == 0) return query(r);
		return query(r) - query(l-1);
	}
};

ll solve(vector<int> x, vector<int> y, vector<int> rx, vector<int> ry) //x y are sorted
{
	/*
	for(int i=0;i<x.size();i++) cerr<<x[i]<<' '<<rx[i]<<'\n';
	for(int i=0;i<y.size();i++) cerr<<y[i]<<' '<<ry[i]<<'\n';
	cerr<<'\n';
	*/
	vi coord;
	for(int i=0;i<y.size();i++)
	{
		int L = y[i] - ry[i]; int R = y[i] + ry[i]; coord.pb(L); coord.pb(R);
	}
	for(int i=0;i<x.size();i++) coord.pb(x[i]);
	sort(coord.begin(),coord.end()); coord.erase(unique(coord.begin(),coord.end()),coord.end());
	Fenwick fen(int(coord.size())+2);
	ll ans = 0;
	vector<vector<ii> > events(int(y.size())+1);
	for(int i=0;i<x.size();i++)
	{
		int L = x[i]-rx[i];
		int R = x[i]+rx[i];
		int l = lower_bound(y.begin(),y.end(),L)-y.begin();
		int r = upper_bound(y.begin(),y.end(),R)-y.begin();
		r--;
		int cc = lower_bound(coord.begin(),coord.end(),x[i])-coord.begin();
		//cerr<<"EVENT : "<<l<<' '<<r<<' '<<cc<<'\n';
		if(l-1>=0) events[l-1].pb(mp(cc,-1));
		if(r>=0) events[r].pb(mp(cc,1));
	}
	for(int i=0;i<y.size();i++)
	{
		int L = y[i] - ry[i]; int R = y[i] + ry[i];
		L=lower_bound(coord.begin(),coord.end(),L)-coord.begin();
		R=lower_bound(coord.begin(),coord.end(),R)-coord.begin();
		fen.update(L+1,1);
		fen.update(R+2,-1);
		for(ii e:events[i])
		{
			int xx = e.fi; int sign = e.se;
			ans += sign*fen.query(xx+1);
		}
	}
	return ans;
}

ll naive(vector<pair<int,ii> > vec, int k)
{
	int n=vec.size(); ll ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(abs(vec[i].fi-vec[j].fi)<=k)
			{
				int x1 = vec[i].se.fi; int x2 = vec[j].se.fi; int r1 = vec[i].se.se; int r2 = vec[j].se.se;
				if(x1-r1<=x2&&x2<=x1+r1&&x2-r2<=x1&&x1<=x2+r2) ans++;
			}
		}
	}
	return ans;
}

ll clever(vector<pair<int,ii> > V, int k)
{
	map<int,vector<ii>> ma;
	int n=V.size();
	for(int i=0;i<n;i++)
	{
		int iq=V[i].fi; int x=V[i].se.fi; int r=V[i].se.se;
		ma[iq].pb(mp(x,r)); 
	}
	ll ans = 0;
	for(auto &v:ma)
	{
		sort(v.se.begin(),v.se.end());
	}
	for(auto vec:ma)
	{
		//reproduce with itself
		vi x,rx;
		for(ii z:vec.se)
		{
			x.pb(z.fi); rx.pb(z.se);
			//cerr<<z.fi<<' '<<z.se<<'\n';
		}
		ll res = solve(x,x,rx,rx);
		res -= vec.se.size();
		ans += res/2;
		for(int i=1;i<=k;i++)
		{
			if(ma.find(vec.fi+i)==ma.end()) continue;
			vi y,ry;
			for(ii z:ma[vec.fi+i])
			{
				y.pb(z.fi); ry.pb(z.se);
			}
			ans += solve(x,y,rx,ry);
		}
	}
	return ans;
}

const bool DEBUG=0;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int cc=1;;cc++)
	{
		vector<pair<int,ii> > V;
		int n,k; 
		if(!DEBUG)
		{
			cin>>n>>k;
		}
		else
		{
			n=rand()%300+1;
			k=rand()%20;
		}
		for(int i=0;i<n;i++)
		{
			int x,r,iq; 
			if(!DEBUG)
			{
				cin>>x>>r>>iq;
			}
			else
			{
				x=rand()%500;
				r=rand()%300;
				iq=rand()%3;
			}
			V.pb(mp(iq,mp(x,r)));
		}
		ll ans1 = clever(V,k);
		if(!DEBUG)
		{
			cout<<ans1<<'\n'; return 0;
		}
		ll ans2 = naive(V,k);
		cerr<<"ANSWERS (CLEVER, NAIVE) : "<<ans1<<' '<<ans2<<'\n';
		if(ans1!=ans2)
		{
			freopen("AI.in","w",stdout);
			cout<<n<<' '<<k<<'\n';
			for(int i=0;i<n;i++)
			{
				cout<<V[i].se.fi<<' '<<V[i].se.se<<' '<<V[i].fi<<'\n';
			}
			return 0;
		}
		cerr<<"Case #"<<cc<<" complete\n";
	}
}