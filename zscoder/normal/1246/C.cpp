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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
	
int dp[2222][2222][2];
int n,m; 
char a[2222][2222];
int r[2222][2222];
int d[2222][2222];

void radd(int &a, int b)
{
	a=add(a,b);
}

void addrange(int xl, int yl, int xr, int yr, int v, int mode)
{
	if(xl>xr||yl>yr) return ;
	radd(dp[xl][yl][mode],v);
	radd(dp[xl][yr+1][mode],MOD-v);
	radd(dp[xr+1][yl][mode],MOD-v);
	radd(dp[xr+1][yr+1][mode],v);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=m-1;j>=0;j--)
		{
			r[i][j]=r[i][j+1]+(a[i][j]=='R');
		}
	}
	for(int j=0;j<m;j++)
	{
		for(int i=n-1;i>=0;i--)
		{
			d[i][j]=d[i+1][j]+(a[i][j]=='R');
		}
	}
	if(n==1&&m==1)
	{
		cout<<1<<'\n'; return 0;
	}
	addrange(0,1,0,m-1-r[0][0],1,1);
	addrange(1,0,n-1-d[0][0],0,1,0);
	/*
	for(int j=1;j<m;j++)
	{
		dp[0][j][1]=(r[0][0]<m-j?1:0);
	}
	for(int i=1;i<n;i++)
	{
		dp[i][0][0]=(d[0][0]<n-i?1:0);
	}
	*/
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<2;k++)
			{
				if(i>0) radd(dp[i][j][k],dp[i-1][j][k]);
				if(j>0) radd(dp[i][j][k],dp[i][j-1][k]);
				if(i>0&&j>0) radd(dp[i][j][k],MOD-dp[i-1][j-1][k]);
				int v=dp[i][j][k];
				//cerr<<i<<' '<<j<<' '<<k<<' '<<v<<'\n';
				if(v>0)
				{
					if(k==0) //last move = down
					{
						int cntr=r[i][j+1];
						//add 1 to 
						addrange(i,j+1,i,m-1-cntr,v,k^1);
						/*
						for(int l=j+1;l<=m-1-cntr;l++)
						{
							radd(dp[i][l][k^1],v);
						}
						*/
					}
					else
					{
						int cntd=d[i+1][j];
						/*
						for(int l=i+1;l<=n-1-cntd;l++)
						{
							radd(dp[l][j][k^1],v);
						}
						*/
						addrange(i+1,j,n-1-cntd,j,v,k^1);
					}
				}
			}
		}
	}
	cout<<add(dp[n-1][m-1][0],dp[n-1][m-1][1])<<'\n';
}