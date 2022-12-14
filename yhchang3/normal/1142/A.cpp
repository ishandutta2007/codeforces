#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   long long int n,k,a,b,ansx=1e15,ansy=0;
   cin>>n>>k>>a>>b;
   long long int total=n*k;
   for(int i=0;i<n;i++){
      long long int now=(i*k+b+total-a)%total;
      long long int g=total/__gcd(total,now);
      ansx=min(ansx,g);
      ansy=max(ansy,g);
   }
   for(int i=0;i<n;i++){
      long long int now=(i*k+(k-b)+total-a)%total;
      long long int g=total/__gcd(total,now);
      ansx=min(ansx,g);
      ansy=max(ansy,g);
   }
   cout<<ansx<<' '<<ansy<<endl;

}