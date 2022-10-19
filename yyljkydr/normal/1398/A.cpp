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
        if(a[1]+a[2]>a[n])
            puts("-1");
        else
            printf("%d %d %d\n",1,2,n);
    }
}