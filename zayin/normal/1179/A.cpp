#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n,m;
int a[maxn];

int A[maxn],B[maxn];

int main()  {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i);
    
    int l=1,r=n;
    for (int t=1;t<=n;++t)    {
        A[t]=a[l],B[t]=a[l+1];
        int mn=min(a[l],a[l+1]),mx=max(a[l],a[l+1]);
        a[++l]=mx,a[++r]=mn;
    }

    // for (int i=l;i<=r;++i)  cout<<a[i]<<" "; cout<<endl;
    while (m--) {
        LL T;
        scanf("%lld",&T);
        if (T<=n)
            printf("%d %d\n",A[T],B[T]);
        else    {
            printf("%d %d\n",a[l],a[(T-n-1)%(n-1)+1+l]);
        }
    }
    return 0;
}