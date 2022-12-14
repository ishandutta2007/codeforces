#include<bits/stdc++.h>
using namespace std;

struct node{
   int lch,rch;
}Trie[5000000];
int stp=1,root=1;
long long int a[100001];

void insert(long long int x){
   int now=root;
   for(int i=40;i>=0;i--){
      if((1LL<<i)&x){
         if(!Trie[now].rch){
            ++stp;
            Trie[now].rch=stp;
         }
         now=Trie[now].rch;
      }
      else{
         if(!Trie[now].lch){
            ++stp;
            Trie[now].lch=stp;
         }
         now=Trie[now].lch;
      }
   }
}
long long int xorpre,xorsuf,ans;

long long int query(long long int x){
   long long int res=0;
   int now=root;
   for(int i=40;i>=0;i--){
      if((1LL<<i)&x){
         if(Trie[now].lch){
            res|=(1LL<<i);
            now=Trie[now].lch;
         }
         else
            now=Trie[now].rch;
      }
      else{
         if(Trie[now].rch){
            res|=(1LL<<i);
            now=Trie[now].rch;
         }
         else
            now=Trie[now].lch;
      }
   }
   return res;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>a[i];
      xorpre^=a[i];
   }
   for(int i=n-1;i>=0;i--){
      insert(xorsuf);
      ans=max(ans,query(xorpre));
      xorpre^=a[i];xorsuf^=a[i];
   }
   insert(xorsuf);
   ans=max(ans,query(xorpre));
   cout<<ans<<endl;
}