#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

int T;

int n,x[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&x[i]);
        for(int i=1;i<=n;i++)
            printf("%d%c",((~x[i])&x[i-1])," \n"[i==n]),x[i]=x[i]^((~x[i])&x[i-1]);
    }
}