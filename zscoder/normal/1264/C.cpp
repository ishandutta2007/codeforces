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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
const int MOD = 998244353;
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
int modpow(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
int choose(int a, int b)
{
	if(a<b) return 0;
	if(b==0) return 1;
	if(a==b) return 1;
	return mult(fact[a],mult(ifact[b],ifact[a-b]));
}
int inverse(int a)
{
	return modpow(a,MOD-2);
}
void init(int _n)
{
	fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
	fact.resize(_n+1);
	ifact.resize(_n+1);
	inv.resize(_n+1);
	pow2.resize(_n+1);
	pow2[0]=1;
	ifact[0]=1;
	fact[0]=1;
	for(int i=1;i<=_n;i++)
	{
		pow2[i]=add(pow2[i-1],pow2[i-1]);
		fact[i]=mult(fact[i-1],i);
		//ifact[i]=mult(ifact[i-1],inv[i]);
	}
	ifact[_n] = inverse(fact[_n]);
	for(int i=_n-1;i>=1;i--)
	{
		ifact[i] = mult(ifact[i + 1], i + 1);
	}
	for(int i=1;i<=_n;i++)
	{
		inv[i] = mult(fact[i-1],ifact[i]);
	}
}

int prod[455555];
int S[455555];
int a[455555];

int P(int l, int r)
{
	if(l==0) return prod[r];
	else return mult(prod[r],inverse(prod[l-1]));
}

int sum(int l, int r)
{
	if(l==0) return S[r];
	else return add(S[r],MOD-S[l-1]);
}

int query(int l, int r)
{
	int ans = inverse(P(l,r));
	if(l==0)
	{
		ans=mult(ans,add(1,sum(l,r-1)));
		return ans;
	}
	ans = mult(ans,sum(l-1,r-1));
	ans = mult(ans,inverse(P(0,l-1)));
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(455555);
	int n,q; cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]=mult(a[i],inv[100]);
		prod[i]=a[i];
		if(i>0) prod[i]=mult(prod[i],prod[i-1]);
	}
	for(int i=0;i<n;i++)
	{
		S[i]=prod[i];
		if(i>0) S[i]=add(S[i],S[i-1]);
	}
	set<int> ss;
	ss.insert(0);
	ss.insert(n);
	int ans = query(0,n-1);
	for(int zz=0;zz<q;zz++)
	{
		int z; cin>>z; z--;
		if(ss.find(z)==ss.end())
		{
			auto it = ss.lower_bound(z);
			auto it2 = it;
			it2--;
			int l = (*it2); int r = (*it);
			//cerr<<l<<' '<<z<<' '<<r<<'\n';
			ans = add(ans,MOD-query(l,r-1));
			ans = add(ans,query(l,z-1));
			ans = add(ans,query(z,r-1));
			ss.insert(z);
		}
		else 
		{
			ss.erase(z);
			auto it = ss.lower_bound(z);
			auto it2 = it;
			it2--;
			int l = (*it2); int r = (*it);
			ans = add(ans,query(l,r-1));
			ans = add(ans,MOD-query(l,z-1));
			ans = add(ans,MOD-query(z,r-1));
		}
		/*
		vi v;
		for(int x:ss) v.pb(x);
		int ans=0;
		for(int i=0;i+1<v.size();i++)
		{
			ans=add(ans,query(v[i],v[i+1]-1));
		}
		*/
		cout<<ans<<'\n';
	}
}