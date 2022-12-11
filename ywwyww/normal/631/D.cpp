#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<cmath>
#include<functional>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void sort(int &a,int &b)
{
	if(a>b)
		swap(a,b);
}
void open(const char *s)
{
#ifndef ONLINE_JUDGE
	char str[100];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
	sprintf(str,"%s.out",s);
	freopen(str,"w",stdout);
#endif
}
int rd()
{
	int s=0,c;
	while((c=getchar())<'0'||c>'9');
	do
	{
		s=s*10+c-'0';
	}
	while((c=getchar())>='0'&&c<='9');
	return s;
}
int upmin(int &a,int b)
{
	if(b<a)
	{
		a=b;
		return 1;
	}
	return 0;
}
int upmax(int &a,int b)
{
	if(b>a)
	{
		a=b;
		return 1;
	}
	return 0;
}
struct ch
{
	char c;
	ll x;
};
int operator ==(ch a,ch b)
{
	return a.c==b.c&&a.x==b.x;
}
int operator !=(ch a,ch b)
{
	return a.c!=b.c||a.x!=b.x;
}
ch a[200010];
ch b[200010];
int n,m;
void solve1()
{
	ll ans=0;
	int i;
	for(i=1;i<=n;i++)
		if(a[i].c==b[1].c&&a[i].x>=b[1].x)
			ans+=a[i].x-b[1].x+1;
	printf("%I64d\n",ans);
}
void solve2()
{
	int ans=0;
	int i;
	for(i=1;i<n;i++)
		if(a[i].c==b[1].c&&a[i+1].c==b[2].c&&a[i].x>=b[1].x&&a[i+1].x>=b[2].x)
			ans++;
	printf("%d\n",ans);
}
int fail[200010];
int c[200010];
int main()
{
	open("cf631d");
	scanf("%d%d",&n,&m);
	int i;
	char c;
	int x;
	for(i=1;i<=n;i++)
	{
		scanf("%d-%c",&x,&c);
		if(i>1&&c==a[i-1].c)
		{
			i--;
			n--;
			a[i].x+=x;
		}
		else
		{
			a[i].c=c;
			a[i].x=x;
		}
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d-%c",&x,&c);
		if(i>1&&c==b[i-1].c)
		{
			i--;
			m--;
			b[i].x+=x;
		}
		else
		{
			b[i].c=c;
			b[i].x=x;
		}
	}
	if(m<=2)
	{
		if(m==1)
			solve1();
		else
			solve2();
		return 0;
	}
	ch first=b[1],last=b[m];
	for(i=1;i<=m-2;i++)
		b[i]=b[i+1];
	m-=2;
	fail[1]=0;
	for(i=2;i<=m;i++)
	{
		fail[i]=fail[i-1];
		while(fail[i]&&b[i]!=b[fail[i]+1])
			fail[i]=fail[fail[i]];
		if(b[fail[i]+1]==b[i])
			fail[i]++;
	}
	int j=0;
	int ans=0;
	for(i=1;i<=n;i++)
	{
		while(j&&a[i]!=b[j+1])
			j=fail[j];
		if(a[i]==b[j+1])
			j++;
		if(j==m)
		{
			if(i-m+1>=2&&i<=n-1&&a[i-m].c==first.c&&a[i-m].x>=first.x&&a[i+1].c==last.c&&a[i+1].x>=last.x)
				ans++;
			j=fail[j];
		}
	}
	printf("%d\n",ans);
	return 0;
}