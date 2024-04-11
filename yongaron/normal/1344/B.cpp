#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, m;

char a[1234][1234];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void dfs(int x, int y)
{
  int xx, yy;
  a[x][y] = 0;
  for(int i = 0; i < 4; i++)
  {
    xx = x+dx[i];
    yy = y+dy[i];
    if(xx > -1 && xx < n && yy > -1 && yy < m)
      if(a[xx][yy] == '#')
        dfs(xx, yy);
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin>>a[i][j];
  bool broken = false;
  bool el = false, ec = false;
  int last;
  for(int i = 0; i < n; i++)
  {
    last = -1;
    for(int j = 0; j < m; j++)
    {
      if(a[i][j] == '#')
      {
        if(last > -1 && last != j-1)
          broken = true;
        last = j;
      }
    }
    if(last == -1)
      el = true;
  }
  for(int j = 0; j < m; j++)
  {
    last = -1;
    for(int i = 0; i < n; i++)
    {
      if(a[i][j] == '#')
      {
        if(last > -1 && last != i-1)
          broken = true;
        last = i;
      }
    }
    if(last == -1)
      ec = true;
  }
  if(ec != el)
    broken = true;
  if(broken)
  {
    cout<<-1<<endl;
    return 0;
  }
  int ans = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      if(a[i][j] == '#')
      {
        ans++;
        dfs(i, j);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}