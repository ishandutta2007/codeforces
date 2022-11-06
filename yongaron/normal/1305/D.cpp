#include<iostream>
#include<vector>

using namespace std;

int n;

vector<int> graf[1234];
bool edge[1234][1234];

bool done[1234];

int rem;

void dfs(int v, int b, int f)
{
  if(v == b)
    return;
  if(!done[v])
  {
    done[v] = true;
    rem--;
  }
  for(int i = 0; i < graf[v].size(); i++)
    if(graf[v][i] != f)
      dfs(graf[v][i], b, v);
}

int main(int argc, char const *argv[]) {
  cin>>n;
  rem = n;
  int a, b;
  for(int i = 0; i < n-1; i++)
  {
    cin>>a>>b;
    graf[a].push_back(b);
    graf[b].push_back(a);
    edge[a][b] = edge[b][a] = true;
  }
  while(1)
  {
    for(int i = 1; i <= n; i++)
    {
      if(done[i])
        continue;
      for(int j = i+1; j <= n; j++)
      {
        if(done[j])
          continue;
        if(done[i])
          break;
        if(!edge[i][j] || rem == 2)
        {
          cout<<"? "<<i<<" "<<j<<endl;
          cin>>a;
          dfs(i, a, 0);
          dfs(j, a, 0);
          if(rem == 1)
          {
            for(int l = 1; l <= n; l++)
            {
              if(!done[l])
              {
                cout<<"! "<<l<<endl;
                return 0;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}