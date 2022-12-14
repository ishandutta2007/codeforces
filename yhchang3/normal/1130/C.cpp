#include<bits/stdc++.h>
using namespace std;
string s[50];
const int MAXN = 3000;
int parent[MAXN],Rank[MAXN]; //we cant use rank as a variable in C++
void Init(){
   for(int i=0;i<MAXN;i++){
      parent[i]=i;
      Rank[i]=1;
   }
}
int Find(int x){ // Path Compression
   return x==parent[x] ? x : parent[x] = Find(parent[x]);
}
vector<pair<int,int> > v1,v2;
void Union(int x,int y){ //Union by Rank
   int rootx = Find(x),rooty = Find(y);
   if(rootx!=rooty){
      if(Rank[rootx] < Rank[rooty])    swap(rootx,rooty);
      parent[rooty]=rootx;
      if(Rank[rootx] == Rank[rooty])    Rank[rootx]++;
   }
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,rs,cs,rt,ct;
   cin>>n;
   cin>>rs>>cs>>rt>>ct;
   Init();
   rs--;cs--;rt--;ct--;
   for(int i=0;i<n;i++)
      cin>>s[i];
   for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
         if(s[i][j]=='0'){
            if(i!=0&&s[i-1][j]=='0')
               Union(i*n+j,(i-1)*n+j);
            if(i!=n-1&&s[i+1][j]=='0')
               Union(i*n+j,(i+1)*n+j);
            if(j!=0&&s[i][j-1]=='0')
               Union(i*n+j,i*n+j-1);
            if(j!=n-1&&s[i][j+1]=='0')
               Union(i*n+j,i*n+j+1);
         }
   if(Find(rs*n+cs)==Find(rt*n+ct)){
      cout<<0<<endl;
      return 0;
   }
   for(int i=0;i<n;i++)
      for(int j=0;j<n;j++){
         if(Find(rs*n+cs)==Find(i*n+j))
            v1.push_back({i,j});
         if(Find(rt*n+ct)==Find(i*n+j))
            v2.push_back({i,j});
      }
   int ans=1e9;
   for(int i=0;i<v1.size();i++)
      for(int j=0;j<v2.size();j++)
         ans=min(ans,(v1[i].first-v2[j].first)*(v1[i].first-v2[j].first)+(v1[i].second-v2[j].second)*(v1[i].second-v2[j].second));
   cout<<ans<<endl;
}