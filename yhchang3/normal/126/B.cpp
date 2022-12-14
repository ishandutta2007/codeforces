#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int fail[MAXN];
bool visit[MAXN];
void FailureFunction(string s){
   fail[0]=0;
   int i=0;
   for(int j=1;j<s.size();j++){
      while(s[i]!=s[j]&&i>0)
         i=fail[i-1];
      if(s[i]==s[j])   i++;
      fail[j]=i;
      if(j!=s.size()-1)
         visit[i]=true;
   }
}
string s;
void debug(){
   for(int i=0;i<7;i++)
      cout<<fail[i]<<' '<<visit[i]<<endl;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>s;
   FailureFunction(s);
   int pos=0;
   /*debug();
   return 0;*/
   for(int i=fail[int(s.size()-1)];i>0;i=fail[i-1]){
      if(visit[i]){
         pos=i;
         break;
      }
   }
   if(!pos) cout<<"Just a legend"<<endl;
   else{
      for(int i=0;i<pos;i++)
         cout<<s[i];
      cout<<endl;
   }
}