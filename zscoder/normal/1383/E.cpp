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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
void radd(int &a, int b)
{
	a=add(a,b); 
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
void rmult(int &a, int b)
{
	a=mult(a,b);
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

struct Fenwick
{
	vector<int> t;
    Fenwick(int n)
    {
        t.assign(n+1,0);
    }
    void reset(int n)
    {
		t.assign(n+1, 0);
	}
    void update(int p, int v)
    {
        for (; p < (int)t.size(); p += (p&(-p))) 
        {
			t[p] = add(t[p],v);
		}
    }
    int query(int r) //finds [1, r] sum
    {                     
        int sum = 0;
        for (; r; r -= (r&(-r))) 
        {
			sum=add(sum,t[r]);
		}
        return sum;
    }
    int query(int l, int r) //finds [l, r] sum
    {
		if(l == 0) return query(r);
		return add(query(r), MOD- query(l-1));
	}
};

int dp[1011111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s; 
	init(1011111);
	int n=s.length();
	Fenwick fen1(n+10);
	Fenwick fen(n+10);
	int run = 0; 
	deque<int> a;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			//if(i==0&&s[i]=='1') continue;
			a.pb(run);
			run=0;
		}
		else
		{
			run++;
		}
	}
	a.pb(run);
	//if(run>0) a.pb(run);
	if(a.size()==1)
	{
		cout<<s.length()<<'\n';
		return 0; //all zeroes
	}
	int coeff = mult(a[0]+1,a.back()+1);
	a.pop_front(); a.pop_back();
	map<int,int> S;
	n=a.size();
	if(n==0)
	{
		cout<<coeff<<'\n';
		return 0;
	}
	dp[0] = a[0]+1;
	//S.insert({a[0],-1});
	//fen1.update(a[0]+1,1);
	//fen.update(a[0]+1,1); //increment position by 1
	S[a[0]]=1;
	int totsum = 1;
	for(int i=1;i<n;i++)
	{
		int v=a[i];
		//some old j<i
		if(i>0)
		{
			dp[i]=add(dp[i],mult(dp[i-1],v+1)); //extend from immediate previous
		}
		//cerr<<i<<' '<<dp[i]<<'\n';
		S[v]=add(S[v],dp[i-1]);
		while(!S.empty())
		{
			int val = (*S.begin()).fi; int dpsum = (*S.begin()).se;
			if(val>=v) break;
			radd(dp[i],mult(v-val,dpsum));
			radd(S[v],dpsum);
			S.erase(val);
		}
		//cerr<<i<<' '<<dp[i]<<'\n';
		/*
		//extract answer
		radd(dp[i], add(mult(fen1.query(v+1), v+1), MOD - fen.query(v+1)));
		while(!S.empty()&&S.
		*/
		
	}
	int ans=1;
	for(int i=0;i<n;i++) ans=add(ans,dp[i]);
	ans=mult(ans,coeff);
	cout<<ans<<'\n';
	/*
	{
		memset(dp,0,sizeof(dp));
		dp[0]=a[0]+1;
		for(int i=1;i<n;i++)
		{
			int v=a[i];
			dp[i]=mult(dp[i-1],v+1);
			for(int j=0;j<i;j++)
			{
				int ddval = 1;
				if(j>0) ddval = dp[j-1];
				int maxval = 0;
				for(int k=j;k<i;k++)
				{
					maxval = max(maxval,a[k]);
				}
				//must be in [maxval+1,v]
				if(v>=maxval+1) radd(dp[i],mult(ddval,v-maxval));
			}
		}		
		int ans=0;
		for(int i=0;i<n;i++) radd(ans,dp[i]);
		cout<<ans<<'\n';
	}
	*/
	//ans minus 1 (0)
}