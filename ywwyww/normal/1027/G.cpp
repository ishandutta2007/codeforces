#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<iostream>
//using namespace std;
using std::min;
using std::max;
using std::swap;
using std::sort;
using std::reverse;
using std::random_shuffle;
using std::lower_bound;
using std::upper_bound;
using std::unique;
using std::vector;
using std::cin;
using std::cout;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
int rd(){int s=0,c,b=0;while(((c=getchar())<'0'||c>'9')&&c!='-');if(c=='-'){c=getchar();b=1;}do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');return b?-s:s;}
void put(int x){if(!x){putchar('0');return;}static int c[20];int t=0;while(x){c[++t]=x%10;x/=10;}while(t)putchar(c[t--]+'0');}
int upmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
int upmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
const int N=100010;
ll c[N];
int cnt1;
ll d[N];
int cnt2;
ll n,x;
ll phi[N];
ll mul(ll a,ll b,ll c)
{
	ll temp=(a*b-(ll)((long double)a/c*b+1.0e-8)*c);
	return temp>=0?(temp>=c?temp-c:temp):temp+c;
}
ll fp2(ll a,ll b,ll c)
{
	ll s=1;
	for(;b;b>>=1,a=mul(a,a,c))
		if(b&1)
			s=mul(s,a,c);
	return s;
}
ll fp(ll a,ll b,ll c)
{
	ll s=1;
	for(;b;b>>=1,a=a*a%c)
		if(b&1)
			s=s*a%c;
	return s;
}
vector<pll> e[N];
vector<pll> f1,f2;
int main()
{
	open("cf981h");
	cin>>n>>x;
	for(int i=1;(ll)i*i<=n;i++)
		if(n%i==0)
		{
			c[++cnt1]=i;
			if((ll)i*i!=n)
				c[++cnt1]=n/i;
		}
	ll m=n;
	for(int i=2;(ll)i*i<=n;i++)
		if(m%i==0)
		{
			d[++cnt2]=i;
			while(m%i==0)
				m/=i;
		}
	if(m!=1)
		d[++cnt2]=m;
	for(int i=1;i<=cnt2;i++)
	{
		ll y=d[i]-1;
		for(int j=2;(ll)j*j<=y;j++)
			if(y%j==0)
			{
				int s=0;
				while(y%j==0)
				{
					y/=j;
					s++;
				}
				e[i].push_back(pll(j,s));
			}
		if(y!=1)
			e[i].push_back(pll(y,1));
	}
	sort(c+1,c+cnt1+1);
	ll ans=0;
	for(int i=2;i<=cnt1;i++)
	{
		phi[i]=c[i];
		for(int j=1;j<=cnt2;j++)
			if(c[i]%d[j]==0)
				phi[i]=phi[i]/d[j]*(d[j]-1);
		ll y=x%c[i];
		f1.clear();
		for(int j=1;j<=cnt2;j++)
			if(c[i]%d[j]==0)
			{
				int s=0;
				ll temp=c[i];
				while(temp%d[j]==0)
				{
					temp/=d[j];
					s++;
				}
				for(auto v:e[j])
					f1.push_back(v);
				if(s>1)
					f1.push_back(pll(d[j],s-1));
			}
		sort(f1.begin(),f1.end());
		f2.clear();
		for(auto v:f1)
			if(!f2.empty()&&f2.back().first==v.first)
				f2.back().second+=v.second;
			else
				f2.push_back(v);
		ll s=1;
		for(auto v:f2)
		{
			ll s2=fp2(y,phi[i]/fp(v.first,v.second,0x7fffffffffffffffll),c[i]);
//			ll s3=fp2(y,v.first,c[i]);
			ll s4=1;
			for(int j=0;j<=v.second;j++)
			{	
				if(s2==1)
				{
					s*=s4;
					break;
				}
				s2=fp2(s2,v.first,c[i]);
				s4*=v.first;
			}
		}
		ans+=phi[i]/s;
	}
	ans++;
	cout<<ans;
	return 0;
}