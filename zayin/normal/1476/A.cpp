#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        LL n,m;
        scanf("%lld%lld",&n,&m);
        if (m<n)
            m=((n-1)/m+1)*m;
        
        printf("%lld\n",(m-1)/n+1);
    }
    return 0;
}