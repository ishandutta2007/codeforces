#include<bits/stdc++.h>
using namespace std;

int T;

int n;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int s=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            s=(s+x)%n;
        }
        printf("%lld\n",1ll*s*(n-s));
    }
}