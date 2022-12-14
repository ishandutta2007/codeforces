#include<bits/stdc++.h>
using namespace std;
struct mirror{
   int v,l,r;
   char p;
}m[100];
int ans=0,tmp;
bool visit[100],sw;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int hl,hr,n;
   cin>>hl>>hr>>n;
   for(int i=0;i<n;i++)
      cin>>m[i].v>>m[i].p>>m[i].l>>m[i].r;
   for(int i=1;i<=n;i++){
      memset(visit,0,sizeof visit);
      double step=((i-1)*100+100-hl+(100-2*hr)*(i%2)+hr)/100000.0;
      double be=(100-hl)/step;
      step=100/step;
      tmp=0;
      for(int j=0;j<i;j++){
         double now=be+step*j;
         sw=0;
         if(j%2){
            for(int k=0;k<n;k++)
               if(m[k].p=='F'&&now>=m[k].l&&now<=m[k].r&&!visit[k]){
                  sw=1;visit[k]=true;tmp+=m[k].v;
                  break;
               }
         }
         else{
            for(int k=0;k<n;k++)
               if(m[k].p=='T'&&now>=m[k].l&&now<=m[k].r&&!visit[k]){
                  sw=1;visit[k]=true;tmp+=m[k].v;
                  break;
               }
         }
         if(sw)
            continue;
         else
            break;
      }
      if(!sw)
         continue;
      ans=max(ans,tmp);
   }
   for(int i=1;i<=n;i++){
      memset(visit,0,sizeof visit);
      double step=((i-1)*100+hl+(2*hr-100)*(i%2)+100-hr)/100000.0;
      double be=hl/step;
      step=100/step;
      tmp=0;
      for(int j=0;j<i;j++){
         double now=be+step*j;
         sw=0;
         if(j%2){
            for(int k=0;k<n;k++)
               if(m[k].p=='T'&&now>=m[k].l&&now<=m[k].r&&!visit[k]){
                  sw=1;visit[k]=true;tmp+=m[k].v;
                  break;
               }
         }
         else{
            for(int k=0;k<n;k++)
               if(m[k].p=='F'&&now>=m[k].l&&now<=m[k].r&&!visit[k]){
                  sw=1;visit[k]=true;tmp+=m[k].v;
                  break;
               }
         }
         if(sw)
            continue;
         else
            break;
      }
      if(!sw)
         continue;
      ans=max(ans,tmp);
   }
   cout<<ans<<endl;
}