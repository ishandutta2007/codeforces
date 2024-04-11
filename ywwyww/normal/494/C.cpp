#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<list>
#include<stack>
using namespace std;
typedef long long ll;
//f[i][j]=imx[i]+j
struct seg
{
	int l,r;
	double p;
	int mx;
};
int operator <(seg a,seg b) 
{
	if(a.l!=b.l)
		return a.l<b.l;
	if(a.r!=b.r)
		return a.r>b.r;
	return a.p<b.p;
}
int c[20][1000010];
seg a[1000010];
list<int> l[100010];
int n,q;
int get(int l,int r)
{
	int x=0;
	while((1<<(x+1))<=r-l+1)
		x++;
	return max(c[x][l],c[x][r-(1<<x)+1]);
}
double f[5010][5010];
double getf(int x,int y)
{
	if(y<0)
		return 0;
//		return 1;
	if(y>q)
		return f[x][q];
//		return 1;
	return f[x][y];
}
void dfs(int x)
{
	int i;
	int s=0;
	double s1,s2;
	for(auto v:l[x])
		dfs(v);
	for(i=0;i<=q;i++)
	{
//		s1=a[x].p;
//		s2=1-a[x].p;
		s2=1;
		for(auto v:l[x])
		{
			s++;
			s1*=getf(v,a[x].mx-a[v].mx+i-1);
			s2*=getf(v,a[x].mx-a[v].mx+i);
		}
		f[x][i]+=s2*(1-a[x].p);
		f[x][i+1]+=s2*a[x].p;
	}
	if(!s)
	{
		memset(f[x],0,sizeof f[x]);
		f[x][0]=1-a[x].p;
		for(i=1;i<=q;i++)
			f[x][i]=1;
	}
}
int main()
{
//	freopen("cf494c.in","r",stdin);
//	freopen("cf494c.out","w",stdout);
	scanf("%d%d",&n,&q);
	memset(f,0,sizeof f);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&c[0][i]);
	for(i=1;i<=q;i++)
		scanf("%d%d%lf",&a[i].l,&a[i].r,&a[i].p);
	q++;
	a[q].l=1;
	a[q].r=n;
	a[q].p=0;
	sort(a+1,a+q+1);
	int j;
	for(i=1;i<=19;i++)
		if((1<<i)<=n)
			for(j=1;j<=n;j++)
				if(j+(1<<i)-1<=n)
					c[i][j]=max(c[i-1][j],c[i-1][j+(1<<(i-1))]);
	for(i=1;i<=q;i++)
		a[i].mx=get(a[i].l,a[i].r);
	for(i=2;i<=q;i++)
	{
		for(j=i-1;j>=1;j--)
			if(a[j].r>=a[i].r)
				break;
		l[j].push_back(i);
	}
	dfs(1);
	double ans=0;
	ans+=f[1][0]*a[1].mx;
	for(i=1;i<=q;i++)
		ans+=(f[1][i]-f[1][i-1])*(a[1].mx+i);
	printf("%.10lf\n",ans);
	return 0;
}