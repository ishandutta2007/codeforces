#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t;
   cin>>t;
   while(t--){
      bool sw=0;
      cin>>s;
      for(int i=1;i<s.size();i++){
         if(s[0]!=s[i]){
            swap(s[(int)s.size()-1],s[i]);
            cout<<s<<endl;
            sw=1;
            break;
         }
      }
      if(sw)   continue;
      else  cout<<-1<<endl;
   }
}