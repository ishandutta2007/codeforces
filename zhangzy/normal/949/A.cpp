#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;

int n, m;
char s[404000];
deque<int>q[2];
vector<int>vec[202000];

int main(){
  cin>>s+1; n=strlen(s+1);
  for (int i=1;i<=n;++i) q[0].push_back(i);
  for (int i=1;i<=n;++i){
    int x;
    if (s[i]=='0'){
      x=q[0].front(); q[0].pop_front();
      vec[x].push_back(i);
      q[1].push_back(x);
    }else{
      if (q[1].empty()) return 0*puts("-1");
      x=q[1].front(); q[1].pop_front();
      vec[x].push_back(i);
      q[0].push_front(x);
    }
  }
  for (int i=1;i<=n;++i){
    if (vec[i].size()){
      ++m;
      if (s[vec[i].back()]=='1') return 0*puts("-1");
    }
  }
  printf("%d\n",m);
  for (int i=1;i<=n;++i){
    if (vec[i].size()){
      printf("%u ",vec[i].size()); 
      for (auto o:vec[i]) printf("%d ",o); puts("");
    }
  }
}