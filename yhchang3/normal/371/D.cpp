#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;
int parent[MAXN];
void init(int n){
   for(int i=1;i<=n;i++)
      parent[i]=i;
}
int Find(int x){
   return x==parent[x]?x:parent[x]=Find(parent[x]);
}
void Union(int a,int b){
   parent[Find(a)]=Find(b);
}
int n,m,c[MAXN],d[MAXN];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++)
      cin>>c[i];
   init(n+1);
   cin>>m;
   int op,x,k,p;
   for(int i=1;i<=m;i++){
      cin>>op;
      if(op==2){
         cin>>k;
         cout<<d[k]<<endl;
      }
      else{
         cin>>p>>x;
         p=Find(p);
         while(x>0&&p<=n){
            int y=min(x,c[p]-d[p]);
            d[p]+=y;
            x-=y;
            if(c[p]==d[p]) Union(p,p+1);
            p=Find(p);
         }
      }
   }
}