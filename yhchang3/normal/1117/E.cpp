#include<bits/stdc++.h>
using namespace std;
string s;
string sask,stmp,sans;
int a[3][10000],tmp;
int ans[10000];
int R[3][10000];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>s;
   int n=((int) s.size());
   for(int i=0;i<n;i++){
      tmp=i;
      for(int j=0;j<=2;j++){
         a[j][i]=tmp%26;
         tmp/=26;
      }
   }
   for(int i=0;i<=2;i++){
      sask.clear();
      for(int j=0;j<n;j++)
         sask+=char(a[i][j]+'a');
      sask+="\n";
      cout<<"? "<<sask<<endl;
      cin>>stmp;
      for(int j=0;j<n;j++)
         R[i][j]=stmp[j]-'a';
   }
   for(int i=0;i<n;i++)
      sans+=' ';
   for(int i=0;i<n;i++)
      sans[26*26*R[2][i]+26*R[1][i]+R[0][i]]=s[i];
   sans+='\n';
   cout<<"! "<<sans<<endl;
}