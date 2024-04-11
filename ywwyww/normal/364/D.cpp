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
ll a[1000010];
int n;
ll ans=0;
ll d[1000010];
ll c[1000010];
ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}
void choose(ll x)
{
	int m=0;
	ll i;
	for(i=1;i*i<=x;i++)
		if(x%i==0)
		{
			d[++m]=i;
			if(i*i!=x)
				d[++m]=x/i;
		}
	sort(d+1,d+m+1);
	for(i=1;i<=m;i++)
		c[i]=0;
	for(i=1;i<=n;i++)
		c[lower_bound(d+1,d+m+1,gcd(a[i],x))-d]++;
	int j;
	for(i=m;i>=1;i--)
	{
		int s=0;
		for(j=i;j<=m;j++)
			if(d[j]%d[i]==0)
				s+=c[j];
		if(s>=(n+1)/2)
		{
			ans=max(ans,d[i]);
			return;
		}
	}
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(i=1;i<=10;i++)
		choose(a[(rand()*100+rand())%n+1]);
	printf("%I64d\n",ans);
	return 0;
}