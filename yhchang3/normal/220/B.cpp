#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
struct Query{
   int l,r,block,idx;
}Q[MAXN];
int a[MAXN],tmp[MAXN],ans[MAXN],cnt=0;

bool operator<(Query a,Query b){
   return a.block==b.block? a.r<b.r:a.block<b.block;
}
void update(int pos,int val){
   if(a[pos]>100000) return;
   if(a[pos]==tmp[a[pos]])
      cnt--;
   tmp[a[pos]]+=val;
   if(a[pos]==tmp[a[pos]])
      cnt++;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++)
      cin>>a[i];
   int blocksize=round(n/sqrt(m));
   if(blocksize==0)  blocksize++;
   for(int i=1;i<=m;i++){
      cin>>Q[i].l>>Q[i].r;
      Q[i].idx=i;
      Q[i].block=Q[i].l/blocksize;
   }
   sort(Q,Q+m);
   int l=1,r=0;
   for(int i=1;i<=m;i++){
      while(r<Q[i].r) update(++r,1);
      while(r>Q[i].r) update(r--,-1);
      while(l<Q[i].l) update(l++,-1);
      while(l>Q[i].l) update(--l,1);
      ans[Q[i].idx]=cnt;
   }
   for(int i=1;i<=m;i++)
      cout<<ans[i]<<endl;
}