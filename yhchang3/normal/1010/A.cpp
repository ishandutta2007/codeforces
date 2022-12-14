#include<bits/stdc++.h>
using namespace std;
int a[2000],b[2000];
double ans;
void calc(int x){
   ans=(ans/(x-1))*x;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++)
      cin>>a[i];
   for(int i=1;i<=n;i++)
      cin>>b[i];
   for(int i=1;i<=n;i++)
      if(a[i]==1||b[i]==1){
         cout<<-1<<endl;
         return 0;
      }
   ans=m;
   calc(b[1]);
   for(int i=n;i>=2;i--){
      calc(a[i]);
      calc(b[i]);
   }
   calc(a[1]);
   cout<<fixed<<setprecision(8)<<ans-m<<endl;
}