#include<bits/stdc++.h>
using namespace std;
bool a[2000],b[2000];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,s;
   cin>>n>>s;
   for(int i=1;i<=n;i++)
      cin>>a[i];
   for(int i=1;i<=n;i++)
      cin>>b[i];
   if(a[1]==false){
      cout<<"NO"<<endl;
      return 0;
   }
   if(a[s]==true){
      cout<<"YES"<<endl;
      return 0;
   }
   if(b[s]==false){
      cout<<"NO"<<endl;
      return 0;
   }
   bool flag=false;
   for(int i=s+1;i<=n;i++){
      if(a[i]==true&&b[i]==true)
         flag=true;
   }
   if(flag) cout<<"YES"<<endl;
   else  cout<<"NO"<<endl;
}