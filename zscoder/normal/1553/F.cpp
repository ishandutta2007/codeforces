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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ll a[333333];
ll S[333333];
ll T[333333];
ll coeff[333333];
const int C=301111;
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
		if(r<=0) return 0;
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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	ll s=0;
	for(int i=0;i<n;i++)
	{
		s+=a[i];
		S[i]=s*ll(i+1);
	}
	Fenwick fen(C+20);
	ll pref=0;
	Fenwick pbd(C+20);
	for(int i=0;i<n;i++)
	{
		//figure out how much pref changed
		ll x=a[i];
		for(int j=x;j<=C;j+=x)
		{
			fen.update(j,x); //update coeff[j] by x
			//pref+=x*(# of values >= j)
			ll cntlarger = i - pbd.query(j-1);
			pref+=cntlarger*x;
		}
		
		
		pbd.update(x,1);
		pref+=fen.query(x); //query [1,x]
		T[i]=pref;
	}
	/*
	for(int i=0;i<n;i++)
	{
		cerr<<S[i]<<' '<<T[i]<<'\n';
	}
	*/
	for(int i=0;i<n;i++)
	{
		cout<<S[i]-T[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}