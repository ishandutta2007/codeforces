#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
void read(int &s)
{
	int c;
	while((c=getchar())<'0'||c>'9');
	s=c-'0';
	while((c=getchar())>='0'&&c<='9')
		s=s*10+c-'0';
}
int p[10010];
int b[10010];
int cnt;
int t1[210];
int t2[210];
int pv[210];
int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	cnt=0;
	memset(b,0,sizeof b);
	int i,j;
	for(i=2;i<=1000;i++)
	{
		if(!b[i])
			p[++cnt]=i;
		for(j=1;j<=cnt&&i*p[j]<=1000;j++)
		{
			b[i*p[j]]=1;
			if(i%p[j]==0)
				break;
		}
	}
	for(i=1;i<=cnt;i++)
		pv[i]=p[i]*p[i]*p[i];
	int n;
	read(n);
	int x,y;
	for(i=1;i<=n;i++)
	{
		read(x);
		read(y);
		if(x>y)
			swap(x,y);
		ll s=gcd(x,y);
		ll s2=ll(x)/s*y/s;
		ll s3=gcd(s,s2);
		s2/=s3;
		s/=s3;
		if(s2!=1)
		{
			printf("No\n");
			continue;
		}
		for(j=1;j<=cnt&&s>=pv[j];j++)
			if(s%pv[j]==0)
				while(s%pv[j]==0)
					s/=pv[j];
		if(s==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}