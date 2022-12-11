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
int bitcount(ll v)
{
	int s=0;
	for(;v;v>>=1)
		if(v&1)
			s++;
	return s;
}
const int N=300010;
ll a[N],c[N],e[N];
int n;
ll d[2];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		c[i]=c[i-1]+(e[i]=bitcount(a[i]));
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int num=0,mx=0;
		for(int j=i;j<=n&&j<=i+69;j++)
		{
			int s=e[j];
			num+=s;
			mx=max(mx,s);
			if(!(num&1)&&mx*2<=num)
				ans++;
		}
		if(i>=71)
		{
			int x=i-71;
			d[c[x]&1]++;
		}
		ans+=d[c[i]&1];
	}
	printf("%I64d\n",ans);
	return 0;
}