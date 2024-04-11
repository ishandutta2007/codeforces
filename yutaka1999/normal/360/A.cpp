#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 5005
#define INF 1000000000

using namespace std;

struct P
{
	int t,l,r,d;
	P(int t=0,int l=0,int r=0,int d=0):t(t),l(l),r(r),d(d){}
};
P in[SIZE];
int pl[SIZE];
int mx[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	fill(mx,mx+n,INF);
	for(int i=0;i<m;i++)
	{
		int t,l,r,d;
		scanf("%d %d %d %d",&t,&l,&r,&d);l--;r--;
		in[i]=P(t,l,r,d);
		if(t==1)
		{
			for(int j=l;j<=r;j++)
			{
				pl[j]+=d;
			}
		}
		else
		{
			for(int j=l;j<=r;j++)
			{
				mx[j]=min(mx[j],d-pl[j]);
			}
		}
	}
	memset(pl,0,sizeof(pl));
	for(int i=0;i<m;i++)
	{
		int t,l,r,d;
		t=in[i].t,l=in[i].l,r=in[i].r,d=in[i].d;
		if(t==1)
		{
			for(int j=l;j<=r;j++)
			{
				pl[j]+=d;
			}
		}
		else
		{
			int val=-INF;
			for(int j=l;j<=r;j++) val=max(val,mx[j]+pl[j]);
			if(val<d)
			{
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",mx[i]);
	}puts("");
	return 0;
}