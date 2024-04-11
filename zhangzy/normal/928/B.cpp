#include<bits/stdc++.h>
using namespace std;

int n, k, f[101000], x;

int main(){
  cin>>n>>k;
  for (int i=1;i<=n;++i){
    scanf("%d",&x);
    if (x==0){
      f[i]= min(n,i+k)-max(1,i-k)+1;
    }else{
      f[i]= f[x]+ min(n,i+k)- max(max(1,i-k),min(n,x+k)+1)+1;
    }
    printf("%d ",f[i]);
  }
}