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
int rd(){int s=0,c,b=0;while(((c=getchar())<'0'||c>'9')&&c!='-');if(c=='-'){c=getchar();b=1;}do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');return b?-s:s;}
void put(int x){if(!x){putchar('0');return;}static int c[20];int t=0;while(x){c[++t]=x%10;x/=10;}while(t)putchar(c[t--]+'0');}
int upmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
int upmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
int n,k;
const int N=510;
const ll p=998244353;
ll a[N],s[N];
ll f[N],g[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		a[0]=1;
		s[0]=1;
		for(int j=1;j<=n;j++)
		{
			a[j]=s[j-1];
			if(j>i)
				a[j]=(a[j]-s[j-i-1])%p;
			s[j]=(s[j-1]+a[j])%p;
		}
		f[i]=a[n];
		g[i]=(f[i]-f[i-1])%p;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i*j<k)
				ans=(ans+g[i]*g[j])%p;
	ans=(ans*2%p+p)%p;
	printf("%I64d\n",ans);
	return 0;
}