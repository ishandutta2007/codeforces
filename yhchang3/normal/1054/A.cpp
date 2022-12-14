#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int x,y,z,t1,t2,t3,ts,te;
   cin>>x>>y>>z>>t1>>t2>>t3;
   ts=abs(x-y)*t1;
   te=(abs(x-y)+abs(z-x))*t2+3*t3;
   if(ts<te)
      cout<<"NO"<<endl;
   else
      cout<<"YES"<<endl;
}