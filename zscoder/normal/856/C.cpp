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
typedef long double ld; 
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;


vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
const int MOD = 998244353;
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	if(a<0) a+=MOD;
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
		inv[i] = inverse(i);
		fact[i]=mult(fact[i-1],i);
		ifact[i]=mult(ifact[i-1],inv[i]);
		//cerr<<fact[i]<<'\n';
	}
}

int dp[2][2011][2011][11];
int dp2[2011];

const bool DEBUG=0;
ll brute(vector<int> &vec)
{
	vi perm(int(vec.size()));
	for(int i=0;i<vec.size();i++) perm[i]=i;
	ll ans=0;
	do
	{
		int val=0;
		for(int i=0;i<vec.size();i++)
		{
			int cnt=0;
			int z=vec[perm[i]];
			while(z)
			{
				cnt++;
				z/=10;
			}
			for(int j=0;j<cnt;j++) val=(val*10)%11;
			val=(val+vec[perm[i]])%11;
		}
		val%=11;
		if(val<0) val+=11;
		if(val==0) ans++;
	}while(next_permutation(perm.begin(),perm.end()));
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(10000);
	int t; 
	int cc=0;
	if(DEBUG) t=1000000;
	else cin>>t;
	while(t--)
	{
		int n; 
		if(!DEBUG) cin>>n;
		else n=rand()%7+1;
		int cntodd[2] = {};
		int cnt[2][11]={};
		vi V[2];
		vi vec;
		for(int i=0;i<n;i++)
		{
			int x; 
			if(!DEBUG) cin>>x;
			else x=rand();
			vec.pb(x);
			int z =x;
			int dig=0;
			while(z)
			{
				dig++;
				z/=10;
			}
			if(dig&1) cntodd[1]++;
			else cntodd[0]++;
			cnt[dig&1][x%11]++;
			V[dig&1].pb(x%11);
		}
		ll ans1=0;
		if(DEBUG) ans1 = brute(vec);
		int oddneg = cntodd[1]/2;
		int gappos = cntodd[1]/2 + 1;
		int gapneg = (cntodd[1]+1)/2;
		
		for(int i=0;i<=cntodd[0];i++)
		{
			//# of negatives = i
			if(gapneg<=0) 
			{
				if(i==0) dp2[i]=1;
				else dp2[i]=0;
			}
			else dp2[i] = mult(choose(i + gapneg - 1, gapneg - 1), choose(cntodd[0] - i + gappos - 1, gappos - 1));
			//cerr<<"DP 2 : "<<i<<' '<<dp2[i]<<'\n';
		}
		
		int ans=0;
		//cerr<<oddneg<<'\n';
		
		for(int i=0;i<2;i++)
		{
			dp[i][0][0][0]=1;
			for(int j=0;j<V[i].size();j++)
			{
				for(int k=0;k<=V[i].size();k++)
				{
					for(int l=0;l<11;l++)
					{
						//cerr<<i<<' '<<j+1<<' '<<k<<' '<<l<<endl;
						dp[i][j+1][k][l] = add(dp[i][j+1][k][l], dp[i][j][k][(l+11-V[i][j])%11]);
						if(k>0) dp[i][j+1][k][l] = add(dp[i][j+1][k][l], dp[i][j][k-1][(l+V[i][j])%11]);
						//if(dp[i][j+1][k][l]>0) cerr<<"DP : "<<i<<' '<<j+1<<' '<<k<<' '<<l<<' '<<dp[i][j+1][k][l]<<'\n';
					}
				}
			}
		}
		
		for(int i=0;i<=cntodd[0];i++)
		{
			for(int j=0;j<11;j++)
			{
				//cerr<<i<<' '<<j<<endl;
				//cerr<<i<<' '<<j<<' '<<mult(dp[1][int(V[1].size())][oddneg][j],mult(fact[oddneg],fact[cntodd[1]-oddneg]))<<' '<<mult(dp[0][int(V[0].size())][i][(11-j)%11],mult(dp2[i],mult(fact[i],fact[cntodd[0]-i])))<<'\n';
				ans=add(ans,mult(mult(dp[1][int(V[1].size())][oddneg][j],mult(fact[oddneg],fact[cntodd[1]-oddneg])),mult(dp[0][int(V[0].size())][i][(11-j)%11],mult(dp2[i],mult(fact[i],fact[cntodd[0]-i])))));
			}
		}
		ans%=MOD;
		if(ans<0) ans+=MOD;
		if(DEBUG) 
		{
			cerr<<"SLOW : "<<ans1<<'\n';
			cerr<<"FAST : "<<ans<<'\n';
		}
		else
		{
			cout<<ans<<'\n';
		}
		if(DEBUG&&ans!=ans1)
		{
			freopen("eleventh-birthday.txt","w",stdout);
			cout<<1<<'\n';
			cout<<n<<'\n';
			for(int i=0;i<vec.size();i++)
			{
				cout<<vec[i]<<' ';
			}
			cout<<'\n';
			return 0;
		}
		if(DEBUG) cerr<<"Case #"<<++cc<<" complete\n";
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<11;k++)
				{
					dp[1][i][j][k]=dp[0][i][j][k]=0;
				}
			}
		}
	}
}