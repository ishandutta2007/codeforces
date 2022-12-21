#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define N 1000005
#define P 998244353
int n,k,x,a[N],b[N],c[N],A[N];
int main() {
	int test;
	scanf("%d",&test);
    while (test--) {
    	long long ans=1;
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=n;i++) A[i]=0,c[a[i]]=i;
        for (int i=1;i<=k;i++) {
            scanf("%d",&b[i]);
            b[i]=c[b[i]];
            A[b[i]]=i;
        }
        for (int i=1;i<=k;i++) {
        	int s=0;
            if (b[i]-1>=1&&A[b[i]-1]<i) s++;
            if (b[i]+1<=n&&A[b[i]+1]<i) s++;
            ans=1ll*ans*s%P;
        }
        printf("%lld\n",ans);
    }
}