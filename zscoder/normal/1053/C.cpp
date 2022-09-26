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

const int MOD=1e9+7;

ll add(ll a, ll b)
{
	a+=b; a%=MOD;
	if(a<0) a+=MOD;
	return a;
}
ll mult(ll a, ll b)
{
	a%=MOD; b%=MOD;
	a=(a*b)%MOD;
	if(a<0) a+=MOD;
	return a;
}
	
ll normalize(ll a)
{
	a%=MOD;
	if(a<0) a+=MOD;
	return a;
}

struct Fenwick2
{
	vector<ll> t;
    Fenwick2(int n)
    {
        t.assign(n+1,0);
    }
    void reset(int n)
    {
		t.assign(n+1, 0);
	}
    void update(int p, ll v)
    {
        for (; p < (int)t.size(); p += (p&(-p))) t[p] = add(t[p], v);
    }
    ll query(int r) //finds [1, r] sum
    {                     
        ll sum = 0;
        for (; r; r -= (r&(-r))) sum = add(sum, t[r]);
        return sum;
    }
    ll query(int l, int r) //finds [l, r] sum
    {
		if(l == 0) return query(r);
		return add(query(r), MOD - query(l-1));
	}
};
ll pref[222222];
ll a[222222];
ll w[222222];
ll sum(int l, int r)
{
	if(l==0) return pref[r];
	else return pref[r]-pref[l-1];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,q; cin>>n>>q;
	Fenwick fen(n+3); Fenwick2 fen2(n+3);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; a[i]-=i;
		pref[i]=pref[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		fen.update(i,w[i]);
		fen2.update(i,mult(w[i],a[i]));
	}
	for(int z=0;z<q;z++)
	{
		int pos; ll x; cin>>pos>>x;
		if(pos<0)
		{
			pos=abs(pos);
			fen.update(pos,x-w[pos]);
			fen2.update(pos,mult(x-w[pos],a[pos]));
			w[pos]=x;
		}
		else
		{
			int l = pos; int r = x;
			int lo = l; int hi = r;
			ll tot = fen.query(l,r);
			int ans = r;
			while(lo<=hi)
			{
				int mid=(lo+hi)>>1;
				ll tmp = fen.query(l,mid);
				if(tmp*2>tot)
				{
					ans = mid;
					hi=mid-1;
				}
				else lo=mid+1;
			}
			ll x = a[ans];
			ll L = add(mult(normalize(fen.query(l,ans)),x),MOD-fen2.query(l,ans));
			ll R = add(fen2.query(ans+1,r), MOD-mult(normalize(fen.query(ans+1,r)),x));
			ll res = add(L,R);
			cout<<res<<'\n';
		}
	}
}