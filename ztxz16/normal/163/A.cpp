#include <stdio.h>
#include <stdlib.h>
#define mo 1000000007

unsigned int ans,i,j,l1,l2,f[5005][5005],s[5005][5005];
char a1[10005],a2[10005];

int main()
{
    gets(a1+1);
    gets(a2+1);
    for(i=1;a1[i]!=0;i++);
    l1=i-1;
    for(i=1;a2[i]!=0;i++);
    l2=i-1;
    for(i=1;i<=l1;i++)
    {
		if (i==1)
		{
			for(j=1;j<=l2;j++)
			{
				if (a1[i]==a2[j]) f[i][j]=1,ans++;
				else f[i][j]=0;
			}
		}
		else
		{
			for(j=1;j<=l2;j++)
			{
				if (a1[i]==a2[j]) f[i][j]=(s[i-1][j-1]+1)%mo,ans=(ans+f[i][j])%mo;
				else f[i][j]=0;
			}
		}
		for(j=1;j<=l2;j++)
			s[i][j]=(s[i][j-1]+f[i][j])%mo;
	}
	printf("%u\n",ans);
    return 0;
}