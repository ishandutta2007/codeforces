#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int x,y,z,a,b,c;
   cin>>x>>y>>z>>a>>b>>c;
   if((a>=x)&&(a+b)>=x+y&&(a+b+c)>=(x+y+z))
      cout<<"YES"<<endl;
   else
      cout<<"NO"<<endl;
}