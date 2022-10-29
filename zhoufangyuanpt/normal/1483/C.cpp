#include<cstdio>
#include<cstring>
using namespace std;
long long f[310000],a[310000],b[310000];
struct node
{
	int p;long long c;
}list[310000];
struct trnode
{
	int l,r,lc,rc;
	long long c;
}tr[610000];int trlen;
void bt(int l,int r)
{
	int now=++trlen;
	tr[now].l=l;tr[now].r=r;tr[now].lc=tr[now].rc=-1;tr[now].c=-0x3f3f3f3f3f3f3f3fll;
	if(l<r)
	{
		int mid=(l+r)/2;
		tr[now].lc=trlen+1;bt(l,mid);
		tr[now].rc=trlen+1;bt(mid+1,r);
	}
}
inline long long mymax(long long x,long long y){return x>y?x:y;}
void change(int now,int x,long long c)
{
	if(tr[now].l==tr[now].r){tr[now].c=c;return ;}
	int lc=tr[now].lc,rc=tr[now].rc;
	int mid=(tr[now].l+tr[now].r)/2;
	if(x<=mid)change(lc,x,c);
	else change(rc,x,c);
	tr[now].c=mymax(tr[lc].c,tr[rc].c);
}
long long findmax(int now,int l,int r)
{
	if(tr[now].l==l&&tr[now].r==r)return tr[now].c;
	int lc=tr[now].lc,rc=tr[now].rc;
	int mid=(tr[now].l+tr[now].r)/2;
	if(r<=mid)return findmax(lc,l,r);
	else if(l>=mid+1)return findmax(rc,l,r);
	else return mymax(findmax(lc,l,mid),findmax(rc,mid+1,r));
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	trlen=0;bt(0,n);
	f[0]=0;
	change(1,0,0);
	int head=1,tail=0;
	for(int i=1;i<=n;i++)
	{
		while(head<=tail&&a[i]<a[list[tail].p])tail--;
		int p=0;
		if(tail>0)p=list[tail].p;
		long long ff=findmax(1,p,i-1)+b[i];
		if(tail>0&&list[tail].c>ff)ff=list[tail].c;
		list[++tail]=(node){i,ff};
		f[i]=ff;
		change(1,i,ff);
	}
	printf("%lld\n",f[n]);
	return 0;
}