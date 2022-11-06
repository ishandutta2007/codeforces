#include<stdio.h>
int main(){
    char a,b,c;
    a=getchar()-65,b=getchar()-65;
    while(1){
        c=getchar()-65;
        if(c<0||c>26)return puts("YES")&0;
        if(c!=(a+b)%26)return puts("NO")&0;
        a=b;b=c;
    }
}