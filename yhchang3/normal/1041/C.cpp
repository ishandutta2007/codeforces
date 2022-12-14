#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
priority_queue<pii,vector<pii>,greater<pii> > pq;
vector<pii> v;
int ans[300000];
int ansans[300000];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,m,d,x;
   cin>>n>>m>>d;
   for(int i=1;i<=n;i++){
      cin>>x;
      v.push_back({x,i});
   }
   sort(v.begin(),v.end());
   int cnt=1;
   ans[0]=cnt++;
   pq.push({v[0].first+d,1});
   for(int i=1;i<n;i++){
      if(v[i].first>pq.top().first){
         int tmp=pq.top().second;
         pq.pop();
         ans[i]=tmp;
         pq.push({v[i].first+d,tmp});
      }
      else{
         ans[i]=cnt;
         pq.push({v[i].first+d,cnt++});
      }
   }
   for(int i=0;i<n;i++){
      ansans[v[i].second]=ans[i];
   }
   cout<<cnt-1<<endl;
   for(int i=1;i<=n;i++){
      if(i!=1)
         cout<<' ';
      cout<<ansans[i];
   }
   cout<<endl;
}