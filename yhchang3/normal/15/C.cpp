#include<bits/stdc++.h>
using namespace std;
long long int tmp=0,x,m;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>x>>m;
      if(x%2==0){
         if(m%2){
            tmp^=(x+m-1);
            if((m-1)%4) tmp^=1;
         }
         else{
            if(m%4)  tmp^=1;
         }
      }
      else{
         tmp^=x;
         if(m%2==0){
            tmp^=(x+m-1);
            m--;
         }
         m--;
         if(m%4)
            tmp^=1;
      }
   }
   if(tmp==0)
      cout<<"bolik"<<endl;
   else
      cout<<"tolik"<<endl;
}