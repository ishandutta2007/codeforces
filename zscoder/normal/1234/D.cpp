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

struct Fenwick
{
	vector<ll> t;
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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	int q; cin>>q;
	int n=s.length();
	Fenwick fen[28];
	for(int i=0;i<26;i++) fen[i].reset(n+10);
	for(int i=0;i<n;i++)
	{
		fen[s[i]-'a'].update(i+1,1);
	}
	while(q--)
	{
		int t; cin>>t;
		if(t==1)
		{
			int p; char c; cin>>p>>c;
			fen[s[p-1]-'a'].update(p,-1);
			s[p-1]=c;
			fen[s[p-1]-'a'].update(p,1);
		}
		else
		{
			int l,r; cin>>l>>r;
			int ans=0;
			for(int i=0;i<26;i++)
			{
				if(fen[i].query(l,r)>0) ans++;
			}
			cout<<ans<<'\n';
		}
	}
}