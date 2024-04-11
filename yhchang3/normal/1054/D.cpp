#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
long long int ans=0;
int a[200010],tmpa,tmpb,now=0;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,k,c;
   cin>>n>>k;
   c=round(pow(2,k));
   c-=1;
   m[0]=1;
   for(int i=1;i<=n;i++)
      cin>>a[i];
   for(int i=1;i<=n;i++){
      tmpa=m[a[i]^now];
      tmpb=m[(c-a[i])^now];
      if(tmpa>tmpb)
         now^=(c-a[i]);
      else
         now^=a[i];
      m[now]++;
      ans+=i-min(tmpa,tmpb);
   }
   cout<<ans<<endl;

}