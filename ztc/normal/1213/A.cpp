#include<stdio.h>
int n,a[2],b;
int main(){
      scanf("%d",&n);
      while(n--)scanf("%d",&b),a[b&1]++;
      printf("%d",a[0]<a[1]?a[0]:a[1]);
}