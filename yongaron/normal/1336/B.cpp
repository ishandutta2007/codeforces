#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t;

int nr, nb, ng;

vector<long long> r, g, b;

long long mi;

void solve()
{
  int ig = 0, ib = 0;
  for(int i = 0; i < r.size(); i++)
  {
    while(ig < g.size()-1 && g[ig+1] <= r[i])
      ig++;
    while(ib < b.size() && b[ib] < r[i])
      ib++;
    if(ig < g.size() && ib < b.size())
      mi = min(mi, (r[i]-g[ig])*(r[i]-g[ig])+(r[i]-b[ib])*(r[i]-b[ib])
            + (b[ib]-g[ig])*(b[ib]-g[ig]));
  }
}


int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>t;
  while(t--)
  {
    mi = 4e18;
    cin>>nr>>ng>>nb;
    long long x;
    r.clear();
    g.clear();
    b.clear();
    for(int i = 0; i < nr; i++)
    {
      cin>>x;
      r.push_back(x);
    }
    for(int i = 0; i < ng; i++)
    {
      cin>>x;
      g.push_back(x);
    }
    for(int i = 0; i < nb; i++)
    {
      cin>>x;
      b.push_back(x);
    }
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    solve();
    swap(g, b);
    solve();
    swap(r, g);
    solve();
    swap(g, b);
    solve();
    swap(r, g);
    solve();
    swap(g, b);
    solve();
    cout<<mi<<endl;
  }
  return 0;
}