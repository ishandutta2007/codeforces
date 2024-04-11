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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
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
struct DSU
{
	int S;
	
	struct node
	{
		int p; ll sum;
	};
	vector<node> dsu;
	
	DSU(int n)
	{
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 0;
			dsu.pb(tmp);
		}
	}
	
	void reset(int n)
	{
		dsu.clear();
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 0;
			dsu.pb(tmp);
		}
	}
	
	int rt(int u)
	{
		if(dsu[u].p == u) return u;
		dsu[u].p = rt(dsu[u].p);
		return dsu[u].p;
	}
	
	void merge(int u, int v)
	{
		u = rt(u); v = rt(v);
		if(u == v) return ;
		if(rand()&1) swap(u, v);
		dsu[v].p = u;
		dsu[u].sum += dsu[v].sum;
	}
	
	bool sameset(int u, int v)
	{
		if(rt(u) == rt(v)) return true;
		return false;
	}
	
	ll getstat(int u)
	{
		return dsu[rt(u)].sum;
	}
};

int kpow[222222];
	
int f(int n, int a, int b)
{
	DSU dsu(n);
	for(int j=0;j<a;j++)
	{
		dsu.merge(j,n-a+j);
	}
	for(int j=0;j<b;j++)
	{
		dsu.merge(j,n-b+j);
	}
	set<int> S;
	for(int i=0;i<n;i++) S.insert(dsu.rt(i));
	return S.size();
}

int mob[212111];
bool comp[212111];
vi D[212111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(242401);
	int n,k; cin>>n>>k;
	kpow[0]=1;
	for(int i=1;i<=211111;i++)
	{
		kpow[i]=mult(kpow[i-1],k);
	}
	for(int i=1;i<=211111;i++) 
	{
		for(int j=i;j<=211111;j+=i) D[j].pb(i);
	}
	for(int i=1;i<=211111;i++) mob[i] = 1;
    for(int i=2;i<=211111;i++)
    {
		 if (!comp[i]) 
		 {
			for (int j = 2*i; j <= n; j += i) comp[j] = 1;
			for (int j = i; j <= n; j += i) {
				if (j/i % i == 0) mob[j] = 0;
				else mob[j] *= -1;
			}
		}
    }
	int ans=0;
	//sum of f(s)
	{
		int res=0;
		for(int i=1;i<n;i++)
		{
			res=add(res,kpow[n-i]); //check later
		}
		ans=add(ans,res);
	}
	//sum of f(s)C2
	{
		int res=0;
		for(int g=1;g<n;g++)
		{
			for(int s=g;s<2*n;s+=g)
			{
				//gcd(i,j)=1
				//1<=i<j<=floor((n-1)/g)
				//i+j=s/g
				int l = max(1,s/g - (n-1)/g);
				int r = (s/g-1)/2;
				int cnt = max(0,r-l+1);
				//cerr<<cnt<<'\n';
				for(int z:D[s/g])
				{
					if(z==1) continue;
					if(mob[z]==0) continue;
					int G = g*z;
					int l = max(1,s/G - (n-1)/G);
					int r = (s/G-1)/2;
					int c = max(0,r-l+1);
					cnt+=mob[z]*c;
					//cerr<<z<<' '<<mob[z]<<' '<<c<<'\n';
				}
				//cerr<<"F: "<<g<<' '<<s<<' '<<A<<' '<<cnt<<'\n';
				int coeff = kpow[max(g,s-n)];
				res=add(res,mult(cnt,coeff));
			}
		}
		ans=add(ans,add(res,res));
	}
	ans=mult(ans,inverse(modpow(k,n)));
	cout<<ans<<'\n';
}