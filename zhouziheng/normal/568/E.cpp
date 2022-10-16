#include<cstdio>
#include<algorithm>

using namespace std;

int a[200000],b[200000];
int l[200000],pos[200000],f[200000],g[200000];

const int INF=1e9;

int main()
{
	int n=0,m=0;scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[++n]=INF-1;
	scanf("%d",&m);for(int i=1;i<=m;i++)scanf("%d",&b[i]);sort(b+1,b+m+1);
	
	for(int i=1;i<=n;i++)f[i]=INF;
	int maxlen=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=-1)
		{
			int j=lower_bound(f,f+maxlen+1,a[i])-f-1;
			if(j>=maxlen)maxlen++;
			//printf("%d\n",maxlen);
			l[i]=j+1,pos[i]=g[j];if(a[i]<f[j+1])f[j+1]=a[i],g[j+1]=i;
		}
		else
		{
			for(int j=m,p=maxlen+1;j>=1;j--)
			{
				while(p&&b[j]<=f[p-1])p--;
				if(b[j]<f[p]){f[p]=b[j],g[p]=i;}
			}
			l[i]=-1;
			if(g[maxlen+1])maxlen++;
		}
	}
	//printf("%d\n",maxlen);
	int now=n,nowlen=l[n],nowv=a[n];
	while(nowlen)
	{
		if(a[now]!=-1){--nowlen;nowv=a[now];now=pos[now];continue;}
		for(int i=m;i>=1;i--)if(b[i]!=-1&&b[i]<nowv){a[now]=b[i];b[i]=-1;break;}
		for(int i=now-1;i>=1;i--)if(l[i]==nowlen-1&&a[i]<a[now]){pos[now]=i;break;}
		if(!pos[now])for(int i=now-1;i;i--)if(a[i]==-1){pos[now]=i;break;}
		--nowlen,nowv=a[now],now=pos[now];
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]==-1)
		{
			for(int j=1;j<=m;j++)if(b[j]!=-1){a[i]=b[j];b[j]=-1;break;}
		}
		printf("%d ",a[i]);
	}
	return 0;
}