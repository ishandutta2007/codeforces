#include<bits/stdc++.h>
using namespace std;
struct Node{
   char type;
   int lc,rc;
   int f;
   int data;
   bool lch,rch;
   bool ans;
}T[1000100];
string s;
void dfs(int x){
   if(T[x].type=='A'){
      dfs(T[x].lc);
      dfs(T[x].rc);
      T[x].data=(T[T[x].lc].data&T[T[x].rc].data);
      if(T[T[x].lc].data==1)
         T[x].rch=true;
      if(T[T[x].rc].data==1)
         T[x].lch=true;
   }
   else if(T[x].type=='I'){
      return;
   }
   else if(T[x].type=='X'){
      dfs(T[x].lc);
      dfs(T[x].rc);
      T[x].data=(T[T[x].lc].data^T[T[x].rc].data);
      T[x].rch=true;
      T[x].lch=true;
   }
   else if(T[x].type=='N'){
      dfs(T[x].lc);
      T[x].data=1-T[T[x].lc].data;
      T[x].lch=true;
   }
   else{
      dfs(T[x].lc);
      dfs(T[x].rc);
      T[x].data=(T[T[x].lc].data|T[T[x].rc].data);
      if(T[T[x].lc].data==1){
         if(T[T[x].rc].data==1){
            T[x].rch=T[x].lch=false;
         }
         else{
            T[x].lch=true;
            T[x].rch=false;
         }
      }
      else{
         if(T[T[x].rc].data==1){
            T[x].rch=true;
            T[x].lch=false;
         }
         else{
            T[x].lch=T[x].rch=true;
         }
      }
   }
}
void dfs2(int x){
   T[x].ans=true;
   if(T[x].type=='A'){
      if(T[x].lch)
         dfs2(T[x].lc);
      if(T[x].rch)
         dfs2(T[x].rc);
   }
   else if(T[x].type=='I'){
      return;
   }
   else if(T[x].type=='X'){
      if(T[x].lch)
         dfs2(T[x].lc);
      if(T[x].rch)
         dfs2(T[x].rc);
   }
   else if(T[x].type=='N'){
      if(T[x].lch)
         dfs2(T[x].lc);
   }
   else{
      if(T[x].lch)
         dfs2(T[x].lc);
      if(T[x].rch)
         dfs2(T[x].rc);
   }
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>s;
      if(s[0]=='A'){
         T[i].type='A';
         cin>>T[i].lc>>T[i].rc;
         T[T[i].lc].f=T[T[i].rc].f=i;
      }
      else if(s[0]=='I'){
         T[i].type='I';
         cin>>T[i].data;
      }
      else if(s[0]=='O'){
         T[i].type='O';
         cin>>T[i].lc>>T[i].rc;
         T[T[i].lc].f=T[T[i].rc].f=i;
      }
      else if(s[0]=='N'){
         T[i].type='N';
         cin>>T[i].lc;
         T[T[i].lc].f=i;
      }
      else{
         T[i].type='X';
         cin>>T[i].lc>>T[i].rc;
         T[T[i].lc].f=T[T[i].rc].f=i;
      }

   }
   dfs(1);
   dfs2(1);
   for(int i=1;i<=n;i++){
      if(T[i].type=='I'){
         if(T[i].ans)
            cout<<1-T[1].data;
         else
            cout<<T[1].data;
      }
   }
   cout<<endl;
}