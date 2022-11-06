#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

llint gcd(llint a, llint b) { 
  llint t;
  while (b > 0) {
    t = a%b;
    a = b;
    b = t;
  }
  return a;
}

int main(void)
{
  srand(time(0));

  const int MAXN = 1e6 + 11;
  static llint A[MAXN];

  cin.sync_with_stdio(false);

  int n; 
  cin >> n;

  llint maks = 1;
  REP(i, n) cin >> A[i];
  
  REP(iter, 12) {
    int rnd = ((rand()&((1<<15)-1)) << 15) ^ (rand()&((1<<15)-1));
    int ind = rnd % n;
    llint x = A[ind];
    
    static vector<llint> D; D.clear();
    static vector<int> Cnt; Cnt.clear();

    for (llint d = 1; d*d <= x; ++d) {
      if (x%d == 0) {
        D.push_back(d);
        if (d*d != x) {
          D.push_back(x/d);
        }
      }
    }

    sort(D.begin(), D.end());
    Cnt.clear(); Cnt.resize(D.size(), 0); 

    REP(i, n) ++Cnt[ lower_bound(D.begin(), D.end(), gcd(x, A[i])) - D.begin() ];
    int d_sz = D.size();

    REP(i, d_sz) {
      int suma = 0;

      for (int j = i; j < d_sz; ++j)
        if (D[j] % D[i] == 0)
          suma += Cnt[j];

      if (suma >= (n+1) / 2) {
        maks = max(maks, D[i]);
      }

    }
  }

  cout << maks << endl;
  return 0;
}