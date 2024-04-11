#include <cstdio>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=100005;
int n,l,r,q;
int a[MAXN];
int sum[MAXN];
void insert(int x,int c)
{
	++x;
	while (x<=n)
	{
		sum[x]+=c;
		x+=x&-x;
	}
}
int query(int x)
{
	int s=0;
	while (x)
	{
		s+=sum[x];
		x-=x&-x;
	}
	return s;
}
void init()
{
	scanf("%d%d",&n,&q);
	l=0;r=n;
	for (int i=0;i<n;++i)
		a[i]=1,insert(i,1);
}
void solve()
{
	int rev=0;
	while (q--)
	{
		int type;
		scanf("%d",&type);
		if (type==1)
		{
			int p;
			scanf("%d",&p);
			if (rev) rev=0,p=r-l-p;
			if (l+2*p<=r)
			{
				for (int i=0;i<p;++i)
				{
					int u=a[l+p-i-1];
					a[l+p-i-1]=0;
					insert(l+p-i-1,-u);
					a[l+p+i]+=u;
					insert(l+p+i,u);
				}
				l=l+p;
			}
			else
			{
				for (int i=0;i<r-l-p;++i)
				{
					int u=a[l+p+i];
					a[l+p+i]=0;
					insert(l+p+i,-u);
					a[l+p-i-1]+=u;
					insert(l+p-i-1,u);
				}
				r=l+p;
				rev^=1;
			}
		}
		else if (type==2)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if (rev)
			{
				int tmp=x;
				x=r-l-y;
				y=r-l-tmp;
			}
			printf("%d\n",query(y+l)-query(x+l));
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}