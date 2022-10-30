#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;

int n, m, k;
vector<int> G[100009];
int parent[100009];
int level[100009];
bool was[100009];

bool visited[100009];

vector<pair<int, int> > edges;

int levCnt[2];

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m>>k;
  for(int i=1; i<=m; i++)
  {
    int a, b;
    cin>>a>>b;
    edges.push_back({a, b});
    G[a].push_back(b);
    G[b].push_back(a);
  }
  queue<int> Q;
  Q.push(1);
  was[1]=true;
  level[1]=0;
  levCnt[0]++;
  while(Q.size()>0)
  {
    int cur=Q.front();
    Q.pop();
    for(int nb: G[cur])
    {
      if(!was[nb])
      {
        parent[nb]=cur;
        level[nb]=level[cur]+1;
        levCnt[level[nb]%2]++;
        was[nb]=true;
        Q.push(nb);
      }
    }
  }
  if(m==n-1)
  {
    cout<<1<<endl;
    int parity=0;
    if(levCnt[1]>levCnt[0]) parity=1;
    int kcnt=0;
    for(int i=1; i<=n; i++)
    {
      if(level[i]%2==parity)
      {
        if(kcnt<(k+1)/2)
        {
          cout<<i<<" ";
          kcnt++;
        }
      }
    }
    cout<<endl;
    return 0;
  }
  int c1=0;
  int c2=0;
  for(pair<int, int> e: edges)
  {
    if(parent[e.F]==e.S || parent[e.S]==e.F) continue;
    c1=e.F;
    c2=e.S;
    break;
  }
  vector<int> v1, v2;
  if(level[c1]>level[c2])
  {
    v1.push_back(c1);
    c1=parent[c1];
  }
  else if(level[c1]<level[c2])
  {
    v2.push_back(c2);
    c2=parent[c2];
  }
  while(c1!=c2)
  {
    v1.push_back(c1);
    c1=parent[c1];
    v2.push_back(c2);
    c2=parent[c2];
  }
  v1.push_back(c1);
  vector<int> cycle;
  for(int i: v1) cycle.push_back(i);
  reverse(v2.begin(), v2.end());
  for(int i: v2) cycle.push_back(i);
  if(cycle.size()<=k)
  {
    cout<<2<<endl;
    cout<<cycle.size()<<endl;
    for(int i: cycle) cout<<i<<" ";
    cout<<endl;
    return 0;
  }
  visited[cycle[0]]=true;
  visited[cycle[1]]=true;
  for(int i=2; i<k; i++)
  {
    int cur=cycle[i];
    for(int nb: G[cur])
    {
      if(visited[nb] && cycle[i-1]!=nb)
      {
        int idx=-1;
        for(int j=0; j<i; j++)
        {
          if(nb==cycle[j])
          {
            idx=j;
            break;
          }
        }
        cout<<2<<endl;
        cout<<i-idx+1<<endl;
        for(int j=idx; j<=i; j++)
        {
          cout<<cycle[j]<<" ";
        }
        cout<<endl;
        return 0;
      }
      visited[cur]=true;
    }
  }
  cout<<1<<endl;
  for(int i=0; i<k; i+=2)
  {
    cout<<cycle[i]<<" ";
  }
  cout<<endl;
	return 0;
}