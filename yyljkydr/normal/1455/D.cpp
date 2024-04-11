#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,a[N],x;

bool chk()
{
    for(int i=1;i<n;i++)
        if(a[i]>a[i+1])
            return 0;
    return 1;
}

signed main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            if(chk())
            {
                printf("%d\n",tot);
                break;
            }
            if(a[i]>x)
                swap(a[i],x),tot++;
        }
        if(!chk())
            puts("-1");
    }
}