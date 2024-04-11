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

const int C = 300011;
int cnt[333333];
const int M[3] = {int(1e9)+7, int(1e9)+9, 179426549};

struct Combi
{
	vector<int> fact;
	vector<int> ifact;
	vector<int> inv;
	vector<int> pow2;
	int MOD = -1;
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
	void init(int _n, int mod)
	{
		MOD = mod;
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
};

int D[333333];
int dp[3][333333];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	Combi combi[3];
	for(int i=0;i<3;i++)
	{
		combi[i].init(C,M[i]);
	}
	int n; cin>>n;
	int gd=0;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; 
		if(i==0) gd=x;
		else gd=__gcd(gd,x);
		cnt[x]++;
	}
	if(cnt[1]>0)
	{
		cout<<1<<'\n'; return 0;
	}
	if(gd>1)
	{
		cout<<-1<<'\n'; return 0;
	}
	for(int i=1;i<=C;i++)
	{
		cnt[i]=min(cnt[i],1);
	}
	for(int i=1;i<=C;i++)
	{
		for(int j=i;j<=C;j+=i)
		{
			D[i]+=cnt[j];
		}
		//if(D[i]>0) cerr<<i<<' '<<D[i]<<'\n';
	}
	n=0;
	for(int i=1;i<=C;i++)
	{
		n+=cnt[i];
	}
	for(int c=2;c<=10;c++)
	{
		int ans[3] = {0,0,0};
		for(int i=0;i<3;i++)
		{
			ans[i] = combi[i].choose(n,c);
			//cerr<<c<<' '<<i<<' '<<ans[i]<<'\n';
		}
		for(int md=0;md<3;md++)
		{
			for(int i=1;i<=C;i++)
			{
				dp[md][i] = combi[md].choose(D[i], c);
				//if(md==0&&dp[md][i]>0) cerr<<c<<' '<<i<<' '<<dp[md][i]<<'\n';
			}
		}
		for(int md=0;md<3;md++)
		{
			for(int i=C;i>=2;i--)
			{
				for(int j=2*i;j<=C;j+=i)
				{
					dp[md][i] = combi[md].add(dp[md][i], M[md] - dp[md][j]);
				}
				ans[md] = combi[md].add(ans[md], M[md] - dp[md][i]);
			}
		}
		if(ans[0]==0&&ans[1]==0&&ans[2]==0) continue;
		cout<<c<<'\n'; return 0;
	}
}