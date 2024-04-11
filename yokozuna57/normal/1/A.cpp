#include<iostream>
using namespace std;

long long int f(long long int x,long long int y){return (x-1)/y+1;}

int main(){
    long long int n,m,a;
    scanf("%I64d%I64d%I64d",&n,&m,&a);
    printf("%I64d\n",f(n,a)*f(m,a));
}