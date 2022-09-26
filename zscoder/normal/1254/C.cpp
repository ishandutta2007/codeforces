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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll f(int t, int i, int j, int k)
{
	i++; j++; k++;
	cout<<t<<' '<<i<<' '<<j<<' '<<k<<'\n';
	fflush(stdout);
	ll x; cin>>x; return x;
}

ll a[11111];

int main()
{
	int n; cin>>n;
	int L=1;
	for(int i=2;i<n;i++)
	{
		if(f(2,0,L,i)==-1)
		{
			L=i;
		}
	}
	vector<ii> V;
	for(int i=1;i<n;i++)
	{
		if(i!=L)
		{
			a[i]=f(1,0,L,i);
			V.pb({a[i],i});
		}
	}
	vi A,B;
	A.pb(L);
	sort(V.begin(),V.end());
	set<int> rem;
	for(int i=0;i<n;i++)
	{
		if(i==0||i==L) continue;
		rem.insert(i);
	}
	for(pair<ll,ll> x:V)
	{
		int id=x.se;
		rem.erase(id);
		if(rem.empty()){A.pb(id); break;}
		int res = f(2,0,id,(*rem.begin()));
		if(res==1)
		{
			A.pb(id);
		}
		else
		{
			B.pb(id);
		}
	}
	reverse(B.begin(),B.end());
	cout<<0<<' ';
	cout<<1<<' ';
	for(int x:A)
	{
		cout<<x+1<<' ';
	}
	for(int y:B)
	{
		cout<<y+1<<' ';
	}
	cout<<'\n';
	
}