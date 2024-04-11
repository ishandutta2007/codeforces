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
void radd(int &a, int b)
{
	a=add(a,b); 
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
void rmult(int &a, int b)
{
	a=mult(a,b);
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

int a[333333];
int f[333333];
ii F[333333];

ii add(ii a, ii b)
{
	a.fi=add(a.fi,b.fi); a.se=add(a.se,b.se); return a;
}

ii mult(ii a, int v)
{
	a.fi=mult(a.fi,v); a.se=mult(a.se,v);
	return a;
}

ii sub(ii a, ii b)
{
	a.fi=add(a.fi,MOD-b.fi); a.se=add(a.se,MOD-b.se); return a;
}

int subst(ii a, int x)
{
	return add(mult(a.fi,x),a.se);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(555555);
	int n; cin>>n;
	int S=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];S+=a[i];
	}
	{
		f[S]=0;
		F[0]={1,0};
		for(int i=0;i+1<S;i++)
		{
			int p1 = mult(i,inv[S]);
			int p2 = mult(mult(S-i,inv[S]),inv[n-1]);
			int p3 = mult(mult(S-i,n-2),mult(inv[S],inv[n-1]));
			ii sum = {0,0};
			sum = add({0,1},mult(F[i],add(p3,MOD-1)));
			if(i>0) sum=add(sum,mult(F[i-1],p1));
			p2 = MOD-p2;
			p2 = inverse(p2);
			F[i+1]=mult(sum,p2);
		}
		{
			int P = mult(n-2,mult(inv[S],inv[n-1]));
			P = add(1,MOD-P);
			ii LHS = mult(F[S-1],P);
			ii RHS = add({0,1},mult(F[S-2],mult(S-1,inv[S])));
			LHS=sub(LHS,RHS);
			assert(LHS.fi!=0);
			int x = mult(MOD-LHS.se,inverse(LHS.fi));
			for(int i=0;i<S;i++)
			{
				f[i]=subst(F[i],x);
			}
		}
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum=add(sum,f[a[i]]);
	}
	sum=add(sum,MOD-mult(n-1,f[0]));
	sum=mult(sum,inv[n]);
	cout<<sum<<'\n';
	/*
	assert(sum!=0);
	int isum = inverse(sum);
	for(int i=0;i<n;i++)
	{
		ans=add(ans,mult(mult(f[a[i]],f[a[i]]),isum));
	}
	cout<<ans<<'\n';
	*/
}