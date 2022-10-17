#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int T,n;

int qry(int l,int r)
{
    printf("? %lld %lld\n",l,r);
    fflush(stdout);
    int x;
    scanf("%lld",&x);
    return x;
}

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        int l=0,r=n;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            if(!qry(1,mid))
                l=mid;
            else
                r=mid;
        }
        int i=l;
        int j=i+qry(i,n)-qry(i+1,n)+1;
        int k=j+qry(j,n)-qry(j+1,n);
        printf("! %lld %lld %lld\n",i,j,k);
        fflush(stdout);
    }
}