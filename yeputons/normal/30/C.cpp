#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>

#include <ctime>
#include <cassert>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const int N = (int)(2e5);

struct point 
{
  ll x, y, t;
  double p;
  point() {}
  point(ll a, ll b, ll c, double d)
  {
    x = a;
    y = b;
    t = c;
    p = d;
  }
  void read() {scanf("%I64d%I64d%I64d%lf", &x, &y, &t, &p);}
};

int n;
point a[N];
double d[N];

bool Less(point a, point b)
{
  return a.t < b.t;
}

ll dist(point a, point b)
{
  return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
  //freopen("a.in", "r", stdin);
  //freopen("a.out", "w", stdout);

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    a[i].read();                                                
  sort(a, a + n, Less);

  for (int i = 0; i < n; i++)
    d[i] = a[i].p;
  for (int i = 0; i < n; i++)
  {
    d[i] = a[i].p;
    //cout << i << ' ' << d[i] << endl;             
    double mx = 0;
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        continue;
      //cout << (a[j].t - a[i].t >= 0) << endl;
      //cout << ((a[j].t - a[i].t) * (a[j].t - a[i].t) >= dist(a[i], a[j])) << endl;
      //cout << a[i].t << ' ' << dist(a[i], a[j]) << ' '<< (a[j].t - a[i].t) * (a[j].t - a[i].t) << endl;
      if (a[j].t - a[i].t <= 0 && ((a[j].t - a[i].t) * (a[j].t - a[i].t) >= dist(a[i], a[j])))
      {
        mx = max(mx, d[j]);
        //cout << "!" << j << ' ' << d[j] << endl;
      }
    }
    d[i] += mx;
  }
  double ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, d[i]);
  printf("%.10lf\n", ans);

  return 0;
}