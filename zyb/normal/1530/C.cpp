#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,a[N],b[N];
long long f[N],g[N];
#define pb push_back
inline bool check(int x) {
    int p=(n+x)-(n+x)/4;
    int o=min(x,p);
    int o1=min(n,p);
    long long s0=o*100ll;
    long long s1=0;
    int q=max(0,p-o);
    return s0+f[q]>=g[o1];

}
int main() {
    int test;
    scanf("%d",&test);
    while (test--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
        for (int i = 1; i <= n; i++) scanf("%d",&b[i]);
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        for (int i=1;i<=n;i++) f[i]=f[i-1]+a[n-i+1],g[i]=g[i-1]+b[n-i+1];
        
        int l = 0, r = 1000000, s=0; 
        while (l<=r) {
            int mid=(l+r)>>1;
            if (check(mid)) s=mid,r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",s);
    }
}