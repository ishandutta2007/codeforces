#include<bits/stdc++.h>
using namespace std;

int T,n;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int t=n-1,p=-1;
        for(int i=30;i>=0;i--)
            if(t>>i&1)
            {
                p=i;
                break;
            }
        for(int i=n-1;i>=(1<<p);i--)
            printf("%d ",i);
        for(int i=0;i<(1<<p);i++)
            printf("%d ",i);
        puts("");
    }
}