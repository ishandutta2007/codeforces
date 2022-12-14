#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int a[100010];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,m,k;
   cin>>n>>m>>k;
   int ans=n;
   for(int i=0;i<n;i++){
      cin>>a[i];
      if(i!=0)
         v.push_back(a[i]-a[i-1]-1);
   }
   sort(v.begin(),v.end());
   for(int i=0;i<n-k;i++)
      ans+=v[i];
   cout<<ans<<endl;
}