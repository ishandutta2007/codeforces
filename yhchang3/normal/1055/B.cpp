#include<bits/stdc++.h>
using namespace std;
long long int a[100050];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,m,l,ans=0,op,tmpa,tmpb;
   cin>>n>>m>>l;
   for(int i=1;i<=n;i++){
      cin>>a[i];
      if(a[i]>l&&a[i-1]<=l)   ans++;
   }
   while(m--){
      cin>>op;
      if(op==0){
         cout<<ans<<endl;
      }
      else{
         cin>>tmpa>>tmpb;
         if(a[tmpa]>l||a[tmpa]+tmpb<=l){
            a[tmpa]+=tmpb;
            continue;
         }
         a[tmpa]+=tmpb;
         if(a[tmpa-1]>l&&a[tmpa+1]>l)
            ans--;
         else if(a[tmpa-1]<=l&&a[tmpa+1]<=l)
            ans++;
      }
   }
}