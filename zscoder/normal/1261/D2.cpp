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

int a[222222];
int kpow[555555];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(333333);
	int n,k; cin>>n>>k;
	if(k==1)
	{
		cout<<0<<'\n'; return 0;
	}
	int m=n;
	kpow[0]=1;
	for(int i=1;i<=500000;i++) kpow[i]=mult(kpow[i-1],k-2);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[(i+n-1)%n]) m--;
	}
	int M=n-m;
	n=m;
	int ans=0;
	int i2 = inverse(2);
	for(int S=1;S<=n;S++)
	{
		int coeff = mult(ifact[S],mult(kpow[n-S],mult(fact[n],ifact[n-S])));
		int res = pow2[S];
		if(S%2==0)
		{
			res=add(res,MOD-choose(S,S/2));
		}
		res=mult(res,i2);
		ans=add(ans,mult(coeff,res));
	}
	/*
	int ans2=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(i+j<=n)
			{
				ans2=add(ans2,mult(choose(n,i),mult(choose(n-i,j),kpow[n-i-j])));
			}
		}
	}
	*/
	ans=mult(ans,modpow(k,M));
	cout<<ans<<'\n';
}