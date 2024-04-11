#include<bits/stdc++.h>
using namespace std;
bool a[100003],b[100003];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,t,k;
        scanf("%d",&n);
        for(int i=1; i<=n; i++) 
        {
            bool f=1;
            scanf("%d",&k);

            for(int j=1; j<=k; j++)
            {
                scanf("%d",&t);
                if((!a[t]) &&f) {
                    b[i]=a[t]=1;
                    f=0;
                } 
        }
    }
    int x=0,y=0;
    for(int i=1; i<=n; i++) if(!a[i]) 
    {
        x=i; break;
    }
    for(int i=1; i<=n; i++) if(!b[i])
    {
        y=i; break;
    }
    if(x && y)
    printf("IMPROVE\n%d %d\n",y,x);
    else printf("OPTIMAL\n");
    for(int i=1; i<=n; i++) a[i]=b[i]=0;
    }
    return 0;
}