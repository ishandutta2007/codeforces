#include<bits/stdc++.h>
using namespace std;
int l[1010],r[1010],ans[1010],now;
bool visit[1010],flag1,flag2;
vector<int> v;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   now=n;
   for(int i=1;i<=n;i++)
      cin>>l[i];
   for(int i=1;i<=n;i++)
      cin>>r[i];
   while(true){
      flag1=0;
      for(int i=1;i<=n;i++)
         if(!visit[i])  flag1=true;
      if(!flag1)  break;
      v.clear();
      for(int i=1;i<=n;i++){
         if(!visit[i]&&l[i]==0&&r[i]==0){
            visit[i]=true;
            v.push_back(i);
            ans[i]=now;
         }
      }
      if(v.size()==0){
         cout<<"NO"<<endl;
         return 0;
      }
      for(int i=1;i<=n;i++){
         for(int j=0;j<v.size();j++){
            if(i<v[j])  r[i]--;
            else if(i>v[j])   l[i]--;
         }
      }
      now--;
   }
   cout<<"YES"<<endl;
   for(int i=1;i<=n;i++){
      if(i!=1) cout<<' ';
      cout<<ans[i];
   }
   cout<<endl;
}