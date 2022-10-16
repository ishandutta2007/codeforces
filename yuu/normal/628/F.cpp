#include <bits/stdc++.h>
using namespace std;
int n, b, q;
vector <pair <int, int> > v;
class maxflow{
public:
  class edge{
  public:
    using pointer=edge*;
    int v, c;
    pointer r;
    edge(int v, int c): v(v), c(c){}
  };
  void add_edge(int u, int v, int c){
    g[u].push_back(new edge(v, c));
    g[v].push_back(new edge(u, 0));
    g[u].back()->r=g[v].back();
    g[v].back()->r=g[u].back();
  }
  queue <int> q;
  vector <edge::pointer> g[11111];
  edge::pointer trace[11111];
  int source, sink;
  int done[11111];
  int t=0;
  bool bfs(){
    t++;
    while(!q.empty()) q.pop();
    q.push(source);
    done[source]=1;
    int u;
    while(!q.empty()){
      u=q.front();
      q.pop();
      for(auto i: g[u]) if(i->c) if(done[i->v]!=t){
        done[i->v]=t;
        q.push(i->v);
        trace[i->v]=i;
        if(i->v==sink) return 1;
      }
    }
    return 0;
  }
  int mf;
  void increase_flow(){
    int c=1e9;
    int u=sink;
    while(u!=source){
      c=min(c, trace[u]->c);
      u=trace[u]->r->v;
    }
    mf+=c;
    u=sink;
    while(u!=source){
      trace[u]->c-=c;
      trace[u]->r->c+=c;
      u=trace[u]->r->v;
    }
  }
  int max_flow(int s, int t){
    source=s;
    sink=t;
    mf=0;
    while(bfs()) increase_flow();
    return mf;
  }
} F;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin>>n>>b>>q;
  v.resize(q);
  for(auto &t: v) cin>>t.first>>t.second;
  v.push_back({0, 0});
  v.push_back({b, n});
  sort(v.begin(), v.end());
  {
    vector <pair <int, int>> temp;
    temp.push_back(v[0]);
    for(int i=1; i<v.size(); i++){
      if(v[i].first==v[i-1].first){
        if(v[i].second!=v[i-1].second){
          cout<<"unfair\n";
          return 0;
        }
      }
      else temp.push_back(v[i]);
    }
    v=temp;
  }
  for(int i=1; i<v.size(); i++) if(v[i].second<v[i-1].second){
    cout<<"unfair\n";
    return 0;
  }
  int u=7;
  for(int i=1; i<v.size(); i++){
    int s=0;
    int cnt[5];
    for(int j=0; j<5; j++) cnt[j]=0;
    for(int j=v[i-1].first+1; j<=v[i].first; j++) cnt[j%5]++;
    F.add_edge(u, 6, v[i].second-v[i-1].second);
    for(int j=0; j<5; j++) if(cnt[j]) F.add_edge(j, u, cnt[j]);
    u++;
  }
  for(int i=0; i<5; i++) F.add_edge(5, i, n/5);
  cout<<((F.max_flow(5, 6)==n)?"fair\n":"unfair\n");
}