#include <cstdio>
#include <iostream>
using namespace std;

int a1,a2,a3,a4,a5,a6;

int main(){
    scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6);
    printf("%d",(a1+a2+a3)*(a1+a2+a3)-a1*a1-a3*a3-a5*a5);
    
return 0;
}