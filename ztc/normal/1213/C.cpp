#include<stdio.h>
long long n,m,t,a,p;
int main(){
      scanf("%lld",&t);
      while(t--){
            scanf("%lld%lld",&n,&m);n/=m;m%=10;
            if(m==0)puts("0");
            else if(m==5)printf("%lld\n",((n+1)/2)*5);
            else if(m%2==0){
                  a=(n/5)*20;n%=5;p=0;
                  for(int i=1;i<=n;i++){
                        p=(p+m)%10;a+=p;
                  }printf("%lld\n",a);
            }
            else{
                    a=(n/10)*45;n%=10;p=0;
                    for(int i=1;i<=n;i++){
                            p=(p+m)%10;a+=p;
                    }printf("%lld\n",a);
            }
      }
}