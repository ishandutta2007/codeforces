#include<stdio.h>
int cnt=0,n;
int main(){
    scanf("%d",&n);if(n&1)return printf("No")&0;
    while(getchar()!='\n');
    for(int i=1;i<=n;i++){
        if(getchar()=='(')cnt++;
        else cnt--;
        if(cnt<-1)return printf("No")&0;
    }if(cnt)printf("No");
    else printf("Yes");
}