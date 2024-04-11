#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str[100010];

int main()
{
    int n,m,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%d",&str[i]);
        }
        int sum=0,tmp;
        for(i=2; i<=n; i++)
        {
            if(str[i]<str[i-1])
            {
                sum++;
                tmp=i;
            }
                
        }
        if(sum == 0)printf("0\n");
        else if(sum > 1)printf("-1\n");
        else if(sum == 1 && str[n] <= str[1])
            printf("%d\n",n-tmp+1);
        else printf("-1\n");
    }
    return 0;
}