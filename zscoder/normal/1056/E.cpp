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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x)
{
	return uniform_int_distribution<int>(0, x)(rng);
}
const int C = 1000111;
string s,t; 
ll F[2];

struct H1 {
 
	long long mod = 1000000007LL;
 
	long long power(long long a, long long b)
	{
		long long ret = 1;
		while(b)
		{
			if(b&1)
				ret = (ret * a) % mod;
			a = (a * a) % mod;
			b /= 2;
		}
		return ret;
	}
 
 
	long long inv(long long x)
	{
		return power(x, mod - 2);
	}
 
	long long base = F[0]+100001;
	long long val[C+10];
	long long invPow[C+10];
 
	long long getHash(int start, int len)
	{
		long long v = val[start + len] - val[start];
		v %= mod;
		if(v < 0) v += mod;
		v *= invPow[start];
		v %= mod;
		return v;
	}
 
 
 
	void prepare()
	{
		invPow[0] = 1;
		invPow[1] = inv(base);
		for(int i = 2; i <= C; i++)
			invPow[i] = (invPow[i-1] * invPow[1]) % mod;
		val[0] = 0;
		long long weight = 1;
		for(int i = 0; i < t.length(); i++)
		{
			val[i+1] = (val[i] + (long long)t[i] * weight) % mod;
			weight = (weight * base) % mod;
		}
	}
 
};
struct H2 {
 
	long long mod = 1000000007LL;
 
	long long power(long long a, long long b)
	{
		long long ret = 1;
		while(b)
		{
			if(b&1)
				ret = (ret * a) % mod;
			a = (a * a) % mod;
			b /= 2;
		}
		return ret;
	}
 
 
	long long inv(long long x)
	{
		return power(x, mod - 2);
	}
 
	long long base = F[1]+100001;
	long long val[C+10];
	long long invPow[C+10];
 
	long long getHash(int start, int len)
	{
		long long v = val[start + len] - val[start];
		v %= mod;
		if(v < 0) v += mod;
		v *= invPow[start];
		v %= mod;
		return v;
	}
 
 
 
	void prepare()
	{
		invPow[0] = 1;
		invPow[1] = inv(base);
		for(int i = 2; i <= C; i++)
			invPow[i] = (invPow[i-1] * invPow[1]) % mod;
		val[0] = 0;
		long long weight = 1;
		for(int i = 0; i < t.length(); i++)
		{
			val[i+1] = (val[i] + (long long)t[i] * weight) % mod;
			weight = (weight * base) % mod;
		}
	}
 
};

ll pre[122222][2];
H1 h1;
H2 h2;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	F[0]=rnd(int(1e6))+100110;
	F[1]=rnd(int(1e6))+101100;
	cin>>s>>t;
	ll n = t.length();
	ll cnt[2]={0,0};
	for(int i=0;i<s.length();i++) cnt[s[i]-'0']++;
	ll ans = 0;
	for(int i=0;i<s.length();i++)
	{
		if(i>0) for(int j=0;j<2;j++) pre[i][j]=pre[i-1][j];
		pre[i][s[i]-'0']++;
	}
	h1.prepare(); h2.prepare();
	for(ll len=1;len<=n;len++)
	{
		ll a = len; ll b = n - a*cnt[0];
		if(b<=0) continue;
		if(b%cnt[1]!=0) continue;
		b/=cnt[1];
		//test a, test b
		pair<ll,ll> h[2] = {{-1,-1},{-1,-1}};
		int curpos = 0; bool pos=1;
		for(int j=0;j<s.length();j++)
		{
			pair<ll,ll> curh = {-1,-1};
			if(s[j]=='0')
			{
				curh = mp(h1.getHash(curpos,a),h2.getHash(curpos,a));
			}
			else
			{
				curh = mp(h1.getHash(curpos,b),h2.getHash(curpos,b));
			}
			if(h[s[j]-'0'].fi==-1) h[s[j]-'0']=curh;
			else
			{
				if(h[s[j]-'0']!=curh){pos=0; break;}
			}
			if(s[j]=='0') curpos+=a;
			else curpos+=b;
		}
		if(pos) 
		{
			if(a==b)
			{
				if(h[0]==h[1]) continue;
			}
			ans++;
		}
	}
	cout<<ans<<'\n';
}