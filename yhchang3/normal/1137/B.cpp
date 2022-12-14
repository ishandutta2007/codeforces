#include<bits/stdc++.h>
using namespace std;
string s,t;
const int MAXN=1e6+5;
int fail[MAXN];//the max length in 0~i that prefix==suffix
//indicate the place to go when mismatching
void FailureFunction(string pattern){
   fail[0]=0;
   for(int i=1;i<pattern.size();i++){
      fail[i]=fail[i-1];
      while(fail[i]>0&&pattern[fail[i]]!=pattern[i])
         fail[i]=fail[fail[i]-1];
      if(pattern[fail[i]]==pattern[i]) fail[i]++;
   }
}
int cnt[2];
int cnt2[2];
string sans;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>s>>t;
   for(int i=0;i<s.size();i++)
      cnt[s[i]-'0']++;
   FailureFunction(t);
   for(int i=fail[t.size()-1];i<t.size();i++)
      cnt2[t[i]-'0']++;
   for(int i=0;i<t.size();i++){
      cnt[t[i]-'0']--;
   }
   if(cnt[0]<0||cnt[1]<0){
      cout<<s<<endl;
      return 0;
   }
   sans+=t;
   int m=min((cnt2[0]?cnt[0]/cnt2[0]:1e9),(cnt2[1]?cnt[1]/cnt2[1]:1e9));
   for(int i=0;i<m;i++){
      for(int j=fail[t.size()-1];j<t.size();j++){
         sans+=t[j];
      }
   }
   cnt[0]-=m*cnt2[0];
   cnt[1]-=m*cnt2[1];
   while(cnt[0]--)
      sans+='0';
   while(cnt[1]--)
      sans+='1';
   cout<<sans<<endl;
}