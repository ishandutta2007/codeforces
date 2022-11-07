#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

const int N = 1e5+5;
const int M = 1e5+5;

long long n, m;

pair<double, int> a[N];

long long fa[N], si[N];

double ans;

bool was[N];

vector<int> graf[N];

int rt(int x)
{
  if(fa[x] != x)
    fa[x] = rt(fa[x]);
  return fa[x];
}

void connect(int x, int y, double d)
{
  x = rt(x);
  y = rt(y);
  if(x == y)
    return;
  if(si[x] < si[y])
    swap(x, y);
  fa[y] = x;
  ans += si[x]*d*si[y];
  si[x] += si[y];
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>n>>m;
  int x, y;
  for(int i = 1; i <= n; i++)
  {
    cin>>a[i].first;
    a[i].second = i;
    fa[i] = i;
    si[i] = 1;
  }
  sort(a+1, a+n+1, [](pair<double, int> x, pair<double, int> y){return x.first > y.first;});
  for(int i = 0; i < m; i++)
  {
    cin>>x>>y;
    graf[x].push_back(y);
    graf[y].push_back(x);
  }
  for(int i = 1; i <= n; i++)
  {
    for(int j = 0; j < graf[a[i].second].size(); j++)
    {
      if(was[graf[a[i].second][j]])
        connect(a[i].second, graf[a[i].second][j], a[i].first);
      was[a[i].second] = true;
    }
  }
  cout<<fixed<<setprecision(6)<<ans/(n*(n-1)/2)<<endl;
  return 0;
}