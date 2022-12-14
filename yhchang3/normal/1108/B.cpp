#include<bits/stdc++.h>
using namespace std;
int b[10001];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,a,m=0;
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>a;
      b[a]++;
      m=max(m,a);
   }
   for(int i=1;i<=m;i++){
      if(m%i==0)
         b[i]--;
   }
   for(int i=m;i>0;i--){
      if(b[i]){
         cout<<m<<' '<<i<<endl;
         return 0;
      }
   }
}