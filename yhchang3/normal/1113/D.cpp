#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int fail[MAXN];
string s;
void FailureFunction(string s){
   fail[0]=0;
   int i=0;
   for(int j=1;j<s.size();j++){
      while(s[j]!=s[i]&&i>0)
         i=fail[i-1];
      if(s[i]==s[j]) i++;
      fail[j]=i;
   }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
   cin>>s;
   FailureFunction(s);
   int n=(int) s.size();
   bool sw=0;
   if(n%2){
      for(int i=0;i<n/2;i++)
         if(s[0]!=s[i])
            sw=true;
   }
   else{
      for(int i=0;i<n;i++)
         if(s[0]!=s[i])
            sw=true;
   }
   if(!sw){
      cout<<"Impossible"<<endl;
      return 0;
   }
   if(n%2)  cout<<2<<endl;
   else if((n%(n-fail[n-1])==0&&(n-fail[n-1])%2==0)||n%(n-fail[n-1]))
      cout<<1<<endl;
   else
      cout<<2<<endl;

}