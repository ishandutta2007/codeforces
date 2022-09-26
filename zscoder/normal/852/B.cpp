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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

const int MOD=1e9+7;
ll add(ll a, ll b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}

ll mult(ll a, ll b)
{
	return (a*b)%MOD;
}

ll dp[3][111];
ll cnt[111];
ll F[1111111];

const int mod = int(1e9) + 7;
const int DIM = 105;

struct Matrix {
  int a[DIM][DIM];
  int *operator [] (int r) { return a[r]; };

  Matrix(int x = 0) {
    memset(a, 0, sizeof a);
    if (x)
    {
		for(int i = 0; i < DIM; i++) a[i][i] = x;
	}
  }
} const I(1);

Matrix operator * (Matrix A, Matrix B) {
  const ll mod2 = ll(mod) * mod;
  Matrix C;
 for(int i = 0; i < DIM; i++)
 {
	 for(int j = 0; j < DIM; j++)
	 {
		ll w = 0;
		for(int k = 0; k < DIM; k++)
		{
			w += ll(A[i][k]) * B[k][j];
			if (w >= mod2) w -= mod2;
		}
    C[i][j] = w % mod;
	}
  }
  return C;
}

Matrix mpow(Matrix A, ll r)
{
	Matrix res(1);
	while(r)
	{
		if(r&1) res=res*A;
		A=A*A;
		r>>=1;
	}
	return res;
}

ll R[111];

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n,l,m;
	scanf("%d %d %d",&n,&l,&m); //cin>>n>>l>>m;

	for(int i=0;i<n;i++)
	{
		int x;scanf("%d",&x);x%=m;
		dp[1][x]++;
	}
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x);
		x%=m;
		F[i]=x;
		cnt[x]++;
	}
	Matrix T;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			T.a[i][j] = cnt[(i+m-j)%m];
		}
	}
	T = mpow(T,l-2);
	/*
	for(int i=2;i<=l-1;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<m;k++)
			{
				dp[i][j]=add(dp[i][j],mult(cnt[k],dp[i-1][(j+m-k)%m]));
			}
			//cerr<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
		}
	}
	*/
	ll ans2=0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			R[i] = add(R[i], mult(T.a[i][j], dp[1][j]));
		}
	}
	for(int i=0;i<n;i++)
	{
		int x;scanf("%d",&x);x%=m;
		F[i]+=x;
		while(F[i]>=m) F[i]-=m;
		//ans=add(ans,dp[l-1][(m-F[i])%m]);
		ans2=add(ans2,R[(m-F[i])%m]);
	}
	//cout<<ans<<'\n';
	printf("%lld\n",ans2);
}