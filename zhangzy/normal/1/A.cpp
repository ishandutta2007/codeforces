#include<bits/stdc++.h>
using namespace std;
long long n,m,a,t;
int main(){
    cin>>n>>m>>a;
    t=(n+a-1)/a*((m+a-1)/a);
    while (clock()<998);
    printf("%I64d\n",t);
}