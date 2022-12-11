#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,k,ans=0,tot2=0,tot=0,cnt=0,a[100005],sum=0;
char s[100005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		s[0]='L';
		sum=-1000000;
		cnt=tot2=tot=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='W')
			{
				tot2++;
				if(s[i-1]=='L')tot++;
				if(sum>0)a[++cnt]=sum;
				sum=0;
			}
			else sum++;
		}
		sort(a+1,a+cnt+1);
		if(k>=n-tot2)ans=1+2*(n-1);
		else
		{
			if(tot2==0)
			{
				if(k)ans=1+2*(k-1);
				else ans=0;
			}
			else
			{
				int res=k;
				//printf("@%d %d %d\n",tot,tot2);
				for(int i=1;i<=cnt;i++)
				{
					if(res>=a[i])
					{
						tot--;
						res-=a[i];
					}
					else break;
				}
				//printf("%d\n",tot);
				ans=2*(tot2+k)-tot;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}