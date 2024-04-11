#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,x;

long long y;

int a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%lld",&n,&x,&y);
        long long s=x;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),s+=a[i];
        if(s%2!=y%2)
            puts("Bob");
        else
            puts("Alice");
    }
}