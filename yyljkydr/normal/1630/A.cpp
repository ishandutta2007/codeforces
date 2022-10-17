#include<bits/stdc++.h>
using namespace std;

int T,n,k;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        if(k==n-1)
        {
            if(n<=4)
                puts("-1");
            else
            {
                printf("%d %d\n",n-1,n/2-1);
                printf("%d %d\n",n/2,n/2+1);
                printf("%d %d\n",0,n/2-2);
                for(int i=1;i<n/2-2;i++)
                    printf("%d %d\n",i,n-1-i);
            }
        }
        else
        {
            printf("%d %d\n",n-1,k);
            if(k!=0)
                printf("%d %d\n",0,n-1-k);
            for(int i=1;i<=n/2-1;i++)
                if(i!=k&&i!=(n-1-k))
                    printf("%d %d\n",i,n-1-i);
        }
    }
}