#include<bits/stdc++.h>
using namespace std;
int a[31],b[31],p[31];
struct op{
   int num[31];
   int stp;
}tmp,now;
long long int ans=-2e18,k[31];
queue<op> q;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,u,r;
   cin>>n>>u>>r;
   for(int i=1;i<=n;i++)
      cin>>a[i];
   for(int i=1;i<=n;i++)
      cin>>b[i];
   for(int i=1;i<=n;i++)
      cin>>k[i];
   for(int i=1;i<=n;i++)
      cin>>p[i];
   for(int i=1;i<=n;i++)
      tmp.num[i]=a[i];
   tmp.stp=0;
   q.push(tmp);
   while(!q.empty()){
      now=q.front();q.pop();
      if((u-now.stp)%2==0){
         long long int cnt=0;
         for(int i=1;i<=n;i++)
            cnt+=now.num[i]*k[i];
         ans=max(ans,cnt);
      }
      else{
         long long int cnt=0;
         for(int i=1;i<=n;i++)
            cnt+=(now.num[i]^b[i])*k[i];
         ans=max(ans,cnt);
      }
      if(now.stp==u) continue;
      if(now.stp==u-1){
         for(int i=1;i<=n;i++)
            tmp.num[i]=now.num[i]^b[i];
         tmp.stp=now.stp+1;
         q.push(tmp);
         for(int i=1;i<=n;i++)
            tmp.num[i]=now.num[p[i]]+r;
         tmp.stp=now.stp+1;
         q.push(tmp);
         continue;
      }
      for(int i=1;i<=n;i++)
         tmp.num[i]=now.num[p[i]]+r;
      tmp.stp=now.stp+1;
      q.push(tmp);
      for(int i=1;i<=n;i++)
         now.num[i]^=b[i];
      for(int i=1;i<=n;i++)
         tmp.num[i]=now.num[p[i]]+r;
      tmp.stp=now.stp+2;
      q.push(tmp);
   }
   cout<<ans<<endl;
}