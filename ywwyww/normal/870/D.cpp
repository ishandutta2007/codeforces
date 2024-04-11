#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
int ask(int x,int y) //ask p_x^b_y
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int s;
	scanf("%d",&s);
	return s;
}
int n;
int a[5010];
int p[5010];
int b[5010];
int d[5010];
void solve1()
{
	int s=0;
	int i;
	for(i=0;i<n;i++)
		s^=(i^a[i]);
	for(i=0;i<n;i++)
	{
		b[i]=(a[i]^s);
		p[b[i]]=i;
	}
	printf("!\n1\n");
	for(i=0;i<n;i++)
		printf("%d ",p[i]);
	printf("\n");
}
int c[5010];
int check(int x)
{
	//p[0]=x
	memset(c,0,sizeof c);
	int i;
	for(i=0;i<n;i++)
	{
		b[i]=(x^a[i]);
		if(b[i]>=n)
			return 0;
		if(c[b[i]])
			return 0;
		p[b[i]]=i;
		c[b[i]]=1;
	}
	if(p[0]!=x)
		return 0;
	for(i=0;i<n;i++)
		if(a[i]!=(p[0]^b[i]))
			return 0;
	for(i=0;i<n;i++)
		if(d[i]!=(p[i]^b[i]))
			return 0;
	return 1;
}
void solve2()
{
	int sum=0;
	int mi=-1;
	int i;
	for(i=0;i<n;i++)
		d[i]=ask(i,i);
	for(i=0;i<n;i++)
		if(check(i))
		{
			sum++;
			if(mi==-1)
				mi=i;
		}
	printf("!\n%d\n",sum);
	for(i=0;i<n;i++)
	{
		b[i]=(mi^a[i]);
		p[b[i]]=i;
	}
	for(i=0;i<n;i++)
		printf("%d ",p[i]);
	printf("\n");
}
int main()
{
//	freopen("d.in","r",stdin);
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
		a[i]=ask(0,i);
	if(n%2==1)
		solve1();
	else
		solve2();
	return 0;
}