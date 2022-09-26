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
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

string que[111111];
int ans[111111];
vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> ipow2;
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
	ipow2.resize(_n+1);
	ipow2[0]=1;
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
	for(int i=1;i<=_n;i++)
	{
		ipow2[i]=mult(ipow2[i-1],inv[2]);
	}
}

int wc[30]; //weight of each character

struct Hash
{
 
	long long mod = 1000000007LL;
	long long base = 22222223;
	string T;
	
	Hash(ll _mod=1000000007, ll _base=22222223, string s="")
	{
		mod = _mod; base = _base; T=s;
	}
	
	void init(ll _mod, ll _base, string s)
	{
		mod = _mod; base = _base; T=s;
	}
	
	int power(int a, int b)
	{
		int ret = 1;
		while(b)
		{
			if(b&1)
				ret = (ret *1LL* a) % mod;
			a = (a *1LL* a) % mod;
			b /= 2;
		}
		return ret;
	}
 
 
	int inv(int x)
	{
		return power(x, mod - 2);
	}
 
	
	vector<int> val;
	vector<int> invPow;
	vector<int> sufval;
 
	int getHash(int start, int len)
	{
		assert(len<=T.length());
		if(len==0) return 0;
		if(start==0) return val[len];
		if(start+len==int(T.length())) return sufval[len];
		ll v = val[start + len] - val[start];
		v %= mod;
		if(v < 0) v += mod;
		v *= invPow[start];
		v %= mod;
		return v;
	}
 
 
 
	void prepare()
	{
		invPow.resize(T.length()+1,0);
		val.resize(T.length()+1,0);
		sufval.resize(T.length()+1,0);
		invPow[0] = 1;
		invPow[1] = inv(base);
		for(int i = 2; i <= T.length(); i++)
			invPow[i] = (invPow[i-1] *1LL * invPow[1]) % mod;
		val[0] = 0;
		long long weight = 1;
		for(int i = 0; i < T.length(); i++)
		{
			val[i+1] = ll(val[i] + (long long)T[i] * weight) % mod;
			weight = (weight *1LL* base) % mod;
		}
		sufval[0] = 0;
		for(int i = T.length()-1; i>=0;i--)
		{
			sufval[T.length()-i] = (sufval[T.length()-1-i]*1LL*base)%mod;
			sufval[T.length()-i] += T[i];
			sufval[T.length()-i]%=mod;
			if(sufval[T.length()-i]<0) sufval[T.length()-i]+=mod;
		}
	}
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MM[3] = {1000000033, 1000004023, 800001619};
int CC[3] = {0,0,0};
Hash H[3][21];
int lenlen[33];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(1011310);
	for(int i=0;i<3;i++)
	{
		CC[i] = 350 + uniform_int_distribution<int>(0, int(1e7))(rng);
	}
	int n,q; cin>>n>>q;
	string s; cin>>s;
	string t; cin>>t;
	const int MAX = 1000011;
	string curs = s;
	int C = 0;
	for(int i=0;i<n;i++)
	{
		lenlen[i]=curs.length();
		for(int j=0;j<3;j++)
		{
			H[j][i].init(MM[j],CC[j],curs);
			H[j][i].prepare();
		}
		if(curs.length()>=MAX) break;
		curs=curs+t[i]+curs;
		C++;
	}
	//cerr<<"VALUE OF C = "<<C<<'\n';
	vector<ii> questions;
	for(int z=0;z<q;z++)
	{
		int k; cin>>k;
		cin>>que[z];
		questions.pb({k,z});
	}
	sort(questions.begin(),questions.end());
	map<vector<int>,int> hashes;
	for(int i=0;i<s.length();i++)
	{
		for(int j=i;j<s.length();j++)
		{
			int len=j-i+1;
			vi lul;
			for(int k=0;k<3;k++)
			{
				lul.pb(H[k][0].getHash(i,len));
			}
			//cerr<<lul[0]<<' '<<lul[1]<<' '<<lul[2]<<'\n';
			hashes[lul]++;
		}
	}
	int curr=C+1;
	//answer queries in increasing fashion
	for(auto E:questions)
	{
		int id=E.se;
		int k=E.fi;
		string s = que[id];
		int res=0;
		//check number of times it appears as strict substring
		Hash F[3];
		vi purehash;
		for(int j=0;j<3;j++)
		{
			F[j].init(MM[j],CC[j],s); F[j].prepare();
			purehash.pb(F[j].getHash(0,int(s.length())));
		}
		radd(res,mult(hashes[purehash],pow2[k]));
		//ok now we have some small fry
		for(int j=0;j<=min(k-1,C);j++) //suppose t_j is the largest guy you have
		{
			for(int i=0;i<s.length();i++)
			{
				if(s[i]!=t[j]) continue;
				//cerr<<"OK "<<i<<' '<<j<<'\n';
				int lsiz = i;
				int rsiz = int(s.length())-1-i;
				if(max(lsiz,rsiz)<=lenlen[j])
				{
					//both fits!
					bool pos=1;
					for(int k=0;k<3;k++)
					{
						if(F[k].getHash(0,lsiz)!=H[k][j].getHash(lenlen[j]-lsiz,lsiz))
						{
							pos=0; break;
						}
						if(F[k].getHash(i+1,rsiz)!=H[k][j].getHash(0,rsiz))
						{
							pos=0; break;
						}
					}
					if(pos)
					{
						radd(res,pow2[k-1-j]);
					}
				}
			}
		}
		//cerr<<"CUR RES = "<<res<<'\n';
		//only those > C now
		while(curr<=k-1)
		{
			radd(wc[t[curr]-'a'],ipow2[curr]);
			curr++;
		}
		for(int i=0;i<s.length();i++)
		{
			int coeff = mult(pow2[k-1],wc[s[i]-'a']);
			int j = C;
			int lsiz = i;
			int rsiz = int(s.length())-1-i;
			//cerr<<coeff<<'\n';
			if(max(lsiz,rsiz)<=lenlen[j])
			{
				//both fits!
				bool pos=1;
				for(int k=0;k<3;k++)
				{
					if(F[k].getHash(0,lsiz)!=H[k][j].getHash(lenlen[j]-lsiz,lsiz))
					{
						pos=0; break;
					}
					if(F[k].getHash(i+1,rsiz)!=H[k][j].getHash(0,rsiz))
					{
						pos=0; break;
					}
				}
				if(pos)
				{
					radd(res,coeff);
				}
			}
		}
		ans[id]=res;
	}
	
	for(int i=0;i<q;i++)
	{
		cout<<ans[i]<<'\n';
	}
	
}