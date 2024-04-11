#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N],b[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),b[i]=a[i];
        int mn=*min_element(a+1,a+n+1);
        sort(b+1,b+n+1);
        bool ok=1;
        for(int i=1;i<=n;i++)
            if(a[i]%mn!=0&&a[i]!=b[i])
                ok=0;
        puts(ok?"YES":"NO");
    }
}