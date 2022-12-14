#include<bits/stdc++.h>
using namespace std;
struct cell{
   pair<int,int> pre;
   int edge;
};
cell dp[1010][5001];
queue<pair<int,int> > q;
vector<int> ans;
int x,y,tmpx,tmpy;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int d,s;
   cin>>d>>s;
   for(int i=0;i<=1000;i++)
      for(int j=0;j<=5000;j++)
         dp[i][j].edge=-1;
   q.push({0,0});
   while(!q.empty()){
      pair<int,int> now=q.front();q.pop();
      for(int i=0;i<=9;i++){
         x=(now.first*10+i)%d;
         y=now.second+i;
         if(dp[x][y].edge==-1){
            dp[x][y]={{now.first,now.second},i};
            q.push({x,y});
         }
         if(y==s&&x==0){
            while(y!=0){
               ans.push_back(dp[x][y].edge);
               tmpx=dp[x][y].pre.first;
               tmpy=dp[x][y].pre.second;
               x=tmpx;
               y=tmpy;
            }
            reverse(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++)
               cout<<ans[i];
            cout<<endl;
            return 0;
         }
      }
   }
   cout<<-1<<endl;
}