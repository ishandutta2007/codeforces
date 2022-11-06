#include<iostream>
#include<vector>

using namespace std;

int n, m;

char mp[123][123];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char out[] = {'U', 'D', 'L', 'R'};

bool was[123][123];

vector<char> v;

bool dfs(int x, int y)
{
  if(x <= 0 || x > n || y <= 0 || y > m)
    return false;
  if(was[x][y])
    return false;
  if(mp[x][y] == '*')
    return false;
  if(mp[x][y] == 'F')
    return true;
  was[x][y] = true;
  for(int i = 0; i < 4; i++)
  {
    if(dfs(x+dx[i], y+dy[i]))
    {
      v.push_back(out[i]);
      return true;
    }
  }
  return false;
}

int main(int argc, char const *argv[]) {
  cin>>n>>m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin>>mp[i+1][j+1];
  int x, y;
  x = y = 1;
  if(mp[1][1] == 'F')
    return 0;
  if(n > 1 && mp[2][1] == '.')
  {
    cout<<out[1]<<endl;
    cin>>x>>y;
    if(x == 1)
      swap(out[0], out[1]);
    if(mp[x][y] == 'F')
      return 0;
    cout<<out[0]<<endl;
    cin>>x>>y;
    while(m == 1 || mp[x][2] == '*')
    {
      cout<<out[1]<<endl;
      cin>>x>>y;
      if(mp[x][y] == 'F')
        return 0;
    }
    cout<<out[3]<<endl;
    cin>>x>>y;
    if(y == 1)
      swap(out[2], out[3]);
    if(mp[x][y] == 'F')
        return 0;
  }
  else if(m > 1 && mp[1][2] == '.')
  {
    cout<<out[3]<<endl;
    cin>>x>>y;
    if(y == 1)
      swap(out[2], out[3]);
    if(mp[x][y] == 'F')
      return 0;
    cout<<out[2]<<endl;
    cin>>x>>y;
    while(n == 1 || mp[2][y] == '*')
    {
      cout<<out[3]<<endl;
      cin>>x>>y;
      if(mp[x][y] == 'F')
        return 0;
    }
    cout<<out[1]<<endl;
    cin>>x>>y;
    if(x == 1)
      swap(out[0], out[1]);
    if(mp[x][y] == 'F')
        return 0;
  }
  dfs(x, y);
  for(int i = v.size()-1; i >= 0; i--)
  {
    cout<<v[i]<<endl;
    cin>>x>>y;
  }
  return 0;
}