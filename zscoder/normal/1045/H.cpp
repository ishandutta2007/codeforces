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
	
string subtract1(string x)
{
	int pos=int(x.length())-1;
	for(int i=int(x.length())-1;i>=0;i--)
	{
		if(x[i]=='1')
		{
			pos=i; break;
		}
	}
	x[pos]='0';
	for(int i=pos+1;i<x.length();i++) x[i]='1';
	int beg=0;
	for(int i=0;i<x.length();i++)
	{
		if(x[i]=='1'){beg=i; break;}
	}
	x=x.substr(beg,int(x.length())-beg);
	return x;
}

int f(int a, int b)
{
	if(a<0||b<0) return 0;
	if(a==0&&b==0) return 1;
	return choose(a+b-1,a);
}

int calc(int minlen, int maxlen, int firstdig, int c[][2], int isfront) //counts # of strings with length <= maxlen, and extra firstdig firstdig
{
	int n = c[0][0]+c[0][1]+c[1][0]+c[1][1];
	if(c[0][0]<0||c[0][1]<0||c[1][0]<0||c[1][1]<0) return 0;
	if(n==0&&maxlen==0) return 1;
	if(n>maxlen||n<minlen) return 0;
	if(n==1)
	{
		if(c[firstdig][0]==1||c[firstdig][1]==1) return 1;
		else return 0;
	}
	int c1 = c[firstdig][firstdig^1]; int c2 = c[firstdig^1][firstdig];
	if(c1<c2) return 0;
	if(c1-c2>=2) return 0;
	//c1-c2 is in [0,1]
	int ext[2] = {c[0][0],c[1][1]};
	int cnt[2] = {0,0};
	cnt[firstdig] = c2+(isfront==0); //firstdig is always 0
	cnt[firstdig^1] = c1;
	//cerr<<ext[0]<<' '<<cnt[0]<<' '<<ext[1]<<' '<<cnt[1]<<'\n';
	if(cnt[0]<0||cnt[1]<0) return 0;
	return mult(f(ext[0],cnt[0]),f(ext[1],cnt[1]));
}

int solve(string s, int c[][2])
{
	if(c[0][0]+c[0][1]+c[1][0]+c[1][1]==0)
	{
		if(s=="0") return 1;
		else return 2;
	}
	int ans = 0;
	int n = s.length();
	int z[2][2]={};
	for(int i=0;i+1<s.length();i++)
	{
		z[s[i]-'0'][s[i+1]-'0']++;
	}
	bool pos=1;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(z[i][j]!=c[i][j]){pos=0;}
		}
	}
	if(pos) ans++;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			int d[2][2]={{c[0][0],c[0][1]},{c[1][0],c[1][1]}};
			int firstdig=0;
			if(i==0)
			{
				d[0][1]++;
			}
			else
			{
				d[s[i-1]-'0'][0]--; 
			}
			//cerr<<"DO "<<d[0][0]<<' '<<d[0][1]<<' '<<d[1][0]<<' '<<d[1][1]<<'\n';
			ans = add(ans, calc((i==0?0:n-i-1),n-i-1,firstdig,d,(i==0?1:0)));
		}
		if(i>0) c[s[i-1]-'0'][s[i]-'0']--;
	}
	//check if s itself is a solution
	return ans;
}

string convert(int bin)
{
	vi digits;
	while(bin)
	{
		digits.pb(bin&1); bin>>=1;
	}
	if(digits.empty()) digits.pb(0);
	reverse(digits.begin(),digits.end());
	string s;
	for(int d:digits) s+=d+'0';
	return s;
}

ll rnd()
{
	ll x=rand()<<15;
	x^=rand();
	return x;
}

int solve_naive(string s, int c[][2])
{
	int aa = 0;
	for(int i=0;i<s.length();i++)
	{
		aa<<=1;
		if(s[i]=='1') aa++;
	}
	int ans = 0;
	for(int z=1;z<=aa;z++)
	{
		string t = convert(z);
		int d[2][2]={};
		for(int i=0;i+1<t.length();i++)
		{
			d[t[i]-'0'][t[i+1]-'0']++;
		}
		bool pos=1;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				if(d[i][j]!=c[i][j]){pos=0; break;}
			}
			if(!pos) break;
		}
		if(pos) ans++;
	}
	return ans;
}

const bool DEBUG=0;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(222222);
	for(int cc=1;;cc++)
	{
		string L,R; int unused=0; string oriL;
		if(!DEBUG) cin>>L>>R;
		else
		{
			int l = rnd()%int(50000)+1;
			int r = rnd()%int(50000)+1;
			if(l>r) swap(l,r);
			unused=rnd()%(r-l+1)+l;
			L=convert(l); R=convert(r);
		}
		oriL=L;
		L=subtract1(L);
		int c[2][2]={};
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				if(!DEBUG) cin>>c[i][j];
				else
				{
					if(i>0||j>0) continue;
					string tmp = convert(unused);
					for(int k=0;k+1<tmp.length();k++)
					{
						c[tmp[k]-'0'][tmp[k+1]-'0']++;
					}
				}
			}
		}
		int d[2][2]={{c[0][0],c[0][1]},{c[1][0],c[1][1]}};
		int ans = solve(R,c);
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				c[i][j]=d[i][j];
			}
		}
		//cerr<<"ANS : "<<ans<<'\n';
		ans = add(ans, MOD-solve(L,c));
		//cerr<<"ANS 2 : "<<ans<<'\n';
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				c[i][j]=d[i][j];
			}
		}
		if(!DEBUG)
		{
			cout<<ans<<'\n'; return 0;
		}
		cerr<<"MY ANS : "<<ans<<'\n';
		int ans_naive=0;
		ans_naive=solve_naive(R,c);
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				c[i][j]=d[i][j];
			}
		}
		ans_naive=add(ans_naive,MOD-solve_naive(L,c));
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				c[i][j]=d[i][j];
			}
		}
		cerr<<"NAIVE ANS : "<<ans_naive<<'\n';
		if(ans!=ans_naive)
		{
			freopen("self-exploration.in","w",stdout);
			cout<<oriL<<'\n'<<R<<'\n'<<c[0][0]<<'\n'<<c[0][1]<<'\n'<<c[1][0]<<'\n'<<c[1][1]<<'\n';
			return 0;
		}
		cerr<<"Case #"<<cc<<" complete\n";
	}
}