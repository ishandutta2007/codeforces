#include<iostream>
#include<queue>

using namespace std;

int n;

int a[12][12];
int x[123], y[123];
int bishop[123], knight[123], rook[123];
int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};
int position[12][12][3];

int abs(int u)
{
  if(u < 0)
    return -u;
  return u;
}

struct state
{
  int piece, x1, y1, dist, cost;
};

queue<state> q;

int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      cin>>a[i][j];
      x[a[i][j]] = j;
      y[a[i][j]] = i;
    }
  }
  knight[1] = rook[1] = bishop[1] = 0;
  for(int l = 2; l <= n*n; l++)
  {
    q.push({0, x[l-1], y[l-1], 0, rook[l-1]});
    q.push({1, x[l-1], y[l-1], 0, bishop[l-1]});
    q.push({2, x[l-1], y[l-1], 0, knight[l-1]});
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
        position[i][j][0] = position[i][j][1] = position[i][j][2] = 1e7;
    }
    while(!q.empty())
    {
      state c = q.front();
      q.pop();
      position[c.x1][c.y1][c.piece] = min(c.cost, position[c.x1][c.y1][c.piece]);
      if(c.dist == 3)
        continue;
      if(c.piece == 0)
      {
        q.push({1, c.x1, c.y1, c.dist+1, c.cost+10001});
        q.push({2, c.x1, c.y1, c.dist+1, c.cost+10001});
        for(int i = 0; i < n; i++)
        {
          q.push({0, i, c.y1, c.dist+1, c.cost+10000});
          q.push({0, c.x1, i, c.dist+1, c.cost+10000});
        }
      }
      if(c.piece == 1)
      {
        q.push({0, c.x1, c.y1, c.dist+1, c.cost+10001});
        q.push({2, c.x1, c.y1, c.dist+1, c.cost+10001});
        for(int i = 0; i < n; i++)
        {
          if(c.x1-i >= 0 && c.y1-i >= 0)
            q.push({1, c.x1-i, c.y1-i, c.dist+1, c.cost+10000});
          if(c.x1-i >= 0 && c.y1+i < n)
            q.push({1, c.x1-i, c.y1+i, c.dist+1, c.cost+10000});
          if(c.x1+i < n && c.y1-i >= 0)
            q.push({1, c.x1+i, c.y1-i, c.dist+1, c.cost+10000});
          if(c.x1+i < n && c.y1+i < n)
            q.push({1, c.x1+i, c.y1+i, c.dist+1, c.cost+10000});
        }
      }
      if(c.piece == 2)
      {
        q.push({0, c.x1, c.y1, c.dist+1, c.cost+10001});
        q.push({1, c.x1, c.y1, c.dist+1, c.cost+10001});
        for(int i = 0; i < 8; i++)
        {
          if(c.x1+dx[i] >= 0 && c.y1+dy[i] >= 0 && c.x1+dx[i] < n && c.y1+dy[i] < n)
            q.push({2, c.x1+dx[i], c.y1+dy[i], c.dist+1, c.cost+10000});
        }
      }
    }
    rook[l] = position[x[l]][y[l]][0];
    bishop[l] = position[x[l]][y[l]][1];
    knight[l] = position[x[l]][y[l]][2];
    // cout<<rook[l]<<" "<<bishop[l]<<" "<<knight[l]<<endl;
  }
  if(rook[n*n] <= bishop[n*n] && rook[n*n] <= knight[n*n])
    cout<<rook[n*n]/10000<<" "<<rook[n*n]%10000<<endl;
  else if(bishop[n*n] <= knight[n*n])
    cout<<bishop[n*n]/10000<<" "<<bishop[n*n]%10000<<endl;
  else
    cout<<knight[n*n]/10000<<" "<<knight[n*n]%10000<<endl;
  return 0;
}