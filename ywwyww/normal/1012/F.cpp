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
const int N=30;
int n,p;
struct trip
{
	int s,l,t,id;
};
trip a[N];
trip b[N];
int cmp1(trip a,trip b)
{
	return a.s<b.s;
}
int cmp2(trip a,trip b)
{
	return a.t<b.t;
}
const int inf=0x7f7f7f7f;
const int M=22;
int f[1<<M];
int g[1<<M];
int h[1<<M];
int l[1<<M];
void dp()
{
	memset(f,0x7f,sizeof f);
	f[0]=1;
	for(int i=0;i<1<<n;i++)
	{
		if(f[i]==inf)
			continue;
		int now=1;
		int ti=f[i];
		int gone=0;
		for(int j=1;j<=n;j++)
			if(!(i&(1<<(b[j].id-1))))
			{
				while(now<=n&&ti+b[j].t>=a[now].s)
				{
					if(!(i&(1<<(a[now].id-1))))
					{
						if(a[now].s<=ti&&a[now].s+a[now].l-1>=ti)
							ti=a[now].s+a[now].l;
						gone|=1<<(a[now].id-1);
						now++;
					}
					else
					{
						gone|=1<<(a[now].id-1);
						ti=max(ti,a[now].s+a[now].l);
						now++;
					}
				}
				if(now<=n&&!(gone&(1<<(b[j].id-1))))
					if(upmin(f[i|(1<<(b[j].id-1))],ti+b[j].t))
					{
						g[i|(1<<(b[j].id-1))]=i;
						h[i|(1<<(b[j].id-1))]=ti;
						l[i|(1<<(b[j].id-1))]=b[j].id;
					}
			}
	}
}
int s1[N],s2[N];
void output(int x,int y)
{
	while(x)
	{
		s1[l[x]]=y;
		s2[l[x]]=h[x];
		x=g[x];
	}
}
int main()
{
	open("cf1012f");
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].s,&a[i].l,&a[i].t);
		a[i].id=i;
		b[i]=a[i];
	}
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n+1,cmp2);
	for(int i=2;i<=n;i++)
		if(a[i].s<=a[i-1].s+a[i-1].l-1)
		{
			printf("NO\n");
			return 0;
		}
	dp();
	if(p==1)
	{
		if(f[(1<<n)-1]<inf)
		{
			printf("YES\n");
			output((1<<n)-1,1);
			for(int i=1;i<=n;i++)
				printf("%d %d\n",s1[i],s2[i]);
			return 0;
		}
	}
	else
	{
		for(int i=0;i<1<<n;i++)
			if(f[i]<inf&&f[(1<<n)-1-i]<inf)
			{
					printf("YES\n");
					output(i,1);
					output((1<<n)-1-i,2);
					for(int i=1;i<=n;i++)
						printf("%d %d\n",s1[i],s2[i]);
					return 0;
			}
	}
	printf("NO\n");
	return 0;
}