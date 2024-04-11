#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int q,a[Maxn],n,k,sum;
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		sum=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i]%2;
		}
		if(sum>=k&&(sum&1)==(k&1))
		{
			printf("YES\n");
			for(int i=1;i<=n;i++)
			{			
				if(k==1)
				{
					printf("%d\n",n);
					break;
				}
				if(a[i]%2) printf("%d ",i),k--;
			}
		}
		else printf("NO\n");
	}
	return 0;
}