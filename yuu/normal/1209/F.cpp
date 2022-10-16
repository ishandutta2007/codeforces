#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt=0;
int f[1000001][10];
vector <pair <int, int>> g[1000001];
vector <int> edges[1000001];
int u[1000001];
int v[1000001];
int d[1000001];
bool done[1000001];
vector <int> get(int x){
  vector <int> res;
  while(x>0){
    res.push_back(x%10);
    x/=10;
  }
  reverse(res.begin(), res.end());
  return res;
}
void insert(int i, vector <int> a, int j){
  // cerr<<i<<' '<<j<<' '<<a.size()<<'\n';
  int rem=a.size();
  for(int x: a){
    rem--;
    if(rem==0){
      g[i].push_back(make_pair(x, j));
      return;
    }
    if(f[i][x]) i=f[i][x];
    else{
      cnt++;
      f[i][x]=cnt;
      g[i].push_back(make_pair(x, cnt));
      i=cnt;
    }
  }
}
queue <int> q;
void bfs(){
  q.push(1);
  done[1]=1;
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(auto v: g[u]) if(!done[v.second]){
      done[v.second]=1;
      d[v.second]=d[u]+1;
      q.push(v.second);
    }
  }
}
const long long base=1000000007;
long long ans[1000001];
void get_answer(vector <int> &now, long long res){
  // cerr<<now.size()<<'\n';
  for(int i: now) if(i<=n) ans[i]=res;
  vector <int> all;
  for(int i=0; i<10; i++){
    all.clear();
    for(auto x: now) for(auto p: g[x]) if(p.first==i){ 
      if(!done[p.second]){
        done[p.second]=1;
        all.push_back(p.second);
      }
    }
    if(!all.empty()) get_answer(all, (res*10+i)%base);;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin>>n>>m;
  // cerr<<"OK\n";
  for(int i=1; i<=m; i++){
    cin>>u[i]>>v[i];
    edges[u[i]].push_back(i);
    edges[v[i]].push_back(i);
  }
  cnt=n;
  for(int i=1; i<=n; i++) for(auto x: edges[i]) insert(i, get(x), u[x]^v[x]^i);
  bfs();
  for(int i=1; i<=cnt; i++){
    vector <pair <int, int>> temp;
    for(auto p: g[i]) if(d[p.second]==d[i]+1) temp.push_back(p);
    g[i]=temp;
  }
  for(int i=1; i<=cnt; i++) done[i]=0;
  vector <int> now;
  now.push_back(1);
  get_answer(now, 0);
  for(int i=2; i<=n; i++) cout<<ans[i]<<'\n';
}