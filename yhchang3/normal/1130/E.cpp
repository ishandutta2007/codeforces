#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int k,now,A,delta;
   cin>>k;
   now=(k+1000000)/2000*2000;
   A=now-k;
   delta=now/2000;
   cout<<2000<<endl;
   for(int i=1;i<=1998;i++)
      cout<<0<<' ';
   cout<<-A+delta<<' ';
   cout<<A<<endl;
}