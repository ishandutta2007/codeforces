#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

bool is_prime(int x) { if (x <= 1) return false; for (int i = 2; i*i <= x; ++i) if (x%i == 0) return false; return true; }

int main(void)
{
  for (int n; scanf("%d", &n) == 1; ) {
    int limit = 2 * n * n;
    int p = 1;

    vector<int> primes;
    deque<pair<int, int> > V;
    vector<int> take;

    while (true) {
      for (++p; !is_prime(p); ++p);
      primes.push_back(p);

      V.clear();
      function<void (int, int)> f = [&f, &V, limit, primes](int x, int p_ind) {
        if (x > limit) return;
        if (p_ind == (int)primes.size()) {
          V.push_back(make_pair(x, 0));
          return;
        }
        f(x, p_ind+1);
        f(x * primes[p_ind], p_ind);
      };
      f(1, 0);

      vector<int> need(primes.size(), (n+1) / 2);

      auto reeval = [&primes, &V, &need]() {
        for (pair<int, int>& par : V) {
          par.second = 0;
          REP(p_it, (int)primes.size()) {
            if (need[p_it] == 0) continue;
            par.second += (par.first % primes[p_it] == 0);
          }
        }
        sort(V.begin(), V.end(), [](const pair<int, int> &a, const pair<int, int>& b) -> bool {
            return a.second > b.second;
          });
      };

      reeval();
      take.clear();

      while ((int)take.size() < n && !V.empty()) {
        int f = V[0].first;
        take.push_back(f);

        V.pop_front();

        bool recalc = false;
        REP(p_it, (int)primes.size()) {
          if (need[p_it] == 0) continue;
          if (f % primes[p_it] == 0) {
            --need[p_it];
            if (need[p_it] == 0) recalc = true;
          }
        }
        if (recalc) reeval();
      }

      if ((int)take.size() == n) break;
    }

    sort(take.begin(), take.end());
    REP(i, (int)take.size()) printf("%d%c", take[i], i+1 == n ? '\n' : ' ');
  }
  return 0;
}