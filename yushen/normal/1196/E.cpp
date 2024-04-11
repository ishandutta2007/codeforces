#include <bits/stdc++.h>
using namespace std;
int q,n,m;
int main()
{
//	freopen("E.in","r",stdin); 
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&n,&m);
		swap(n,m);
		if(n>3*m+1||m>3*n+1)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		if(n==m)
		{
			for(int i=1;i<=m*2;i++)
				printf("1 %d\n",i);
		}
		else if(n<m)
		{
			for(int i=1;i<=2*n+1;i++)
				printf("2 %d\n",i);
			m-=n+1;
			for(int i=2;i<=2*n&&m;i+=2)
				printf("1 %d\n",i),m--;
			for(int i=2;i<=2*n&&m;i+=2)
				printf("3 %d\n",i),m--;
		}
		else
		{
			for(int i=1;i<=2*m+1;i++)
				printf("3 %d\n",i);
			n-=m+1;
			for(int i=2;i<=2*m&&n;i+=2)
				printf("2 %d\n",i),n--;
			for(int i=2;i<=2*m&&n;i+=2)
				printf("4 %d\n",i),n--;
		}
	}
	return 0;
}