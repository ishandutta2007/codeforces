#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010,mod = 1e9+7;
int parent[MAXN],Rank[MAXN]; //we cant use rank as a variable in C++
void Init(){
   for(int i=1;i<=MAXN;i++){
      parent[i]=i;
      Rank[i]=1;
   }
}
int Find(int x){ // Path Compression
   return x==parent[x] ? x : parent[x] = Find(parent[x]);
}
void Union(int x,int y){ //Union by Rank
   int rootx = Find(x),rooty = Find(y);
   if(rootx!=rooty){
      if(Rank[rootx] < Rank[rooty])    swap(rootx,rooty);
      parent[rooty]=rootx;
      if(Rank[rootx] == Rank[rooty])    Rank[rootx]++;
   }
}
int cnt[MAXN];
long long int ex(long long int x,int y){
   long long int res=1;
   while(y){
      if(y&1)
         res=res*x%mod;
      x=x*x%mod;
      y/=2;
   }
   return res;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,k,x,y,z;
   cin>>n>>k;
   Init();
   for(int i=1;i<n;i++){
      cin>>x>>y>>z;
      if(z==0)
         Union(x,y);
   }
   long long int ans=0;
   for(int i=1;i<=n;i++)
      cnt[Find(i)]++;
   for(int i=1;i<=n;i++)
      if(cnt[i]!=0)
         ans=(ans+ex(cnt[i],k))%mod;
   ans=(ex(n,k)+mod-ans)%mod;
   cout<<ans<<endl;


}