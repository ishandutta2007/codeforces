#include<bits/stdc++.h>
using namespace std;
int n,k;
const int MAXN = 1e5,MAXLOG=17;
int parent[MAXLOG+1][MAXN+1],depth[MAXN+1],dfn[MAXN+1],cnt;
vector<int> edge[MAXN+1];
set<pair<int,int> > s;
void dfs(int now,int father){
   dfn[now]=++cnt;
   parent[0][now]=father;
   for(int i=0;i+1<=MAXLOG;i++)
      parent[i+1][now]=parent[i][parent[i][now]];
   for(int i=0;i<edge[now].size();i++){
      int next=edge[now][i];
      if(next!=father){
         depth[next]=depth[now]+1;
         dfs(next,now);
      }
   }
}
int LCA(int a,int b){
   if(depth[a]>depth[b])
      swap(a,b);
   int tmp=0;
   for(int i=depth[b]-depth[a];i;i/=2){
      if(i&1)  b=parent[tmp][b];
      tmp++;
   }
   if(a==b) return a;
   for(int i=MAXLOG;i>=0;i--)
      if(parent[i][a]!=parent[i][b]){
         a=parent[i][a];
         b=parent[i][b];
      }
   return parent[0][a];
}
int dist(int a,int b){
   return depth[a]+depth[b]-2*depth[LCA(a,b)];
}
int ans;
void ins(int x){
   set<pair<int,int> >::iterator it=s.insert({dfn[x],x}).first,pre,nxt,head=s.begin(),tail=--s.end();
   if(s.size()==1)   return ;
   if(it==head)   pre=tail;
   else{pre=--it;it++;}
   if(it==tail)   nxt=head;
   else{nxt=++it;it--;}
   ans=ans+(dist(pre->second,x)+dist(x,nxt->second)-dist(pre->second,nxt->second))/2;
}
void del(int x){
   set<pair<int,int> >::iterator it=s.find({dfn[x],x}),pre,nxt,head=s.begin(),tail=--s.end();
   if(s.size()==1){
      s.erase(it);
      return;
   }
   if(it==head)   pre=tail;
   else{pre=--it;it++;}
   if(it==tail)   nxt=head;
   else{nxt=++it;it--;}
   ans=ans-(dist(pre->second,x)+dist(x,nxt->second)-dist(pre->second,nxt->second))/2;
   s.erase(it);
}
int ansans=0;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>k;
   for(int i=1,a,b;i<n;i++){
      cin>>a>>b;
      edge[a].push_back(b);
      edge[b].push_back(a);
   }
   dfs(1,0);
   for(int l=1,r=1;r<=n;r++){
      ins(r);
      while(ans>=k)  del(l++);
      ansans=max(ansans,r-l+1);
   }
   cout<<ansans<<endl;
}