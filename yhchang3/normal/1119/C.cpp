#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[500][500];
int t[500][500];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>m;
   for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
         cin>>s[i][j];
   for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
         cin>>t[i][j];
   bool sw=0;
   for(int i=0;i<n;i++){
      int a=0,b=0;
      for(int j=0;j<m;j++){
         a+=s[i][j];
         b+=t[i][j];
      }
      if((a+b)&1) sw=1;
   }
   for(int j=0;j<m;j++){
      int a=0,b=0;
      for(int i=0;i<n;i++){
         a+=s[i][j];
         b+=t[i][j];
      }
      if((a+b)&1) sw=1;
   }
   if(sw)
      cout<<"No"<<endl;
   else
      cout<<"Yes"<<endl;
}