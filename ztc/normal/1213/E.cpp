#include<stdio.h>
int n,a,b;char t[8];
int main(){
    scanf("%d",&n);
    while(getchar()!='\n');
    a=(getchar()-'a')*3+getchar()-'a';
    while(getchar()!='\n');
    b=(getchar()-'a')*3+getchar()-'a';
    if(a>b)a^=b^=a^=b;puts("YES\n");
    if(a!=1&&b!=1&&a!=5&&b!=5&&a!=6&&b!=6)for(int i=1;i<=n;i++)printf("abc");
    else if(a!=7&&b!=7&&a!=3&&b!=3&&a!=2&&b!=2)for(int i=1;i<=n;i++)printf("cba");
    else{
        if(a==1){
            for(int i=1;i<=n;i++)putchar('b');
            for(int i=1;i<=n;i++)putchar('c');
            for(int i=1;i<=n;i++)putchar('a');
        }else if(a==2){
            for(int i=1;i<=n;i++)putchar('c');
            for(int i=1;i<=n;i++)putchar('b');
            for(int i=1;i<=n;i++)putchar('a');
        }else if(a==3){
            for(int i=1;i<=n;i++)putchar('a');
            for(int i=1;i<=n;i++)putchar('c');
            for(int i=1;i<=n;i++)putchar('b');
        }else if(a==5){
            for(int i=1;i<=n;i++)putchar('c');
            for(int i=1;i<=n;i++)putchar('a');
            for(int i=1;i<=n;i++)putchar('b');
        }else if(a==6){
            for(int i=1;i<=n;i++)putchar('a');
            for(int i=1;i<=n;i++)putchar('b');
            for(int i=1;i<=n;i++)putchar('c');
        }else{
            for(int i=1;i<=n;i++)putchar('b');
            for(int i=1;i<=n;i++)putchar('a');
            for(int i=1;i<=n;i++)putchar('c');
        }
    }
}