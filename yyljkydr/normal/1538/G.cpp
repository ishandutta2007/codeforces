#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7;

int T,a,b,x,y;

bool chk(int s)
{
    if(x==y)
        return min(a/x,b/x)>=s;
    //k * x + (s - k) * y <= a
    //(s - k) * x + k * y <= b
    //k * (x - y) <= a - y * s
    //k * (y - x) <= b - x * s
    double r=1.0*(a-y*s)/(x-y),l=1.0*(b-x*s)/(y-x);
    if(r<0)
        return 0;
    if(l>s)
        return 0;
    int L=ceil(l),R=floor(r);
    return L<=R;
}

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
        if(x<y)
            swap(x,y),swap(a,b);
        // chk(5);
        int l=0,r=2e9+1;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            if(chk(mid))
                l=mid;
            else
                r=mid;
        }
        printf("%lld\n",l);
    }
}