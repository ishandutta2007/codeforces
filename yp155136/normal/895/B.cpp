#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

int main ()
{
    int n,x,k;
    scanf("%d %d %d",&n,&x,&k);
    //k number such that y%x==0
    vector<LL> v;
    while (n--)
    {
        int x;
        scanf("%d",&x);
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    LL ans=0;
    for (LL i:v)
    {
        LL group = i/x;
        if (i%x==0) group--;
        group += k;
        LL L=group*x,R=(group+1)*x-1;
        if (R < i) continue;
        else L = max(L,i);
        //L = max(L,i);
        //R = max(R,i);
        ans += upper_bound(v.begin(),v.end(),R) - lower_bound(v.begin(),v.end(),L);
    }
    printf("%lld\n",ans);
}