#include<stdio.h>
using namespace std;
int i,j,ans;
long long L,R;
int main() {
    scanf("%I64d%I64d",&L,&R);
    for (i=1;i<=63;i++) {
        long long gt=((1ll<<(i))-1);
        for (j=1;j<i;j++) {
            long long gtw=gt-(1ll<<(j-1));
            if (gtw>=L&&gtw<=R) ans++;
        }
    }
    printf("%d\n",ans);
}