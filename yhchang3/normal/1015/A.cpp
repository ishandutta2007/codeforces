#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,m,l,r;
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      cin>>l>>r;
      for(int j=l;j<=r;j++)
         a[j]++;
   }
   int cnt=0;
   for(int i=1;i<=m;i++){
      if(!a[i])
         cnt++;
   }
   cout<<cnt<<endl;
   int aa=cnt;
   for(int i=1;i<=m;i++){
      if(!a[i]){
         cout<<i;
         cnt--;
         if(cnt)
            cout<<' ';
      }
   }
   if(aa)
      cout<<endl;
}