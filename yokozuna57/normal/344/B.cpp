#include<iostream>
using namespace std;

bool f(int a,int b,int c){
    if(a>b+c)return true;
    if(b>a+c)return true;
    if(c>a+b)return true;
    return false;
}

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if((a+b+c)%2!=0||f(a,b,c))printf("Impossible\n");
    else {
        printf("%d %d %d\n",(a+b+c)/2-c,(a+b+c)/2-a,(a+b+c)/2-b);
    }
}