#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int fail[MAXN];
long long int f1[MAXN],f2[MAXN],fp[MAXN],ft[MAXN],ans=0;
char s1[MAXN],s2[MAXN];
char tmp,last;
string pattern,text;
vector<int> v;
void FailureFunction(string s){
   fail[0]=0;
   int i=0;
   for(int j=1;j<s.size();j++){
      while((s[i]!=s[j]||fp[i]!=fp[j])&&i>0)
         i=fail[i-1];
      if(s[i]==s[j]&&fp[i]==fp[j])  i++;
      fail[j]=i;
   }
}
void KMP(string text,string pattern){
   FailureFunction(pattern);
   int i=0;
   for(int j=0;j<text.size();j++){
      while((pattern[i]!=text[j]||fp[i]!=ft[j])&&i>0)
         i=fail[i-1];
      if(pattern[i]==text[j]&&fp[i]==ft[j])  i++;
      if(i==pattern.size()){
         v.push_back(j-i+1);
         i=fail[i-1];
      }
   }
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,m;
   last='$';
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      cin>>f1[i];
      cin>>tmp>>tmp;
      if(tmp==last){
         i--;n--;
         f1[i]+=f1[i+1];
      }
      s1[i]=tmp;
      last=tmp;
   }
   last='$';
   for(int i=1;i<=m;i++){
      cin>>f2[i];
      cin>>tmp>>tmp;
      if(tmp==last){
         i--;m--;
         f2[i]+=f2[i+1];
      }
      s2[i]=tmp;
      last=tmp;
   }
   if(m==1){
      for(int i=1;i<=n;i++){
         if(s1[i]!=s2[1])  continue;
         ans+=max((long long int)0,f1[i]-f2[1]+1);
      }
      cout<<ans<<endl;
      return 0;
   }
   if(m==2){
      for(int i=1;i<n;i++){
         if(s1[i]!=s2[1])  continue;
         if(s1[i+1]!=s2[2])   continue;
         if(f1[i]<f2[1])   continue;
         if(f1[i+1]<f2[2]) continue;
         ans++;
      }
      cout<<ans<<endl;
      return 0;
   }
   for(int i=2;i<m;i++){
      fp[i-2]=f2[i];
      pattern+=s2[i];
   }
   for(int i=1;i<=n;i++){
      ft[i-1]=f1[i];
      text+=s1[i];
   }
   KMP(text,pattern);
   for(int i=0;i<v.size();i++){
      if(v[i]==0||v[i]==text.size()-1) continue;
      if(text[v[i]-1]!=s2[1]) continue;
      if(text[v[i]+m-2]!=s2[m])  continue;
      if(ft[v[i]-1]<f2[1]) continue;
      if(ft[v[i]+m-2]<f2[m])  continue;
      ans++;
   }
   cout<<ans<<endl;
}