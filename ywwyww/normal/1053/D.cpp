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
const ll p=1000000007;
const int N=2000010;
int pri[N],cnt,b[N];
int c[N];
int s[N];
int a[N];
void init()
{
	int maxn=2000000;
	for(int i=2;i<=maxn;i++)
	{
		if(!b[i])
		{
			pri[++cnt]=i;
			c[i]=i;
		}
		for(int j=1;j<=cnt&&i*pri[j]<=maxn;j++)
		{
			b[i*pri[j]]=1;
			c[i*pri[j]]=pri[j];
			if(i%pri[j]==0)
				break;
		}
	}
}
pii d[N];
pii s1[N],s2[N];
int n,t;
int bb[N];
int main()
{
	open("d");
	scanf("%d",&n);
	int flag=0;
	init();
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,std::greater<int>());
	for(int i=1;i<=n;i++)
	{
		if(s[a[i]]==0)
		{
			s[a[i]]++;
			if(a[i]==2)
				s[a[i]]++;
			bb[i]=2;
			if(!s1[a[i]].first)
			{
				if(pii(a[i],i)>s1[a[i]])
				{
					s2[a[i]]=s1[a[i]];
					s1[a[i]]=pii(a[i],i);
				}
				else
					s2[a[i]]=max(s2[a[i]],pii(a[i],i));
				continue;
			}
		}
		if(s[a[i]]==1)
		{
			s[a[i]]++;
			t=0;
			for(int j=a[i]-1;j!=1;j/=c[j])
				if(!t||d[t].first!=c[j])
					d[++t]=pii(c[j],c[j]);
				else
					d[t].second*=c[j];
			for(int j=1;j<=t;j++)
			{
				int v=d[j].first;
				d[j].first=d[j].second;
				d[j].second=i;
				if(d[j]>s1[v])
				{
					s2[v]=s1[v];
					s1[v]=d[j];
				}
				else
					s2[v]=max(s2[v],d[j]);
			}
			bb[i]=1;
		}
		else
			flag=1;
	}
	for(int i=1;i<=n&&!flag;i++)
		if(bb[i]==2)
		{
			if(s1[a[i]].second==i)
			{
				if(s2[a[i]].first==s1[a[i]].first)
				{
					flag=1;
					break;
				}
			}
			else
			{
				flag=1;
				break;
			}
		}
		else if(bb[i]==1)
		{
			t=0;
			for(int j=a[i]-1;j!=1;j/=c[j])
				if(!t||d[t].first!=c[j])
					d[++t]=pii(c[j],c[j]);
				else
					d[t].second*=c[j];
			int ff=1;
			for(int j=1;j<=t;j++)
			{
				int v=d[j].first;
				if(s1[v].second==i)
				{
					if(s2[v].first==s1[v].first)
						;
					else	
						ff=0;
				}
			}
			if(ff)
			{
				flag=1;
				break;
			}
		}
	ll ans=1;
	for(int i=1;i<=2000000;i++)
		if(s1[i].first)
			ans=ans*s1[i].first%p;
	if(flag)
		ans++;
	printf("%I64d\n",ans);
	return 0;
}