#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;
   long long int L,v,l,r;
   while(t--){
      cin>>L>>v>>l>>r;
         cout<<L/v+(l-1)/v-(r)/v<<endl;
   }
}