#include<iostream>
#include<string>
#include<vector>

using namespace std;

int n;
string s;

int strom[1234567][2];
char op[1234567];
bool imp[1234567];
bool in[1234567][2];


bool dfs(int v)
{
  if(op[v] == 'I')
    return in[v][0];
  else if(op[v] == 'N')
  {
    in[v][0] = dfs(strom[v][0]);
    return !in[v][0];
  }
  else if(op[v] == 'A')
  {
    in[v][0] = dfs(strom[v][0]);
    in[v][1] = dfs(strom[v][1]);
    return in[v][0]&in[v][1];
  }
  else if(op[v] == 'O')
  {
    in[v][0] = dfs(strom[v][0]);
    in[v][1] = dfs(strom[v][1]);
    return in[v][0]|in[v][1];
  }
  else if(op[v] == 'X')
  {
    in[v][0] = dfs(strom[v][0]);
    in[v][1] = dfs(strom[v][1]);
    return in[v][0]^in[v][1];
  }
}

void dfs2(int v)
{
  imp[v] = 1;
  if(op[v] == 'N')
  {
    dfs2(strom[v][0]);
  }
  else if(op[v] == 'A')
  {
    if(in[v][0] && in[v][1])
    {
      dfs2(strom[v][0]);
      dfs2(strom[v][1]);
    }
    else if(in[v][0] && !in[v][1])
      dfs2(strom[v][1]);
    else if(!in[v][0] && in[v][1])
      dfs2(strom[v][0]);
  }
  else if(op[v] == 'O')
  {
    if(!in[v][0] && !in[v][1])
    {
      dfs2(strom[v][0]);
      dfs2(strom[v][1]);
    }
    else if(in[v][0] && !in[v][1])
      dfs2(strom[v][0]);
    else if(!in[v][0] && in[v][1])
      dfs2(strom[v][1]);
  }
  else if(op[v] == 'X')
  {
    dfs2(strom[v][0]);
    dfs2(strom[v][1]);
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i <= n; i++)
  {
    int a, b;
    cin>>s;
    if(s[0] == 'I')
    {
      cin>>a;
      in[i][0] = a;
      op[i] = 'I';
    }
    else if(s[0] == 'N')
    {
      cin>>a;
      op[i] = 'N';
      strom[i][0] = a;
    }
    else
    {
      cin>>a>>b;
      op[i] = s[0];
      strom[i][0] = a;
      strom[i][1] = b;
    }
  }
  bool ans = dfs(1);
  dfs2(1);
  for(int i = 1; i <= n; i++)
    if(op[i] == 'I')
      cout<<(imp[i]^ans);
  cout<<endl;
  return 0;
}