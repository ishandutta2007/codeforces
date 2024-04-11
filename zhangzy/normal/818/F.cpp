#include<bits/stdc++.h>
using namespace std;
long long T,n,p;
int main(){
  for (scanf("%I64d",&T);T--;){
    scanf("%I64d",&n);
    for (p=max(1,(int)sqrt(n*2.0+0.5)-23);p*(p+1)/2<=n-p-1;p++);
    printf("%I64d\n",max( 2*(n-p-1) , n-p+p*(p-1)/2 ));
  }
}