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

const int N = 202222;
string s; 
vi zeroes;
int cnt[N+10];

int getzeroes(int l, int r)
{
	if(l==0) return cnt[r];
	else return cnt[r]-cnt[l-1];
}

struct H2 {
	string T;

	long long mod = 1000000009LL;
 
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
 
	long long base = 10000019;
	long long val[222222];
	long long invPow[222222];
 
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
		for(int i = 2; i <= 222220; i++)
			invPow[i] = (invPow[i-1] * invPow[1]) % mod;
		val[0] = 0;
		long long weight = 1;
		for(int i = 0; i < T.length(); i++)
		{
			val[i+1] = (val[i] + (long long)T[i] * weight) % mod;
			weight = (weight * base) % mod;
		}
	}
 
};
 
 
struct H1 {
	string T;
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
 
	long long base = 22222223;
	long long val[222222];
	long long invPow[222222];
 
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
		for(int i = 2; i <= 222220; i++)
			invPow[i] = (invPow[i-1] * invPow[1]) % mod;
		val[0] = 0;
		long long weight = 1;
		for(int i = 0; i < T.length(); i++)
		{
			val[i+1] = (val[i] + (long long)T[i] * weight) % mod;
			weight = (weight * base) % mod;
		}
	}
 
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		cnt[i]=(s[i]=='0');
		if(s[i]=='0') zeroes.pb(i);
		if(i) cnt[i]+=cnt[i-1];
	}
	H1 h1[2]; H2 h2[2];
	for(int j=0;j<2;j++) h1[j].T=h2[j].T=string(cnt[n-1],'$');
	int ptr=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			for(int j=0;j<2;j++)
			{
				h1[j].T[ptr] = h2[j].T[ptr] = ((i+j)&1)+'0';
			}
			ptr++;
		}
	}
	h1[0].prepare(); h1[1].prepare(); h2[0].prepare(); h2[1].prepare();
	int q; cin>>q;
	for(int z=0;z<q;z++)
	{
		int u,v,len; cin>>u>>v>>len; u--; v--;
		if(getzeroes(u,u+len-1)!=getzeroes(v,v+len-1)){cout<<"No\n"; continue;}
		if(getzeroes(u,u+len-1)==0){cout<<"Yes\n"; continue;}
		int za = lower_bound(zeroes.begin(),zeroes.end(),u)-zeroes.begin();
		int zb = lower_bound(zeroes.begin(),zeroes.end(),v)-zeroes.begin();
		if(((zeroes[za]-u)&1)!=((zeroes[zb]-v)&1))
		{
			cout<<"No\n"; continue;
		}
		int totz = getzeroes(u,u+len-1);
		//cout<<h1[0].getHash(u,len)<<' '<<h1[(u+v)&1].getHash(v,len)<<'\n';
		if(h1[0].getHash(za,totz)==h1[(u+v)&1].getHash(zb,totz))
		{
			if(h2[0].getHash(za,totz)==h2[(u+v)&1].getHash(zb,totz))
			{
				cout<<"Yes\n"; continue;
			}
			else
			{
				cout<<"No\n"; continue;
			}
		}
		else
		{
			cout<<"No\n"; continue;
		}
	}
}