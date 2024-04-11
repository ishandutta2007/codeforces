#include<bits/stdc++.h>
using namespace std;

const int N=101;

int T,n,a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int s=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),s+=a[i];
        puts(s%n?"1":"0");
    }
}