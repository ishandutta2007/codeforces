#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL check(LL x)  {
    LL l=1,r=x;
    while (l<r) {
        LL mid=(l+r)>>1;
        LL sum=mid*(mid+1)/2;
        if (sum>=x)
            r=mid;
        else
            l=mid+1;
    }
    // cout<<x<<":"<<l<<endl;
    if (l*(l+1)/2-1==x)
        return l+1;
    else
        return l;
}
int main()  {
    int T;
    cin>>T;
    while (T--) {
        int x;
        cin>>x;
        printf("%lld\n",check(x));
    }
    return 0;
}