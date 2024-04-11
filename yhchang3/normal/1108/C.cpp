#include<bits/stdc++.h>
using namespace std;
int n,cnt[6];
string s,sans[6];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n;
   cin>>s;
   for(int j=0;j<n;j++){
      if(j%3==0)
         sans[0]+='R';
      if(j%3==1)
         sans[0]+='G';
      if(j%3==2)
         sans[0]+='B';
   }
   for(int j=0;j<n;j++){
      if(j%3==0)
         sans[1]+='R';
      if(j%3==1)
         sans[1]+='B';
      if(j%3==2)
         sans[1]+='G';
   }
   for(int j=0;j<n;j++){
      if(j%3==0)
         sans[2]+='G';
      if(j%3==1)
         sans[2]+='R';
      if(j%3==2)
         sans[2]+='B';
   }
   for(int j=0;j<n;j++){
      if(j%3==0)
         sans[3]+='G';
      if(j%3==1)
         sans[3]+='B';
      if(j%3==2)
         sans[3]+='R';
   }
   for(int j=0;j<n;j++){
      if(j%3==0)
         sans[4]+='B';
      if(j%3==1)
         sans[4]+='R';
      if(j%3==2)
         sans[4]+='G';
   }
   for(int j=0;j<n;j++){
      if(j%3==0)
         sans[5]+='B';
      if(j%3==1)
         sans[5]+='G';
      if(j%3==2)
         sans[5]+='R';
   }
   for(int i=0;i<6;i++)
      for(int j=0;j<n;j++)
         if(sans[i][j]!=s[j])
            cnt[i]++;
   int idx=0;
   for(int i=1;i<6;i++)
      if(cnt[idx]>cnt[i])
         idx=i;
   cout<<cnt[idx]<<endl;
   cout<<sans[idx]<<endl;


}