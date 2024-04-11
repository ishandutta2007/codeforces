#include<cstdio>
#include<cstring>
using namespace std;
int a[210000],b[210000],q[210000],cnt[210000];
int sta[210000],top;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)cnt[i]=0,q[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		top=0;
		for(int i=1;i<=n;i++)if(cnt[i]==0)sta[++top]=i;
		int ss=0,g=0;
		for(int i=1;i<=n;i++)
		{
			if(q[a[i]]==0)
			{
				b[i]=a[i];
				ss++;
				q[a[i]]=i;
			}
			else
			{
				if(sta[top]==i)
				{
					if(top>1)
					{
						b[i]=sta[top-1];
						top--;sta[top]=sta[top+1];
						q[b[i]]=i;
					}
					else g=i;
				}
				else
				{
					b[i]=sta[top--];
					q[b[i]]=i;
				}
			}
		}
		if(g>0)
		{
			b[g]=a[g];
			b[q[a[g]]]=g;
		}
		printf("%d\n",ss);
		for(int i=1;i<n;i++)printf("%d ",b[i]);
		printf("%d\n",b[n]);
	}
	return 0;
}