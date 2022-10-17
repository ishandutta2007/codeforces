#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if(!a[n])
        {
            for(int i=1;i<=n+1;i++)
                printf("%d%c",i," \n"[i==n+1]);
        }
        else if(a[1])
        {
            printf("%d ",n+1);
            for(int i=1;i<=n;i++)
                printf("%d%c",i," \n"[i==n]);
        }
        else
        {
            int flag=1;
            for(int i=1;i<n;i++)
                if(a[i]==0&&a[i+1]==1)
                {
                    flag=1;
                    for(int j=1;j<=i;j++)
                        printf("%d ",j);
                    printf("%d ",n+1);
                    for(int j=i+1;j<=n;j++)
                        printf("%d%c",j," \n"[j==n]);
                    break;
                }
            if(!flag)
                puts("-1");
        }
    }
}