#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#define maxn 25
#define maxm 1<<maxn
#define P	 1000000007
using namespace std;

int		N,M,a[maxn],b[maxn],f[maxm],dis[maxm];

int		main()
{
		scanf("%d",&N);
		memset(f,0,sizeof(f));
		memset(dis,0,sizeof(dis));
		
		for	(int i=1;i<=N;i++)
		{
			scanf("%d",&a[i]);
			dis[1<<(i-1)]=a[i];
		}
		scanf("%d",&M);
		for (int i=1;i<=M;i++)
			scanf("%d",&b[i]);
			
		f[0]=1;
		for	(int i=1;i<=(1<<N)-1;i++)
		{
			if	(i&(i-1))
			{
				dis[i]=dis[i&(i-1)]+dis[(i&(i-1))^i]; 
			}
			bool	flag=0;
			for	(int j=1;j<=M;j++)
			if	(dis[i]==b[j])	
			{
				flag=1;	break;
			}
			if	(flag)	continue;
			
			for	(int j=1;j<=N;j++)
			{
				if	((1<<(j-1))&i)	
				{
					f[i]=f[i]+f[i^(1<<(j-1))];
					if	(f[i]>=P)	f[i]-=P;
				}
			}
		}		
		printf("%d\n",f[(1<<N)-1]);
		return 0;
}