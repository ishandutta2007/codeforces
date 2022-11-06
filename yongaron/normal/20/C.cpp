#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

#define ll long long

using namespace std;

const int N = 1e5+5;
const ll inf = 1e15;

int n, m;

vector<int> graf[N];
vector<ll> delky[N];

ll dist[N];
int from[N];

priority_queue<pair<ll, int>> q;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m;
  ll a, b, w;
  for(int i = 0; i < m; i++)
  {
    cin>>a>>b>>w;
    graf[a].push_back(b);
    graf[b].push_back(a);
    delky[a].push_back(w);
    delky[b].push_back(w);
  }
  for(int i = 1; i <= n; i++)
    dist[i] = inf;
  dist[n] = 0;
  from[n] = 0;
  q.push({0, n});
  while(!q.empty())
  {
    pair<ll, int> p = q.top();
    q.pop();
    int v = p.second;
    ll d = -p.first;
    if(d > dist[v])
      continue;
    for(int i = 0; i < graf[v].size(); i++)
    {
      if(d+delky[v][i] < dist[graf[v][i]])
      {
        dist[graf[v][i]] = d+delky[v][i];
        from[graf[v][i]] = v;
        q.push({-d-delky[v][i], graf[v][i]});
      }
    }
  }
  if(dist[1] == inf)
    cout<<-1<<endl;
  else
  {
    int v = 1;
    while(v)
    {
      cout<<v<<" ";
      v = from[v];
    }
    cout<<endl;
  }
  return 0;
}