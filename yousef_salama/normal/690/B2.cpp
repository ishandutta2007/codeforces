#include <bits/stdc++.h>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 1000000000
#define EPS 1e-8
#define LL long long
#define mod 1000003
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))
#define bits(a) __builtin_popcount(a)

using namespace std;

char s[555][555];
int n;

bool check(int x, int y)
{
  if(x < 0 || y < 0 || x >= n || y >= n) return true;
  return (s[x][y] == '0');
}

bool check_1(int x, int y)
{
  return check(x - 1, y - 1) && check(x - 1, y) && check(x, y - 1);
}

bool check_2(int x, int y)
{
  return check(x - 1, y + 1) && check(x - 1, y) && check(x, y + 1);
}

bool check_3(int x, int y)
{
  return check(x + 1, y + 1) && check(x + 1, y) && check(x, y + 1);
}

bool check_4(int x, int y)
{
  return check(x + 1, y - 1) && check(x + 1, y) && check(x, y - 1);
}

bool three_points_collinear(const pair<int, int> &a, const pair<int, int> &b, const pair<int, int> &c)
{
  return (a.s - b.s) * (a.f - c.f) == (a.s - c.s) * (a.f - b.f);
}

int crosss(const pair<int, int> &O, const pair<int, int> &A, const pair<int, int> &B)
{
  return (A.f - O.f) * (B.s - O.s) - (A.s - O.s) * (B.f - O.f);
}

vector<pair<int, int> > convex_hull(vector<pair<int, int> > &P)
{
  int n = P.size(), k = 0;
  vector<pair<int, int> > H(2*n);
  for(int i=0;i<n;i++)
  {
    while(k >= 2 && crosss(H[k-2], H[k-1], P[i]) <= 0)
      k--;
    H[k++] = P[i];
  }
  for(int i=n-2,t=k+1;i>=0;i--)
  {
    while(k >= t && crosss(H[k-2], H[k-1], P[i]) <= 0)
      k--;
    H[k++] = P[i];
  }
  H.resize(k);
  return H;
}

int main()
{
  while(1)
  {
    scanf("%d", &n);
    if(n == 0) break;
    for(int i=n-1;i>=0;i--)
      scanf("%s", s[i]);
    vector<pair<int, int> > v;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(s[i][j] != '1') continue;
        int c = 0;
        if(check_1(i, j))
          v.pb(mp(i + 1, j + 1)), c++;
        if(check_2(i, j))
          v.pb(mp(i + 1, j)), c++;
        if(check_3(i, j))
          v.pb(mp(i, j)), c++;
        if(check_4(i, j))
          v.pb(mp(i, j + 1)), c++;
        assert(c <= 1);
      }
    }
    for(int i=0;i<v.size();i++)
      swap(v[i].f, v[i].s);
    sort(v.begin(), v.end());
    vector<pair<int, int> > tmp = v;
    v.clear();
    for(int i=0;i<tmp.size();i++)
    {
      if(i && tmp[i] == tmp[i - 1]) continue;
      v.pb(tmp[i]);
    }
    bool bad = true;
    for(int i=0;i+2<v.size() && bad;i++)
      if(!three_points_collinear(v[i], v[i + 1], v[i + 2]))
        bad = false;
    if(bad)
    {
      if(v.empty())
        printf("0\n");
      else if(v[0] != v.back())
      {
        printf("2\n");
        printf("%d %d\n", v[0].f, v[0].s);
        printf("%d %d\n", v.back().f, v.back().s);
      }
      else
      {
        printf("1\n");
        printf("%d %d\n", v[0].f, v[0].s);
      }
      continue;
    }
    v = convex_hull(v);
    assert(v.size() > 3);
    reverse(v.begin(), v.end());
    v.pop_back();
    printf("%d\n", v.size());
    for(int i=0;i<v.size();i++)
      printf("%d %d\n", v[i].f, v[i].s);
  }
  return 0;
}