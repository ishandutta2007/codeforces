#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i,j,n,m,k,t;
    while(scanf("%d",&n)!=EOF)
    {
        int tmp1=n/2,tmp2=n/2,tmp3=1;
        for(i=1;i<=n/2;i++)
        {
            for(j=1;j<=tmp1;j++)
                printf("*");
            for(j=tmp1;j<=tmp2;j++)
                printf("D");
            for(j=tmp2+2;j<=n;j++)
                printf("*");
            printf("\n");
            tmp1--;tmp2++;
        }
        for(i=1;i<=n;i++)
            printf("D");
        printf("\n");
        tmp1=1,tmp2=n;
        for(i=1;i<=n/2;i++)
        {
            for(j=1;j<=tmp1;j++)
                printf("*");
            for(j=tmp1+1;j<=tmp2-1;j++)
                printf("D");
            for(j=tmp2;j<=n;j++)
                printf("*");
            tmp1++;tmp2--;
            printf("\n");
        }
    }
    return 0;
}