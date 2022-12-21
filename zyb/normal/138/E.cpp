#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
long long st[35],b[100005],j,i,sum,ff[100005],k,l,m,n,r,s[30][100005],t[30];
char c[100005];
long long ans;
struct node
{
	long long l,r,c;
}q[100005];
struct node1
{
	long long si,l,r;
}f[100005],a[100005];
inline void work(long long ll,long long rr,long long yy)
{
	for (long long o=ll;o<=rr;o++)
	{
		ff[o]++;
		if (ff[o]>=l&&ff[o]<=r)
		{
			if (ff[o]-1<l)
			sum++;
		}
		else
		if (ff[o]>r&&ff[o]-1<=r&&ff[o]-1>=l)
		sum--;
	}
}
inline void work1(long long ll,long long rr,long long yy)
{
	for (long long o=ll;o<=rr;o++)
	{
		ff[o]--;
		if (ff[o]>=l&&ff[o]<=r)
		{
			if (ff[o]+1>r)
			sum++;
		}
		else
		if (ff[o]<l)
		{
			if (ff[o]+1>=l&&ff[o]+1<=r)
			sum--;
		}
	}
}
int main()
{
	scanf("%s",c);
	scanf("%I64d%I64d%I64d",&m,&l,&r);
	for (i=1;i<=m;i++)
	{
		char cc=getchar();
		while (cc<'a'||cc>'z')
		cc=getchar();
		q[i].c=int(cc)-96;
		s[q[i].c][++t[q[i].c]]=i;
		scanf("%I64d%I64d",&q[i].l,&q[i].r);
		f[i].l=1;
	}
	n=strlen(c);
	for (i=0;i<n;i++)
	{
		b[i+1]=int(c[i])-96;
		if (!st[b[i+1]])
		st[b[i+1]]=i+1;
	}
	for (i=1;i<=n;i++)	
	{
		if (l==0)
		sum++;
		a[b[i]].si++;
		for (j=1;j<=m;j++)
		{
			long long k=j;
			if (b[i]==q[k].c)
			{
				
				if (a[q[k].c].si==q[k].l)
				{
					f[k].l=1,f[k].r=st[q[k].c];
					int pp=1;
					while (b[pp]!=b[i])
					pp++;
					work(1,pp,k);
				}
				else
				if (a[q[k].c].si>q[k].l&&a[q[k].c].si<=q[k].r)
				{
					long long pp=f[k].r+1;
					while (b[pp]!=b[i])
					pp++;
					work(f[k].r+1,pp,k);
					f[k].r=pp;
				}
				else
				if (a[q[k].c].si>q[k].r)
				{
					long long pp=f[k].r+1;
					while (b[pp]!=b[i])
					pp++;
					work(f[k].r+1,pp,k);
					f[k].r=pp;
					pp=f[k].l;
					while (b[pp]!=b[i])
					pp++;
					work1(f[k].l,pp,k);
					f[k].l=pp+1;
				}
			}
			else
			{
				if (q[k].l==0)
				work(f[k].r+1,i,k),f[k].r=i;
			}	
		}
		ans+=sum;
	}
	printf("%I64d\n",ans);
}