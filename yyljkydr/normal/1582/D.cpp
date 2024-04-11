#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N],r[N];

bool cmp(int x,int y)
{
    return a[x]<a[y];
}

void solve(int x)
{
    for(int i=1;i<=x;i+=2)
        printf("%d %d ",a[i+1],-a[i]);
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if(n&1)
        {
            solve(n-3);
            if(a[n-1]+a[n-2]!=0)
                printf("%d %d %d\n",a[n],a[n],-(a[n-1]+a[n-2]));
            else if(a[n]+a[n-1]!=0)
                printf("%d %d %d\n",a[n]+a[n-1],-a[n-2],-a[n-2]);
            else
                printf("%d %d %d\n",-a[n-1],a[n]+a[n-2],-a[n-1]);
        }
        else
            solve(n),puts("");
    }
}