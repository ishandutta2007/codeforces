#include<bits/stdc++.h>
using namespace std;
const int MAXN = 400040;
int n,m,q,a,b,cnt=-1;
bool visit[MAXN];
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
   Init();
   cin>>n>>m>>q;
   for(int i=1;i<=q;i++){
      cin>>a>>b;
      Union(a,b+n);
   }
   for(int i=1;i<=n+m;i++){
      visit[Find(i)]=1;
   }
   for(int i=1;i<=n+m;i++)
      if(visit[i])   cnt++;
   cout<<cnt<<endl;
}