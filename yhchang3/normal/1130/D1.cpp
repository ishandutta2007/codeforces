#include<bits/stdc++.h>
using namespace std;
vector<int> v[100];
int a,b;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++){
      cin>>a>>b;
      a--;b--;
      v[a].push_back(b);
   }
   int M=0,ans=0;
   for(int i=0;i<n;i++){
      M=max(M,(int) v[i].size());
   }
   for(int i=0;i<n;i++){
      for(int j=0;j<v[i].size();j++){
         v[i][j]=(v[i][j]+n-i)%n;
      }
      sort(v[i].begin(),v[i].end());
   }

   for(int i=0;i<n;i++){
      ans=0;
      for(int j=0;j<n;j++){
         if(v[j].size()==M){
            ans=max(ans,(j+n-i)%n+v[j][0]);
         }
         if(M!=1&&v[j].size()==M-1){
            ans=max(ans,(j+n-i)%n+v[j][0]-n);
         }
      }
      if(i!=0) cout<<' ';
      cout<<ans+(M-1)*n;
   }
   cout<<endl;
}