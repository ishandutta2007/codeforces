#include <algorithm>
#include <cstdio>
#include <cstring>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=100005;
const int MAXQ=100005;
const int MAXS=100005;
struct query
{
	int l,r,id;
	friend bool operator <(const query &x,const query &y) {return x.r<y.r;}
};
int n,q;
int a[MAXN];
query qr[MAXQ];
int ans[MAXQ];
int lp[MAXS];
int lp2[MAXS];
int cc[MAXS];
int pr[MAXS];
int ss[MAXN];
int ss2[MAXN];
void init()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	for (int i=0;i<q;++i)
	{
		scanf("%d%d",&qr[i].l,&qr[i].r);
		--qr[i].l;
		qr[i].id=i;
	}
	std::sort(qr,qr+q);
}
void insert(int x,int y,int *s)
{
	++x;
	while (x)
	{
		s[x]+=y;
		x-=x&-x;
	}
}
int getsum(int x,int *s)
{
	int su=0;
	++x;
	while (x<=n)
	{
		su+=s[x];
		x+=x&-x;
	}
	return su;
}
void solve()
{
	memset(lp,-1,sizeof(lp));
	memset(lp2,-1,sizeof(lp2));
	memset(pr,-1,sizeof(pr));
	memset(cc,0,sizeof(cc));
	for (int i=0,j=0;i<n;++i)
	{
		insert(lp[a[i]],-1,ss);
		insert(i,1,ss);
		insert(lp[a[i]],-1,ss2);
		insert(i,1,ss2);
		if (i-lp[a[i]]!=cc[a[i]])
		{
			insert(lp2[a[i]],-1,ss2);
			insert(pr[a[i]],1,ss2);
			cc[a[i]]=i-lp[a[i]];
			pr[a[i]]=lp2[a[i]];
		}
		lp2[a[i]]=lp[a[i]];
		lp[a[i]]=i;
		while (j<q&&qr[j].r==i+1)
		{
			ans[qr[j].id]=getsum(qr[j].l,ss)+(getsum(qr[j].l,ss2)==0?1:0);
			++j;
		}
	}
	for (int i=0;i<q;++i)
		printf("%d\n",ans[i]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("8798.in","r",stdin);
	freopen("8798.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}