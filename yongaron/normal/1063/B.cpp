#include<iostream>
#include<queue>

using namespace std;

struct state
{
  int x, y, l, r;
};

int m, n, r, c, rr, ll;
char lab[2345][2345];
bool was[2345][2345];

queue<state> q1, q2;

int main(int argc, char const *argv[]) {
  cin>>n>>m>>r>>c>>ll>>rr;
  r--;
  c--;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin>>lab[i][j];
  q1.push({r, c, ll, rr});
  was[r][c] = true;
  while(!q1.empty() || !q2.empty())
  {
    if(q1.empty())
      swap(q1, q2);
    state cur = q1.front();
    q1.pop();
    if(cur.x > 0 && !was[cur.x-1][cur.y] && lab[cur.x-1][cur.y] == '.')
    {
      was[cur.x-1][cur.y] = true;
      q1.push({cur.x-1, cur.y, cur.l, cur.r});
    }
    if(cur.x < n-1 && !was[cur.x+1][cur.y] && lab[cur.x+1][cur.y] == '.')
    {
      was[cur.x+1][cur.y] = true;
      q1.push({cur.x+1, cur.y, cur.l, cur.r});
    }
    if(cur.l > 0 && cur.y > 0 && !was[cur.x][cur.y-1] && lab[cur.x][cur.y-1] == '.')
    {
      was[cur.x][cur.y-1] = true;
      q2.push({cur.x, cur.y-1, cur.l-1, cur.r});
    }
    if(cur.r > 0 && cur.y < m-1 && !was[cur.x][cur.y+1] && lab[cur.x][cur.y+1] == '.')
    {
      was[cur.x][cur.y+1] = true;
      q2.push({cur.x, cur.y+1, cur.l, cur.r-1});
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(was[i][j])
        ans++;
  /*for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
      cout<<was[i][j];
    cout<<endl;
  }*/
  cout<<ans<<endl;
  return 0;
}