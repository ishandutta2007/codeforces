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
        int s=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),s+=a[i];
        int mx=*max_element(a+1,a+n+1);
        if(mx*2>s||s%2==1)
            puts("T");
        else
            puts("HL");
    }
}