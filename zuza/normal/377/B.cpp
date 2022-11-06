#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

int main(void)
{
  const int MAXN = 1e5 + 123;
  static int probD[MAXN];
  static int studA[MAXN];
  static int studP[MAXN];

  int n_stud, n_prob, n_pass; scanf("%d %d %d", &n_stud, &n_prob, &n_pass);
  REP(i, n_prob) scanf("%d", probD+i);
  REP(i, n_stud) scanf("%d", studA+i);
  REP(i, n_stud) scanf("%d", studP+i);

  static int recon[MAXN];

  auto bs_cmpf = [n_prob, n_stud, n_pass](int kol) {
    typedef pair<int, int> PII;
    vector<PII> probs;
    vector<PII> studs;

    REP(i, n_prob) probs.push_back(PII(probD[i], i));
    sort(probs.begin(), probs.end());
    reverse(probs.begin(), probs.end());

    REP(i, n_stud) studs.push_back(PII(studA[i], i));
    sort(studs.begin(), studs.end());
    reverse(studs.begin(), studs.end());    

    auto set_cmpf = [](int a, int b) {
      if (studP[a] != studP[b]) return studP[a] < studP[b];
      return a < b;
    };
    set<int, decltype(set_cmpf)> pq(set_cmpf);

    int cost = 0;
    int stud_ptr = 0;

    for (int prob_ptr = 0; prob_ptr < n_prob; ) {
      while (stud_ptr < n_stud && studs[stud_ptr].first >= probs[prob_ptr].first) {
        pq.insert(studs[stud_ptr].second);
        ++stud_ptr;
      }
      if (pq.empty()) return false;

      // izaberi studenta
      int idx = *pq.begin(); pq.erase(pq.begin());
      cost += studP[idx];
      if (cost > n_pass) return false;

      REP(i, kol) {
        if (prob_ptr == n_prob) break;
        recon[ probs[prob_ptr].second ] = idx;
        ++prob_ptr;
      }
    }

    return true;
  };

  if (!bs_cmpf(n_prob)) {
    puts("NO");
    return 0;
  }
  int l = 0, r = n_prob;
  while (l < r) {
    int mid = (l + r) / 2;
    if (bs_cmpf(mid))
      r = mid;
    else
      l = mid + 1;
  }

  bs_cmpf(l);

  puts("YES");
  REP(i, n_prob) printf("%d%c", recon[i]+1, i+1 == n_prob ? '\n' : ' ');
  
  return 0;
}