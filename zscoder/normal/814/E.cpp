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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int MOD = 1e9 + 7;

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

int d[51];

ll dp[51][51][51][51];
ll dp2[51][51][51];
int n; 
ll choose[1551][1551];
ll fact[1551];
ll c(int n, int r)
{
	if(n<r) return 0;
	if(r==0) return 1;
	if(choose[n][r]!=-1) return choose[n][r];
	return (choose[n][r]=add(c(n-1,r),c(n-1,r-1)));
}

ll pow2[1001];
ll ipow2[1001];
ll ifact[1001];
ll modpow(ll a, ll b)
{
	ll r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}

int cnt[1001];
int sum(int l, int r)
{
	if(l==0) return cnt[r];
	else return cnt[r]-cnt[l-1];
}

ll dp3[51][51];
ll dp4[51];

ll solve3(int c1)
{
	if(c1==0) return 1;
	if(c1<3) return 0;
	if(dp4[c1]!=-1) return dp4[c1];
	ll ans=0;
	for(int i = 3; i <= c1; i++)
	{
		ans=add(ans,mult(mult(ipow2[1],fact[i-1]),mult(c(c1-1,i-1),solve3(c1-i))));
	}
	return (dp4[c1]=ans);
}

ll solve2(int c1, int c2)
{
	if(c1<0||c2<0) return 0;
	if(dp3[c1][c2]!=-1) return dp3[c1][c2];
	if(c1+c2==0) return 1;
	ll ans=0;
	if(c1>0)
	{
		ll res=0;
		res=mult(c1-1,solve2(c1-2,c2));
		res=add(res,mult(c2,solve2(c1,c2-1)));
		ans=res;
	}
	else
	{
		if(c2<=2) return 0;
		ans=solve3(c2);
		//ans=mult(fact[c2-1],ipow2[1]);
	}
	return (dp3[c1][c2]=ans);
}

ll solve(int c1, int c2, int d1, int d2)
{
	if(dp[c1][c2][d1][d2]!=-1) return dp[c1][c2][d1][d2];
	ll ans=0;
	int ctmp1,ctmp2,dtmp1,dt2;
	ctmp1=c1;ctmp2=c2;dtmp1=d1;dt2=d2;
	ll coeff=c(c2,d2);
	c2-=d2;
	if(c2<0) return 0;
	for(int i = 0; i <= min(c1,d1); i++)
	{
		//choose i of c1 to become d1, choose d1 - i of c2 to become d1
		if(d1-i<=c2)
		{
			ll coeff2 = mult(coeff,mult(c(c1,i),c(c2,d1-i)));
			//cerr<<"COEFF : "<<i<<' '<<coeff2<<'\n';
			c1-=i;
			c2-=(d1-i);
			c1+=(d1-i);
			
			//c1 degree 1 vertices, c2 degree 2 vertices, form how many graphs?
			ans=add(ans,mult(coeff2,solve2(c1,c2)));
			
			c1+=i;
			c1-=(d1-i);
			c2+=(d1-i);
		}
	}
	return (dp[ctmp1][ctmp2][dtmp1][dt2]=ans);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp3,-1,sizeof(dp3));
	fact[0]=1;
	ifact[0]=ipow2[0]=1;
	pow2[0]=1;
	for(int i=1;i<=1000;i++)
	{
		pow2[i]=mult(pow2[i-1],2);
		ipow2[i]=modpow(pow2[i],MOD-2);
	}
	for(int i=1;i<=1000;i++) 
	{
		fact[i]=mult(fact[i-1],i);
		ifact[i]=modpow(fact[i],MOD-2);
	}
	memset(choose,-1,sizeof(choose));
	memset(dp,-1,sizeof(dp));
	memset(dp4,-1,sizeof(dp4));
	//
	//return 0;
	cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>>d[i];
		if(d[i]==2) cnt[i]=1;
		if(i>0) cnt[i]+=cnt[i-1];
	}
	//cerr<<solve(2,2,0,0)<<'\n';
	//==cerr<<solve2(2,2)<<'\n';
	if(d[0]==2)
	{
		dp2[0][0][1]=1;
	}
	else
	{
		if(n<=3)
		{
			cout<<0<<'\n';
			return 0;
		}
		//nothing
		dp2[3][(d[1]==2)+(d[2]==2)+(d[3]==2)][(d[1]==3)+(d[2]==3)+(d[3]==3)]++;
		//1-2
		dp2[3][(d[1]==3)+(d[2]==3)+(d[3]==2)][(d[1]==4)+(d[2]==4)+(d[3]==3)]++;
		//2-3
		dp2[3][(d[1]==2)+(d[2]==3)+(d[3]==3)][(d[1]==3)+(d[2]==4)+(d[3]==4)]++;
		//1-3
		dp2[3][(d[1]==3)+(d[2]==2)+(d[3]==3)][(d[1]==4)+(d[2]==3)+(d[3]==4)]++;
		//1-2&2-3
		if(d[2]>=3) dp2[3][(d[1]-2==1)+(d[2]-3==1)+(d[3]-2==1)][0]++;
		//1-2&1-3
		if(d[1]>=3) dp2[3][(d[1]-3==1)+(d[2]-2==1)+(d[3]-2==1)][0]++;
		//1-3&2-3
		if(d[3]>=3) dp2[3][(d[1]-2==1)+(d[2]-2==1)+(d[3]-3==1)][0]++;
		//1-2,1-3,2-3
		if(d[1]>=3&&d[2]>=3&&d[3]>=3) dp2[3][0][0]++;
	}
	for(int j = 0; j < n; j++)
	{
		for(int k = 0; k < n; k++)
		{
			for(int l = 0; l < n; l++)
			{
				//if(dp2[i][j][k][l]>0) cerr<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<dp2[i][j][k][l]<<'\n';
				if(k==0&&l==0) continue;
				if(dp2[j][k][l]>0)
				{
					//cerr<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<dp2[i][j][k][l]<<'\n';
					if(j+k+2*l<n)
					{
						ll coeff = mult(c(k+2*l,k),mult(fact[k],mult(ipow2[l],fact[2*l]))); //number of ways to pair the children to some parents
						//dp2[i+1][j+k+2*l]
						//[j+1,j+k+2*l] are the people involved
						int c1 = sum(j+1,j+k+2*l); //# of degree 1 in this range
						int c2 = k+2*l - c1; //# of degree 2 in this range
						//cerr<<coeff<<' '<<c1<<' '<<c2<<'\n';
						for(int u=0;u<=c1+c2;u++)
						{
							for(int v=0;v<=c2;v++)
							{
								if(j+k+2*l+u+2*v<n) 
								{
									//cerr<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<c1<<' '<<c2<<' '<<u<<' '<<v<<' '<<solve(c1,c2,u,v)<<'\n';
									dp2[j+k+2*l][u][v] = add(dp2[j+k+2*l][u][v], mult(dp2[j][k][l],mult(coeff,solve(c1,c2,u,v))));
								}
							}
						}
					}
				}
			}
		}
	}
	ll ans=dp2[n-1][0][0];
	cout<<ans<<'\n';
}