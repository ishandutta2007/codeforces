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
int b[1000010];
int c[2000010];
int size;
struct p
{
	int l,r,id;
};
p d[100010];
ll ans[100010];
int cmp(p a,p b)
{
	if(a.l/size!=b.l/size)
		return a.l/size<b.l/size;
	return a.r/size<b.r/size;
}
ll s;
int k;
void add(int x)
{
	s+=c[k^x];
	c[x]++;
}
void del(int x)
{
	c[x]--;
	s-=c[k^x];
}
int main()
{
	int i,n,m;
	scanf("%d%d%d",&n,&m,&k);
	size=sqrt(n)+0.5;
	b[1]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i+1]=b[i]^a[i];
	}
	n++;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&d[i].l,&d[i].r);
		d[i].r++;
		d[i].id=i;
	}
	sort(d+1,d+m+1,cmp);
	memset(c,0,sizeof c);
	int l=1,r=0;
	s=0;
	for(i=1;i<=m;i++)
	{
		while(r<d[i].r)
			add(b[++r]);
		while(l>d[i].l)
			add(b[--l]);
		while(r>d[i].r)
			del(b[r--]);
		while(l<d[i].l)
			del(b[l++]);
		ans[d[i].id]=s;
	}
	for(i=1;i<=m;i++)
		printf("%I64d\n",ans[i]);
	return 0;
}