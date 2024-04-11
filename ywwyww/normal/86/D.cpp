#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int a[1000010];
int c[1000010];
struct p
{
	int l,r,id;
};
int size;
p d[1000010];
int cmp(p a,p b)
{
	return a.l/size!=b.l/size?a.l/size<b.l/size:a.r<b.r;
}
ll ans[1000010];
ll s=0;
void add(int x)
{
	s+=x*(2ll*c[x]+1);
	c[x]++;
}
void del(int x)
{
	c[x]--;
	s-=x*(2ll*c[x]+1);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	size=sqrt(n)+0.5;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&d[i].l,&d[i].r);
		d[i].id=i;
	}
	sort(d+1,d+m+1,cmp);
	int l=1,r=0;
	memset(c,0,sizeof c);
	for(i=1;i<=m;i++)
	{
		while(l>d[i].l)
			add(a[--l]);
		while(r<d[i].r)
			add(a[++r]);
		while(l<d[i].l)
			del(a[l++]);
		while(r>d[i].r)
			del(a[r--]);
		ans[d[i].id]=s;
	}
	for(i=1;i<=m;i++)
		printf("%I64d\n",ans[i]);
	return 0;
}