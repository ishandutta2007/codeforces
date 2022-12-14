#include<bits/stdc++.h>
using namespace std;
int m;
struct mat{
   long long int a11,a21,a12,a22;
}init;
mat operator*(mat A,mat B){
   return (mat) {(A.a11*B.a11+A.a12*B.a21)%m,(A.a11*B.a12+A.a12*B.a22)%m,(A.a21*B.a11+A.a22*B.a21)%m,(A.a21*B.a12+A.a22*B.a22)%m};
}
mat exp(long long int x){
   if(x==0) return (mat)  {1%m,0,0,1%m};
   if(x==1) return init;
   mat tmp=exp(x/2);
   tmp=tmp*tmp;
   if(x%2)
      return   tmp*init;
   else
      return tmp;

}
long long int F(long long int x){
   if(x==1||x==2) return 1%m;
   return (exp(x-2).a11+exp(x-2).a12)%m;

}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   long long int l,r,k,now;
   cin>>m>>l>>r>>k;
   init={1%m,1%m,1%m,0};
   for(int i=1;i<=1000000;i++){
      now=r/i;
      if(i-(l-1)/now>=k){
         cout<<F(now)<<endl;
         return 0;
      }
   }
   for(int i=1000000;i>=1;i--){
      now=i;
      if(r/i-(l-1)/now>=k){
         cout<<F(now)<<endl;
         return 0;
      }
   }
}