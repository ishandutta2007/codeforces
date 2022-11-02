#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n, m;
vector<int> G[100009];
int sqr;
bool visited[100009];
vector<int> indSet;
int degree[100009];
int nxt[100009];
int reachTime[100009];
int tim;
int start;

void dfs(int x)
{
  tim++;
  reachTime[x]=tim;
  for(int ne: G[x])
  {
    if(visited[ne]) continue;
    if(reachTime[ne]>0)
    {
      if(reachTime[ne]+sqr-1<=reachTime[x])
      {
        cout<<2<<endl;
        cout<<(reachTime[x]-reachTime[ne]+1)<<endl;
        int tmp=ne;
        while(tmp!=x)
        {
          cout<<tmp<<" ";
          tmp=nxt[tmp];
        }
        cout<<x<<endl;
        exit(0);
      }
    }
    else
    {
      nxt[x]=ne;
      return dfs(ne);
    }
  }
}

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m;
  sqr=sqrt(n);
  if(sqr*sqr<n) sqr++;
  for(int i=1; i<=m; i++)
  {
    int a, b;
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
    degree[a]++;
    degree[b]++;
  }
  set<pair<int, int> > Q;
  for(int i=1; i<=n; i++)
  {
    Q.insert({degree[i], i});
  }
  bool indSetFound=false;
  while(1)
  {
    pair<int, int> p=*Q.begin();
    if(p.F>=sqr-1)
    {
      break;
    }
    Q.erase(p);
    indSet.push_back(p.S);
    visited[p.S]=true;
    
    for(int ne: G[p.S])
    {
      if(!visited[ne])
      {
        Q.erase({degree[ne], ne});
        for(int nne: G[ne])
        {
          if(!visited[nne])
          {
            Q.erase({degree[nne], nne});
            degree[nne]--;
            Q.insert({degree[nne], nne});
          }
        }
        visited[ne]=true;        
      }
    }
    degree[p.S]=0;
    if(indSet.size()==sqr)
    {
      indSetFound=true;
      break;
    }
  }
  if(indSetFound)
  {
    cout<<1<<endl;
    for(int v: indSet)
    {
      cout<<v<<" ";
    }
    cout<<endl;
    return 0;
  }
  dfs((*Q.begin()).S);
	return 0;
}