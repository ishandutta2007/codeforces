#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n;

int a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        printf("%d\n",a[1]==a[n]?n:1);
    }
}