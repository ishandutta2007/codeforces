#include<stdio.h>
int n,a,b,ans;
int main(){
    scanf("%d%d%d",&n,&a,&b);b*=5;ans=n;
    for(int i=0;i<100&&i*b<=n;i++){
        if((n-b*i)%a<ans)ans=(n-b*i)%a;
    }printf("%d",ans);
}