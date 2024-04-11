#include<cstdio>
#include<algorithm>

using namespace std;

int lg[200000];

struct ST
{
	int a[200000][20],type; //	0: min	1: max
	void init(int n,int *ori,int _type)
	{
		type=_type;
		for(int i=1;i<=n;i++)a[i][0]=ori[i];
		for(int j=1;(1<<j)<=n;j++)
		{
			for(int i=1;i+(1<<j)-1<=n;i++)
			{
				int x=a[i][j-1],y=a[i+(1<<(j-1))][j-1];
				if(x==-1&&y==-1)a[i][j]=-1;
				else if(x==-1)a[i][j]=y;
				else if(y==-1)a[i][j]=x;
				else
				{
					if(type==0)a[i][j]=min(x,y);else a[i][j]=max(x,y);
				}
			}
		}
	}
	int query(int l,int r)
	{
		if(l>r)return -1;
		int len=lg[r-l+1];
		int x=a[l][len],y=a[r-(1<<len)+1][len];
		if(x==-1&&y==-1)return -1;
		if(x==-1)return y;
		if(y==-1)return x;
		if(type==0)return min(x,y);return max(x,y);
	}
}L[30],R[30];

int a[200000];
int tmpl[200000],tmpr[200000];

int main()
{
	int n=0,q=0;scanf("%d%d",&n,&q);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	lg[0]=-1;for(int i=1;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<n;i++)if(a[i]!=a[i+1])tmpl[i]=min(a[i],a[i+1]),tmpr[i]=max(a[i],a[i+1]);else tmpl[i]=tmpr[i]=-1;
	L[0].init(n-1,tmpl,0),R[0].init(n-1,tmpr,1);
	
	for(int i=1;i<30;i++)
	{
		for(int j=1;j<n;j++)
		{
			int l=L[i-1].query(j,j),r=R[i-1].query(j,j);
			if(l==-1||r==-1){tmpl[j]=tmpr[j]=-1;continue;}
			tmpl[j]=L[i-1].query(l,r-1);tmpr[j]=R[i-1].query(l,r-1);
			if(tmpl[j]==tmpr[j]||tmpl[j]==-1||tmpr[j]==-1)tmpl[j]=tmpr[j]=-1;
		}
		
		L[i].init(n-1,tmpl,0),R[i].init(n-1,tmpr,1);
	}
	
	while(q--)
	{
		int l=0,r=0;scanf("%d%d",&l,&r);
		if(l==1&&r==n){puts("0");continue;}
		if(L[29].query(l,r-1)!=1||R[29].query(l,r-1)!=n){puts("-1");continue;}
		int ans=0;
		for(int i=28;i>=0;i--)
		{
			int x=L[i].query(l,r-1),y=R[i].query(l,r-1);
			if(x!=1||y!=n)
			{
				ans+=(1<<i);l=x,r=y;
			}
		}
		ans++;printf("%d\n",ans);
	}
}