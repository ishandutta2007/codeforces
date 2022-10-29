#include<cstdio>
#include<cstring>
using namespace std;
int a[210000],cnt[210000];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,l,r;scanf("%d%d%d",&n,&l,&r);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++)cnt[i]=0;
		if(l<r)
		{
			for(int i=l+1;i<=n;i++)cnt[a[i]]++;
			int s=n,ss=0,h=(r-l)/2;
			for(int i=1;i<=l;i++)
			{
				if(cnt[a[i]]>0)s-=2,cnt[a[i]]--;
			}
			for(int i=1;i<=n;i++)
			{
				if(h==0)break;
				if(cnt[a[i]]>0)
				{
					if(cnt[a[i]]/2<h)
					{
						h-=cnt[a[i]]/2;
						s-=cnt[a[i]]/2*2;
						ss+=cnt[a[i]]/2;
						cnt[a[i]]-=cnt[a[i]]/2*2;
					}
					else
					{
						ss+=h;
						s-=h*2;
						cnt[a[i]]-=h*2;
						h=0;
						break;
					}
				}
			}
			if(h>0)ss+=h;
			ss+=s/2;
			printf("%d\n",ss);
		}
		else
		{
			for(int i=1;i<=l;i++)cnt[a[i]]++;
			int s=n,ss=0,h=(l-r)/2;
			for(int i=l+1;i<=n;i++)
			{
				if(cnt[a[i]]>0)s-=2,cnt[a[i]]--;
			}
			for(int i=1;i<=n;i++)
			{
				if(h==0)break;
				if(cnt[a[i]]>0)
				{
					if(cnt[a[i]]/2<h)
					{
						h-=cnt[a[i]]/2;
						s-=cnt[a[i]]/2*2;
						ss+=cnt[a[i]]/2;
						cnt[a[i]]-=cnt[a[i]]/2*2;
					}
					else
					{
						ss+=h;
						s-=h*2;
						cnt[a[i]]-=h*2;
						h=0;
						break;
					}
				}
			}
			if(h>0)ss+=h;
			ss+=s/2;
			printf("%d\n",ss);
		}
	}
	return 0;
}