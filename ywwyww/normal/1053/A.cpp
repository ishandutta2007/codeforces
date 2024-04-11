#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
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
void open2(const char *s){
#ifdef DEBUG
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
int rd(){int s=0,c,b=0;while(((c=getchar())<'0'||c>'9')&&c!='-');if(c=='-'){c=getchar();b=1;}do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');return b?-s:s;}
void put(int x){if(!x){putchar('0');return;}static int c[20];int t=0;while(x){c[++t]=x%10;x/=10;}while(t)putchar(c[t--]+'0');}
int upmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
int upmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}
ll sx[4],sy[4];
ll n,m,k;
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	if(n*m*2%k)
	{
		printf("NO\n");
		return 0;
	}
	ll _n=n,_m=m;
	ll d=gcd(n,k);
	n/=d;
	k/=d;
	d=gcd(m,k);
	m/=d;
	k/=d;
	if(k>1)
		;
	else if(n*2<=_n)
		n*=2;
	else
		m*=2;
	sx[1]=0;
	sy[1]=0;
	sx[2]=n;
	sy[2]=0;
	sx[3]=0;
	sy[3]=m;
	printf("YES\n");
	for(int i=1;i<=3;i++)
		printf("%I64d %I64d\n",sx[i],sy[i]);
	return 0;
}