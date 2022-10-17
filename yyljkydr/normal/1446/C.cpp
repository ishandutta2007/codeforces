#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,a[N];

int solve(int l,int r,int p)
{
    if(p==-1)
        return r-l+1;
    // printf("%d %d %d\n",l,r,p);
    int mid=lower_bound(a+l,a+r+1,1<<p)-a;
    for(int i=mid;i<=r;i++)
        a[i]-=1<<p;
    int ret=0;
    if(l<=mid-1)
        ret=max(ret,solve(l,mid-1,p-1)+(mid<=r?1:0));
    if(mid<=r)
        ret=max(ret,solve(mid,r,p-1)+(l<=mid-1?1:0));
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    printf("%d\n",n-solve(1,n,30));
}