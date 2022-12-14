#include<bits/stdc++.h>
using namespace std;
long long int yprime[2000005];
vector<pair<long long int ,long long int> > v;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   long long int x,y;
   cin>>n;
   for(int i=0;i<=2000001;i++)
      yprime[i]=-1e18;
   for(int i=0;i<n;i++){
      cin>>x>>y;
      x+=1000000;
      yprime[x]=max(yprime[x],y-x*x);
   }
   for(int i=0;i<=2000001;i++){
      if(yprime[i]!=-1e18){
         while(v.size()>=2&&(v[v.size()-1].first-v[v.size()-2].first)*(yprime[i]-v[v.size()-2].second)>=(i-v[v.size()-2].first)*(v[v.size()-1].second-v[v.size()-2].second))
            v.pop_back();
         v.push_back({i,yprime[i]});
      }
   }
   cout<<v.size()-1<<endl;
}