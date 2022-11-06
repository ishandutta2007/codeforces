#include<stdio.h>
int n,a[150002],t,p,c;
int main(){
      scanf("%d",&t);
      while(t--){
            scanf("%d",&n);
            for(int i=1;i<=n;i++)scanf("%d",&a[i]);
            p=1e8;c=0;
            for(int i=n;i>=1;i--)if(a[i]>p)c++;else p=a[i];
            printf("%d \n",c);
      }
}