#include<bits/stdc++.h>
using namespace std;

int T,n;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n&1)
        {
            printf("3 1 2 ");
            for(int i=4;i<=n;i+=2)
                printf("%d %d ",i+1,i);
        }
        else
        {
            for(int i=1;i<=n;i+=2)
                printf("%d %d ",i+1,i);
        }
        puts("");
    }
}