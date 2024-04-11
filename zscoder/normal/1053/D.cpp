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

vector<ll> primes;
vector<bool> prime;
vector<ll> totient;
vector<ll> sumdiv;
vector<ll> bigdiv;
void Sieve(ll n)
{
	prime.assign(n+1, 1);
	prime[1] = false;
	for(ll i = 2; i <= n; i++)
	{
		if(prime[i])
		{
			primes.pb(i);
			for(ll j = i*2; j <= n; j += i)
			{
				prime[j] = false;
			}
		}
	}
}

ll phi(ll x)
{
	map<ll,ll> pf;
	ll num = 1; ll num2 = x;
	for(ll i = 0; primes[i]*primes[i] <= x; i++)
	{
		if(x%primes[i]==0)
		{
			num2/=primes[i];
			num*=(primes[i]-1);
		}
		while(x%primes[i]==0)
		{
			x/=primes[i];
			pf[primes[i]]++;
		}
	}
	if(x>1)
	{
		pf[x]++; num2/=x; num*=(x-1);
	}
	x = 1;
	num*=num2;
	return num;
}

bool isprime(ll x)
{
	if(x==1) return false;
	for(ll i = 0; primes[i]*primes[i] <= x; i++)
	{
		if(x%primes[i]==0) return false;
	}
	return true;
}

void SievePhi(ll n)
{
	totient.resize(n+1);
	for (int i = 1; i <= n; ++i) totient[i] = i;
	for (int i = 2; i <= n; ++i)
	{
		if (totient[i] == i)
		{
			for (int j = i; j <= n; j += i)
			{
				totient[j] -= totient[j] / i;
			}
		}
	}
}

void SieveSumDiv(ll n)
{
	sumdiv.resize(n+1);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i; j <= n; j += i)
		{
			sumdiv[j] += i;
		}
	}
}

ll getPhi(ll n)
{
	return totient[n];
}

ll getSumDiv(ll n)
{
	return sumdiv[n];
}

void getpf(vector<ii>& pf, ll n)
{
	for(ll i = 0; primes[i]*primes[i] <= n; i++)
	{
		int cnt = 0;
		while(n%primes[i]==0)
		{
			n/=primes[i]; cnt++;
		}
		if(cnt>0) pf.pb(ii(primes[i], cnt));
	}
	if(n>1)
	{
		pf.pb(ii(n, 1));
	}
}

//ll op;
void getDiv(vector<ll>& div, vector<ii>& pf, ll n, int i)
{
	//op++;
	ll x, k;
	if(i >= pf.size()) return ;
	x = n;
	for(k = 0; k <= pf[i].se; k++)
	{
		if(i==int(pf.size())-1) div.pb(x);
		getDiv(div, pf, x, i + 1);
		x *= pf[i].fi;
	}
}

const int MOD = (1e9 + 7);
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

int ans[2222222];
int mx[2222222];
int ans2[2222222];
int C[2222222];
vector<ii> pf[2022222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	Sieve(2000111);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; C[x]++;
		if(C[x]==1)
		{
			getpf(pf[x], x-1);
		}
	}
	int ad = 0;
	for(int v:primes)
	{
		if(C[v]>=3)
		{
			if(ans[v]==0) mx[v]++;
			ans[v]=max(ans[v],1); ans2[v]=ans[v];
			ad=1;
			for(ii x:pf[v])
			{
				if(x.se>ans[x.fi]) mx[x.fi]=1;
				else if(x.se==ans[x.fi]) mx[x.fi]++;
				ans[x.fi]=max(ans[x.fi],x.se); ans2[x.fi]=ans[x.fi];
			}
		}
	}
	for(int i=int(primes.size())-1;i>=0;i--)
	{
		int v=primes[i];
		if(C[v]==1||C[v]==2)
		{
			int cnt=C[v];
			if(cnt>0&&ans[v]==0)
			{
				cnt--; ans[v]=1; mx[v]++;
			}
			bool ex=1;
			for(ii x:pf[v])
			{
				if(x.se>ans[x.fi]) ex=1;
			}
			if(cnt>0&&ex)
			{
				cnt--; 
				for(ii x:pf[v])
				{
					if(x.se>ans[x.fi]) mx[x.fi]=1;
					else if(x.se==ans[x.fi]) mx[x.fi]++;
					ans[x.fi]=max(ans[x.fi],x.se);
				}
			}
			if(cnt>0&&!ad)
			{
				cnt--; ad=1;
			}
		}
	}
	if(!ad)
	{
		for(int i=int(primes.size())-1;i>=0;i--)
		{
			int v=primes[i];
			if(C[v]==1||C[v]==2)
			{
				int cnt=C[v];
				if(cnt>0&&ans2[v]==0)
				{
					cnt--; ans2[v]=1;
					if(ans[v]!=1||mx[v]!=1) ad=1;
				}
				bool ex=1;
				for(ii x:pf[v])
				{
					if(x.se>ans2[x.fi]) ex=1;
				}
				if(cnt>0&&ex)
				{
					cnt--; bool important=0;
					for(ii x:pf[v])
					{
						if(x.se==ans[x.fi]&&mx[x.fi]==1)
						{
							important=1;
						}
						ans2[x.fi]=max(ans2[x.fi],x.se);
					}
					if(!important) ad=1;
				}
				if(cnt>0&&!ad)
				{
					cnt--; ad=1;
				}
			}
		}
	}
	/*
	for(int i=int(primes.size())-1;i>=0;i--)
	{
		int v=primes[i];
		if(C[v]==1)
		{
			int cnt=1;
			if(cnt>0&&ans[v]==0)
			{
				cnt--; ans[v]=1;
			}
			bool ex=0;
			for(ii x:pf[v])
			{
				if(x.se>ans[x.fi]) ex=1;
			}
			if(cnt>0&&ex)
			{
				cnt--; 
				for(ii x:pf[v])
				{
					ans[x.fi]=max(ans[x.fi],x.se);
				}
			}
			if(cnt>0&&!ad)
			{
				cnt--; ad=1;
			}
		}
	}
	*/
	int res=1;
	for(int v:primes)
	{
		res=mult(res,modpow(v,ans[v]));
	}
	if(ad) res=add(res,1);
	cout<<res<<'\n';
}