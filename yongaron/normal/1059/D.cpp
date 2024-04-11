#include<iostream>
#include<iomanip>
#include<algorithm>
#include<math.h>

using namespace std;

int n;
double x[123456], y[123456];
double inf = 1e15, eps = 1e-6;

bool exists(double p)
{
  double l = -inf, r = inf;
  for(int i = 0; i < n; i++)
  {
    if(p*p-(y[i]-p)*(y[i]-p) < 0)
      return false;
    l = max(l, x[i]-sqrt(p*p-(y[i]-p)*(y[i]-p)));
    r = min(r, x[i]+sqrt(p*p-(y[i]-p)*(y[i]-p)));
  }
  if(r-l > -eps)
    return true;
  return false;
}

int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i = 0; i < n; i++)
    cin>>x[i]>>y[i];
  bool pos = false, neg = false;
  for(int i = 0; i < n; i++)
  {
    if(y[i] < 0)
    {
      neg = true;
      y[i] = -y[i];
    }
    else
     pos = true;
  }
  if(neg && pos)
  {
    cout<<-1<<endl;
    return 0;
  }
  double l = 0, r = inf, m;
  for(int i = 0; i < 100; i++)
  {
    m = (l+r)/2;
    if(exists(m))
      r = m;
    else
      l = m;
  }
  cout<<setprecision(20)<<m<<endl;
  return 0;
}