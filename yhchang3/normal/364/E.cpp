#include<bits/stdc++.h>
using namespace std;
int n,m,k;
string s;
int bound1[10],bound2[10];
bool graph[2501][2501];
int pre[2501][2501];
long long int ans=0;
int calc(int x1,int y1,int x2,int y2){
   return pre[x2][y2]-pre[x2][y1]-pre[x1][y2]+pre[x1][y1];
}
int cnt=0;
void solve(int x1,int y1,int x2,int y2,bool vertical){
   if(x1==x2||y1==y2)
      return;
   if(x2-x1==1&&y2-y1==1){
      ans+=(graph[x2][y2]==k);
      return;
   }
   if(vertical){
      int mid=(x1+x2)/2;
      solve(x1,y1,mid,y2,!vertical);
      solve(mid,y1,x2,y2,!vertical);
      bound1[0]=bound2[0]=mid;
      bound1[k+2]=x1;bound2[k+2]=x2;
      for(int i=y1;i<y2;i++){
         for(int j=i+1;j<=y2;j++){
            for(int kk=k+1;kk>0;kk--){
               if(j==i+1){
                  bound1[kk]=bound1[kk+1];
                  bound2[kk]=bound2[kk+1];
               }
               while(bound1[kk]<mid&&calc(bound1[kk],i,mid,j)>=kk)
                  bound1[kk]++;
               while(bound2[kk]>mid&&calc(mid,i,bound2[kk],j)>=kk)
                  bound2[kk]--;
            }
            for(int kk=0;kk<=k;kk++)
               ans+=(bound1[kk]-bound1[kk+1])*(bound2[k-kk+1]-bound2[k-kk]);
         }
      }
   }else{
      int mid=(y1+y2)/2;
      solve(x1,y1,x2,mid,!vertical);
      solve(x1,mid,x2,y2,!vertical);
      bound1[0]=bound2[0]=mid;
      bound1[k+2]=y1;bound2[k+2]=y2;
      for(int i=x1;i<x2;i++){
         for(int j=i+1;j<=x2;j++){
            for(int kk=k+1;kk>0;kk--){
               if(j==i+1){
                  bound1[kk]=bound1[kk+1];
                  bound2[kk]=bound2[kk+1];
               }
               while(bound1[kk]<mid&&calc(i,bound1[kk],j,mid)>=kk)
                  bound1[kk]++;
               while(bound2[kk]>mid&&calc(i,mid,j,bound2[kk])>=kk)
                  bound2[kk]--;
            }
            for(int kk=0;kk<=k;kk++){
               ans+=(bound1[kk]-bound1[kk+1])*(bound2[k-kk+1]-bound2[k-kk]);
            }

         }
      }
   }
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>m>>k;
   for(int i=1;i<=n;i++){
      cin>>s;
      for(int j=1;j<=m;j++)
         graph[i][j]=(s[j-1]=='1');
   }
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+graph[i][j];
   solve(0,0,n,m,0);
   cout<<ans<<endl;
}