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
        
        if(n==1)
        {
            puts("Yes");
            continue;
        }
        int beg=-1;
        for(int i=1;i<=n;i++)
            if(a[i]==1)
                beg=i;
        if(beg==-1)
            puts("No");
        else
        {
            int i=beg+1>n?1:beg+1;
            bool ok=1;
            while(1)
            {
                if(i==beg)
                    break;
                if(a[i]>a[i-1>0?i-1:n]+1)
                    ok=0;
                if(a[i]==1)
                    ok=0;
                i++;
                if(i==n+1)
                    i=1;
            }
            puts(ok?"Yes":"No");
        }
    }
}