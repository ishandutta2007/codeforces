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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int n = 515555;
ll t[2*n+1];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, ll value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

ll query(int l, int r) {  // sum on interval [l, r)
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

map<int,vi> ma;
set<ii> M;
map<ii,int> compressed;
vector<pair<ii,ll> > interesting;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q; cin>>q;
	vector<pair<char,ll> > vec;
	for(int z=0;z<q;z++)
	{
		char c; cin>>c; ll x; cin>>x;
		vec.pb(mp(c,x));
		if(c=='+') compressed[mp(x,z)]=1;
	}
	int ct=0;
	for(auto X:compressed)
	{
		compressed[X.fi]=ct++;
	}
	int qq=0;
	for(auto Q:vec)
	{
		char c = Q.fi; ll x = Q.se;
		if(c=='+')
		{
			int pos = compressed[mp(x,qq)];
			modify(pos,x);
			ma[x].pb(qq);
			set<ii>::iterator it = M.insert(mp(x,qq)).fi;
			for(int i=0;i<interesting.size();i++)
			{
				if(interesting[i].fi.fi>x||(interesting[i].fi.fi==x&&interesting[i].fi.se>qq))
				{
					interesting[i].se+=x;
				}
			}
			if(it!=M.begin()&&it->fi>prev(it)->fi*2)
			{
				interesting.pb(mp(mp(x,qq),query(0,pos)));
			}
			if(next(it)!=M.end())
			{
				for(int i=0;i<interesting.size();i++)
				{
					if(interesting[i].fi==(*next(it)))
					{
						interesting.erase(interesting.begin()+i); break;
					}
				}
				if(next(it)->fi>it->fi*2)
				{
					interesting.pb(mp((*next(it)),query(0,compressed[(*next(it))])));
				}
			}
		}
		else
		{
			int ty = ma[x].back(); ma[x].pop_back();
			modify(compressed[mp(x,ty)],0);
			set<ii>::iterator it = M.find(mp(x,ty));
			for(int i=0;i<interesting.size();i++)
			{
				if(interesting[i].fi.fi>x||(interesting[i].fi.fi==x&&interesting[i].fi.se>ty))
				{
					interesting[i].se-=x;
				}
			}
			if(next(it)!=M.end())
			{
				for(int i=0;i<interesting.size();i++)
				{
					if(interesting[i].fi==(*next(it)))
					{
						interesting.erase(interesting.begin()+i); break;
					}
				}
				if(it!=M.begin()&&next(it)->fi>prev(it)->fi*2)
				{
					interesting.pb(mp((*next(it)),query(0,compressed[(*next(it))])));
				}
			}
			for(int i=0;i<interesting.size();i++)
			{
				if(interesting[i].fi==(*it))
				{
					interesting.erase(interesting.begin()+i); break;
				}
			}
			M.erase(mp(x,ty));
		}
		qq++;
		int ans = M.size();
		if(M.size()>0) ans--;
		for(int i=0;i<interesting.size();i++)
		{
			if(interesting[i].fi.fi>2LL*interesting[i].se) ans--;
		}
		cout<<ans<<'\n';
	}
}