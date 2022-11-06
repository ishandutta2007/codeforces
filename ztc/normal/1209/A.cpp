#include<stdio.h>
#include<algorithm>
int a[102],n,cnt=0,m,k;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    std::sort(a+1,a+n+1);
    while(n){m=0;k=a[1];cnt++;
        for(int i=1;i<=n;i++)if(a[i]%k)a[++m]=a[i];
        n=m;
    }printf("%d",cnt);
}