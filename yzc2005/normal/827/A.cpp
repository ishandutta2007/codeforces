#include <bits/stdc++.h>
using namespace std; 
const int N=2e6+5;
int n,m,len[N];
string t[N],s;
vector<pair<int,int>>pos[N];
int main(){
  cin>>n;
  for(int i=1;i<=n;++i){
    int k;
    cin>>t[i]>>k;
    len[i]=t[i].length();
    while(k--){
      int x;
      cin>>x;
      --x;
      pos[x].emplace_back(x+len[i]-1,i);
      m=max(m,x+len[i]);
    }
  }
  queue<pair<int,int>>que;
  s.resize(m);
  for(int i=0;i<m;++i){
    for(auto p:pos[i])que.push(p);
    while(!que.empty()&&que.front().first<i){
      que.pop();
    }
    if(que.empty()){
      s[i]='a';
    }else{
      int x,y;
      tie(x,y)=que.front();
      s[i]=t[y][len[y]-(x-i)-1];
    }
  }
  cout<<s<<endl;
  return 0;
}