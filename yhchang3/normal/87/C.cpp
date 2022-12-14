#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int mex[100][MAXN];
int sg[MAXN];
int ans[MAXN];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   for(int i=1;i<=100000;i++){
      for(int j=0;j<100;j++){
         if(mex[j][i]==0){
            sg[i]=j;
            break;
         }
      }
      if(sg[i]==0)
         ans[i]=-1;
      else
         ans[i]=mex[0][i];
      int cnt=0,tmp=0;
      int k=i;
      while(cnt+k<=100000&&k>=1){
         cnt+=k;
         tmp^=sg[k];
         if(tmp<=100)
            mex[tmp][cnt]=i-k+1;
         k--;
      }
   }
   int n;
   cin>>n;
   cout<<ans[n]<<endl;
}