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

vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
int MOD;
int add(int a, int b)
{
	a+=b;
	a%=MOD;
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
	
int cnt[555555];

void solve(int n, int depth)
{
	if(depth<=1) {cnt[n]++; return ;}
	if(n==1) {cnt[n]++; return ;}
	solve((n+1)/2,depth-1);
	solve(n-(n+1)/2,depth-1);
}

int solve_one(int n)
{
	return mult(fact[n], mult(n, mult(n-1, inv[4])));
}

int solve_two(int a, int b)
{
	int ans = 0;
	for(int S=2;S<=a+b;S++)
	{
		int r = min(S-1, a);
		int l = max(1, S-b);
		int ct = max(0, r-l+1);
		ans=add(ans,mult(ct,mult(S-2,inv[2*S])));
	}
	ans=mult(ans,fact[a+b]);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k>>MOD; init(633333);
	solve(n,k);
	int smallest=-1;
	for(int i=0;i<=n;i++)
	{
		if(cnt[i]>0)
		{
			smallest=i;
			break;
		}
	}
	int ans = 0;
	//both are in the same array
	for(int i=smallest;i<=smallest+1;i++)
	{
		int c = cnt[i];
		int coeff = mult(c, mult(fact[n-i], choose(n, i)));
		ans = add(ans, mult(coeff, solve_one(i)));
	}
	//both are in different arrays
	for(int i=smallest;i<=smallest+1;i++)
	{
		for(int j=i;j<=smallest+1;j++)
		{
			int c = mult(cnt[i],cnt[j]);
			if(i==j)
			{
				c = choose(cnt[i],2);
			}
			if(i+j>n) continue;
			int coeff = mult(c, mult(fact[n-i-j],choose(n, i+j)));
			ans = add(ans, mult(coeff, solve_two(i,j)));
		}
	}
	ans=mult(ans,ifact[n]);
	cout<<ans<<'\n';
}