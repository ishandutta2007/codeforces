#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n;
double a[maxn];

LL A[maxn];

LL F(LL A)  {
    if (A%100000==0)    return A/100000;
    return A>=0?A/100000:A/100000-1;
}

int main()  {
    scanf("%d",&n);
    LL ans=0;
    for (int i=1;i<=n;++i)  {
        scanf("%lf",a+i);
        A[i]=a[i]*100000;
        ans+=F(A[i]);
    }
    ans=-ans;
    for (int i=1;i<=n;++i)  {
        if (A[i]%100000&&ans) {
            --ans;
            printf("%lld\n",F(A[i])+1);
        } else
            printf("%lld\n",F(A[i]));
    }
    return 0;
}