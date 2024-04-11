#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;

int n, m, k;
vector<int> graf[23456];

struct banned
{
  int a, b, c;
};

bool operator <(const banned &a, const banned &b)
{
  if(a.a == b.a)
  {
    if(a.b == b.b)
      return a.c < b.c;
    return a.b < b.b;
  }
  return a.a < b.a;
}


set<banned> s;

struct found
{
  int a, b, d;
};

found from[3333][3333];
queue<found> q;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin>>n>>m>>k;
  int a, b, c;
  for(int i = 0; i < m; i++)
  {
    cin>>a>>b;
    graf[a].push_back(b);
    graf[b].push_back(a);
  }
  for(int i = 0; i < k; i++)
  {
    cin>>a>>b>>c;
    s.insert({a, b, c});
  }
  for(int i = 0; i < graf[1].size(); i++)
  {
    q.push({1, graf[1][i], 1});
    from[1][graf[1][i]] = {0, 1, 1};
  }
  // cout<<endl;
  while(!q.empty())
  {
    found f = q.front();
    q.pop();
    // cout<<f.a<<" "<<f.b<<" "<<f.d<<endl;
    if(f.b == n)
      break;
    for(int i = 0; i < graf[f.b].size(); i++)
    {
      if(from[f.b][graf[f.b][i]].d == 0 && s.count({f.a, f.b, graf[f.b][i]}) == 0)
      {
        // cout<<"!"<<f.a<<" "<<f.b<<" "<<graf[f.b][i]<<endl;
        q.push({f.b, graf[f.b][i], f.d+1});
        from[f.b][graf[f.b][i]] = {f.a, f.b, f.d+1};
      }
    }
  }
  // cout<<"end"<<endl;
  vector<int> cesta;
  int curr = n;
  cesta.push_back(n);
  int mi, mii;
  int x = 0;
  mi = 1e9;
  for(int i = 0; i <= n; i++)
  {
    if(from[i][curr].d != 0)
    {
      if(from[i][curr].d < mi)
      {
        mi = from[i][curr].d;
        mii = i;
      }
    }
  }
  if(mi > 1e6)
  {
    cout<<-1<<endl;
    return 0;
  }
  int curr2 = mii;
  cesta.push_back(curr2);
  while(curr2 != 1)
  {
    int tmp = curr2;
    curr2 = from[curr2][curr].a;
    curr = tmp;
    cesta.push_back(curr2);
  }

  
  cout<<cesta.size()-1<<endl;
  for(int i = cesta.size()-1; i >= 0; i--)
    cout<<cesta[i]<<" ";
  cout<<endl;
  return 0;
}