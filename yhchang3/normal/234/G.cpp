#include<bits/stdc++.h>
using namespace std;
vector<int> ans[1000];
void DC(int l,int r,int depth){
   if(l==r)
      return;
   int mid=(l+r)/2;
   for(int i=l;i<=mid;i++)
      ans[depth].push_back(i);
   DC(l,mid,depth+1);
   DC(mid+1,r,depth+1);
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n;
   cin>>n;
   DC(1,n,0);
   int cnt=0;
   for(int i=0;i<=999;i++){
      if(ans[i].size())
         cnt++;
   }
   cout<<cnt<<endl;
   for(int i=0;i<cnt;i++){
      cout<<ans[i].size();
      for(int j=0;j<ans[i].size();j++)
         cout<<' '<<ans[i][j];
      cout<<endl;
   }
}