#include<stdio.h>
inline int Max(int a,int b){return a>b?a:b;}
inline int Min(int a,int b){return a<b?a:b;}
int n,a,b,ans;
int main(){
    scanf("%d%d%d",&a,&b,&n);
    printf("%d",Max(Min(a,n)+Min(b,n)-n+1,0));
}