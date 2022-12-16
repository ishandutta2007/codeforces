#include<stdio.h>
using namespace std;
int x;
char c[1056],cc[1005];
int main() {
    scanf("%d",&x);
    scanf("%s%s",c,cc);
    if (cc[0]=='w') printf("%d\n",52+(x==5||x==6));
    else {
        if (x<=29) printf("12\n");
        else if (x==30) printf("11\n");
        else printf("7\n");
    }
}