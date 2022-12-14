#include<bits/stdc++.h>
using namespace std;
string s,sans;
int cnt,ans=100000000;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,r;
   cin>>n>>r;
   for(int i=1;i<=r;i++){
      int t=i,b=r;
      cnt=0;s.clear();
      while(t!=0){
         if(t>=b){
            s+='T';
            t-=b;
         }
         else{
            s+='B';
            b-=t;
         }
         if(s.size()>1){
            if(s[(int)s.size()-1]==s[(int)s.size()-2])
               cnt++;
         }
      }
      if(b==1&&s.size()==n&&cnt<ans){
         sans=s;ans=cnt;
      }
      t=r;b=i;
      cnt=0;s.clear();
      while(t!=0){
         if(t>=b){
            s+='T';
            t-=b;
         }
         else{
            s+='B';
            b-=t;
         }
         if(s.size()>1){
            if(s[(int)s.size()-1]==s[(int)s.size()-2])
               cnt++;
         }
      }
      if(b==1&&s.size()==n&&cnt<ans){
         sans=s;ans=cnt;
      }
   }
   if(ans==100000000){
      cout<<"IMPOSSIBLE"<<endl;
      return 0;
   }
   reverse(sans.begin(),sans.end());
   cout<<ans<<endl;
   cout<<sans<<endl;
}