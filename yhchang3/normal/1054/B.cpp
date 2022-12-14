#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,m=-1;
   cin>>n;
   for(int i=1;i<=n;i++)
      cin>>a[i];
   for(int i=1;i<=n;i++){
      if(a[i]>m+1){
         cout<<i<<endl;
         return 0;
      }
      m=max(m,a[i]);
   }
   cout<<-1<<endl;
}