#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;

ll n,k,x,b[5010],dp[5010][5010];
deque<pll> dq;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>k>>x;
   for(int i=1;i<=n;i++)
      cin>>b[i];
   for(int i=1;i<=n;i++)
      for(int j=0;j<=x;j++)
         dp[i][j]=-1e18;
   for(int j=1;j<=x;j++){
      dq.clear();
      dq.push_back({0,0});
      for(int i=1;i<=n;i++){
         if(dq.front().second<i-k)  dq.pop_front();
         dp[i][j]=dq.front().first+b[i];
         while(!dq.empty()&&dq.back().first<=dp[i][j-1]) dq.pop_back();
         dq.push_back({dp[i][j-1],i});
      }
   }
   long long int ans=-1e18;
   for(int i=n;i>n-k;i--)  ans=max(ans,dp[i][x]);
   if(ans>0)   cout<<ans<<endl;
   else  cout<<-1<<endl;
}