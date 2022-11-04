#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int a,b,c;
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int main(){
    scanf("%d%d%d",&a,&b,&c);
    printf("%d",c/(a*b/gcd(a,b)));
}