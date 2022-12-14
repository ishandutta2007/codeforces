#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5,MOD=1e9+7;
string s;
int fail[MAXN],N,k;
void FailureFunction(string s){
   fail[0]=0;
   int i=0;
   for(int j=1;j<s.size();j++){
      while(s[i]!=s[j]&&i>0)
         i=fail[i-1];
      if(s[i]==s[j]) i++;
      fail[j]=i;
   }
}
long long int exp(int x){
   long long int ans=1,tmp=26;
   while(x){
      if(x%2)  ans*=tmp;
      x/=2;
      tmp=(tmp*tmp)%MOD;
      ans%=MOD;
   }
   return ans;
}

bool check(int x,int y){
   if(y-x>=N)  return true;
   if((y-x)%k==0) return true;
   return false;
}
int pos[MAXN],ans[MAXN],total=0;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,m;
   cin>>n>>m;
   cin>>s;
   if(m==0){
      cout<<exp(n)<<endl;
      return 0;
   }
   for(int i=1;i<=m;i++){
      cin>>pos[i];
      pos[i]--;
   }
   N=(int) s.size();
   FailureFunction(s);
   k=N-fail[N-1];
   for(int i=1;i<m;i++){
      if(check(pos[i],pos[i+1])){
         ans[pos[i]]++;ans[pos[i]+N]--;
      }
      else{
         cout<<0<<endl;
         return 0;
      }
   }
   ans[pos[m]]++;ans[pos[m]+N]--;
   for(int i=1;i<n;i++){
      ans[i]+=ans[i-1];
   }
   for(int i=0;i<n;i++)
      if(!ans[i])
         total++;
   cout<<exp(total)<<endl;
}