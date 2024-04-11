#include<bits/stdc++.h>
using namespace std;
string s1,s2;
set<char> s;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>s1>>s2;
   s.insert('a');
   s.insert('e');
   s.insert('i');
   s.insert('o');
   s.insert('u');
   if(s1.size()!=s2.size())
      cout<<"No"<<endl;
   else{
      for(int i=0;i<s1.size();i++){
         if((s.find(s1[i])!=s.end()&&s.find(s2[i])==s.end())||(s.find(s2[i])!=s.end()&&s.find(s1[i])==s.end())){
            cout<<"No"<<endl;
            exit(0);
         }
      }
      cout<<"Yes"<<endl;
   }
}