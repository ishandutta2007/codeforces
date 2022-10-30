#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
typedef long long LL;

int n;
LL a[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        LL sum=0,s2=0;
        for (int i=1;i<=n;++i)  {
            scanf("%lld",a+i);
            sum+=a[i];
            s2^=a[i];
        }
        printf("2\n%lld %lld\n",s2,s2+sum);
        // assert(sum+s2+sum+s2==(s2^s2^
    }
    return 0;
}