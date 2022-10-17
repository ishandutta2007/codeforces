#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

int x[N],y[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&x[i],&y[i]);
        sort(x+1,x+n+1);
        sort(y+1,y+n+1);
        long long ax,ay;
        ax=n&1?1:(x[n/2+1]-x[n/2]+1);
        ay=n&1?1:(y[n/2+1]-y[n/2]+1);
        printf("%lld\n",ax*ay);
    }
}