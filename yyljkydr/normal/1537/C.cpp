#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n;

int h[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&h[i]);
        sort(h+1,h+n+1);
        if(n==2)
        {
            printf("%d %d\n",h[1],h[2]);
            continue;
        }
        int p=1;
        for(int i=2;i<n;i++)
            if(h[i+1]-h[i]<h[p+1]-h[p])
                p=i;
        for(int i=p+1;i<=n;i++)
            printf("%d ",h[i]);
        for(int i=1;i<=p;i++)
            printf("%d ",h[i]);
        puts("");
    }
}