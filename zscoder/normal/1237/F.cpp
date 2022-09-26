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
typedef double ld; 
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
	if(a<0) return 0;
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
	
int a[2][5555];
int dp[2][3999][4000];

void radd(int &x, int y)
{
	x=add(x,y);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(99999);
	int n,m,q; cin>>n>>m>>q;
	for(int i=1;i<=n;i++) a[0][i]=1;
	for(int i=1;i<=m;i++) a[1][i]=1;
	int tot[2]={0,0};
	for(int i=0;i<q;i++)
	{
		int r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2;
		for(int j=r1;j<=r2;j++)
		{
			a[0][j]=0; 
		}
		for(int j=c1;j<=c2;j++)
		{
			a[1][j]=0;
		}
	}	
	for(int i=1;i<=max(n,m);i++) 
	{
		for(int z=0;z<2;z++)
		{
			tot[z]+=a[z][i];
		}
	}
	for(int z=0;z<2;z++)
	{
		dp[z][0][0]=1;
		for(int i=0;i<=max(n,m);i++)
		{
			for(int j=0;j<=max(n,m);j++)
			{
				if(dp[z][i][j]==0) continue;
				int v=dp[z][i][j];
				if(a[z][i+1]&&a[z][i+2])
				{
					radd(dp[z][i+2][j+1],v);
				}
				radd(dp[z][i+1][j],v);
			}
		}
	}
	int ans=0;
	for(int k=0;k<=max(n,m);k++)
	{
		for(int l=0;l<=max(n,m);l++)
		{
			if(k+2*l<=n&&l+2*k<=m)
			{
				int res=mult(mult(dp[0][n][l],dp[1][m][k]),mult(choose(tot[0]-2*l,k),choose(tot[1]-2*k,l)));
				res=mult(res,mult(fact[k],fact[l]));
				ans=add(ans,res);
			}
		}
	}
	cout<<ans<<'\n';
}