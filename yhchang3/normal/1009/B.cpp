#include<bits/stdc++.h>
using namespace std;
string s,sans;
int state,cnt[3],pos=1e7;;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>s;
   bool sw=0;
   for(int i=0;i<s.size();i++){
      if(s[i]=='2')  pos=min(pos,i);
      cnt[s[i]-'0']++;
   }
   for(int i=0;i<s.size();i++){
      if(s[i]=='1')  continue;
      if(i==pos){
         for(int j=0;j<cnt[1];j++)
            sans+='1';
         sans+='2';
      }
      else{
         sans+=s[i];
      }
   }
   if(pos>=s.size())
      for(int j=0;j<cnt[1];j++)
         sans+='1';
   cout<<sans<<endl;
   /*cin>>s;
   for(int i=0;i<s.size();i++){
      if(state==0){
         if(s[i]=='2'){
            for(int j=0;j<cnt[0];j++)
               sans+='0';
            cnt[0]=0;
            for(int j=0;j<cnt[1];j++)
               sans+='1';
            cnt[1]=0;
            cnt[2]=1;
            state=1;
         }
         else{
            cnt[s[i]-'0']++;
         }
      }
      else{
         if(s[i]=='0'){
            for(int j=0;j<cnt[1];j++)
               sans+='1';
            cnt[1]=0;
            for(int j=0;j<cnt[2];j++)
               sans+='2';
            cnt[2]=0;
            cnt[0]=1;
            state=0;
         }
         else{
            cnt[s[i]-'0']++;
         }
      }
   }
   for(int i=0;i<=2;i++)
      for(int j=0;j<cnt[i];j++)
         sans+=char('0'+i);
   cout<<sans<<endl;*/
}