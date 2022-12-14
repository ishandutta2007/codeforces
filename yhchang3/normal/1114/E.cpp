#include<bits/stdc++.h>
using namespace std;
int a[40];
unsigned int seed=740;
int myrand(){
   return seed=(int) seed*48271LL%2147483647;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,tmp;
   cin>>n;
   srand(time(NULL));
   int m=0;
   int l=0,r=1e9;
   while(l<r){
      int mid=(l+r)/2;
      cout<<"> "<<mid<<endl;
      cin>>tmp;
      if(tmp==1)
         l=mid+1;
      else
         r=mid;
   }
   int d;
   bool sw=0;
   for(int i=0;i<29;i++){
      int k=abs(rand()*rand())%n+1;
      cout<<"? "<<k<<endl;
      cin>>a[i];
      if(a[i]!=l){
         d=l-a[i];
         sw=1;
      }
   }
   a[29]=l;
   for(int i=0;i<30;i++)
      for(int j=i+1;j<30;j++)
         if(abs(a[j]-a[i])){
            d=__gcd(d,abs(a[j]-a[i]));
            sw=1;
         }
   if(sw)
      cout<<"! "<<l-(n-1)*d<<" "<<d<<endl;
   else
      cout<<"! "<<l<<" "<<0<<endl;
}