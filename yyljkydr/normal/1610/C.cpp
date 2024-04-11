#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n;

int a[N],b[N];

int L[N],R[N];

bool chk(int m)
{
    for(int i=1;i<=n;i++)
    {
        L[i]=max(m-a[i],1);
        R[i]=min(m,b[i]+1);
    }
    int now=1;
    for(int i=1;i<=n;i++)
        if(L[i]<=now&&now<=R[i])
            now++;
    return now>m;
}

signed main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i],&b[i]);
        int l=0,r=n+1;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            if(chk(mid))
                l=mid;
            else
                r=mid;
        }
        printf("%d\n",l);
    }
}
/*
bj >= j
aj <= j
*/