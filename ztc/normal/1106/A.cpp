#include<stdio.h>
int mp[502][502],n,cnt=0;
main()
{
	scanf("%d",&n);
	for(int i=2;i<=n+1;i++)
	{
		while(getchar()!='\n');
		for(int j=2;j<=n+1;j++)
		{
			mp[i][j]=getchar()=='X';
			cnt+=(mp[i][j]&&mp[i-1][j-1]&&mp[i-2][j]&&mp[i][j-2]&&mp[i-2][j-2]);
		}
	}printf("%d",cnt);
}