#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
int a[100010],b[100010];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>a[i];
      if(i!=0)
         m[a[i]-a[i-1]]++;
   }
   for(int i=0;i<n;i++){
      cin>>b[i];
      if(i!=0)
         m[b[i]-b[i-1]]--;
   }
   if(a[0]!=b[0]||a[n-1]!=b[n-1]){
      cout<<"No"<<endl;
      return 0;
   }
   for(auto i=m.begin();i!=m.end();i++){
      if(i->second!=0){
         cout<<"No"<<endl;
         return 0;
      }
   }
   cout<<"Yes"<<endl;
}