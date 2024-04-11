#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   cin>>s;

   long long int ans=0;
   for(int i=0;i<n;i++)
      if(((int) s[i]-'0')%2==0)
         ans=ans+i+1;
   cout<<ans<<endl;
}