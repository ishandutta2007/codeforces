#include<bits/stdc++.h>
using namespace std;
int n,k,V;
bool dp[2][5000];
bool cnt[5001];
vector<int> v[5000];
int a[5001],total=0;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>k>>V;
   for(int i=1;i<=n;i++){
      cin>>a[i];
      total+=a[i];
   }
   dp[0][0]=true;
   for(int i=1;i<=n;i++){
      for(int j=0;j<k;j++)
         if(dp[(i+1)&1][j])
            dp[i&1][j]=true;
      for(int j=0;j<k;j++)
         if(dp[(i+1)&1][j]&&!dp[i&1][(j+a[i])%k]){
            v[(j+a[i])%k]=v[j];
            v[(j+a[i])%k].push_back(i);
            dp[i&1][(j+a[i])%k]=true;
         }
   }
   if(total>=V&&dp[n&1][V%k]){
      cout<<"YES"<<endl;
      for(int i=0;i<v[V%k].size();i++)
         cnt[v[V%k][i]]=true;
      int l=1,r=n;
      for(int i=1;i<=n;i++)
         if(!cnt[i])
            r=i;
      for(int i=n;i>=1;i--)
         if(cnt[i])
            l=i;
      for(int i=1;i<=n;i++){
         if(cnt[i]){
            if(i==l) continue;
            if(a[i]==0) continue;
            a[l]+=a[i];
            cout<<(a[i]-1)/k+1<<' '<<i<<' '<<l<<endl;
            a[i]=0;
         }
         else{
            if(i==r) continue;
            if(a[i]==0) continue;
            a[r]+=a[i];
            cout<<(a[i]-1)/k+1<<' '<<i<<' '<<r<<endl;
            a[i]=0;
         }
      }
      if(a[l]>V)
         cout<<(a[l]-V)/k<<' '<<l<<' '<<r<<endl;
      else if(a[l]<V)
         cout<<(V-a[l])/k<<' '<<r<<' '<<l<<endl;
   }
   else
      cout<<"NO"<<endl;
}