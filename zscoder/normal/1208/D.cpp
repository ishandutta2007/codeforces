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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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

ll s[222222];
int a[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>s[i];
	Fenwick fen(n+10);
	for(int i=1;i<=n;i++) fen.update(i,i);
	pbds P;
	for(int i=1;i<=n;i++) P.insert(i);
	for(int i=n-1;i>=0;i--)
	{
		int lo=0; int hi=int(P.size())-1;
		int ans=-1;
		while(lo<=hi)
		{
			int mid=(lo+hi)>>1;
			int pos = (*P.find_by_order(mid));
			if(fen.query(pos-1)>=s[i])
			{
				ans=mid;
				hi=mid-1;
			}
			else lo=mid+1;
		}
		a[i]=(*P.find_by_order(ans)); fen.update(a[i],-a[i]);
		P.erase(a[i]);
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}