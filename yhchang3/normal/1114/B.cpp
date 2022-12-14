#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[300000];
int b[300000];
vector<int> v;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,m,k;
   long long int ans=0;
   cin>>n>>m>>k;
   for(int i=0;i<n;i++){
      cin>>a[i].first;
      a[i].second=i;
   }

   sort(a,a+n);
   for(int i=1;i<=m*k;i++){
      ans+=a[n-i].first;
      v.push_back(a[n-i].second);
   }
   sort(v.begin(),v.end());
   cout<<ans<<endl;
   for(int i=0;i<k-1;i++){
      if(i!=0)
         cout<<' ';
      cout<<v[(i+1)*m-1]+1;
   }
   cout<<endl;

}