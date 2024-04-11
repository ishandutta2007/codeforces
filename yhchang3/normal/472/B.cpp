#include<bits/stdc++.h>
using namespace std;
int f[3000];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,k;
   cin>>n>>k;
   for(int i=0;i<n;i++)
      cin>>f[i];
   sort(f,f+n);
   int ans=0;
   for(int i=n-1;i>=0;i-=k)
      ans+=2*(f[i]-1);
   cout<<ans<<endl;

}