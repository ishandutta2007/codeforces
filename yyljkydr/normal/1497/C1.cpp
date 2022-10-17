#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,k;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        while(k>3)
        {
            n--;k--;
            printf("%d ",1);
        }
        if(k==3)
        {
            if(n&1)
                printf("%d %d %d\n",1,n/2,n/2);
            else
            {
                if((n/2)&1)
                {
                    printf("%d %d %d\n",2,(n-2)/2,(n-2)/2);
                }
                else
                    printf("%d %d %d\n",n/2,n/4,n/4);
            }
            continue;
        }
    }
}