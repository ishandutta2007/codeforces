#include <stdio.h>
int a[501], n, k, cnt;
int main(){
    scanf("%i%i", &n, &k);
    for(int i=1; i<=n; i++)
        scanf("%i", &a[i]);
    for(int i=2; i<=n; i++){
        if(a[i]+a[i-1]<k){
            cnt+=k-a[i-1]-a[i];
            a[i]+=k-a[i-1]-a[i];
        }
    }
    printf("%d\n", cnt);
    for(int i=1; i<=n; i++)
        printf("%d ", a[i]);
}