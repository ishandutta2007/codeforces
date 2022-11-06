#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

map<string, vector<int> > spos;

const int inf = 1e9;
const int BUBEN = 180;

inline void chmin(int& a, int val) { if (val < a) a = val; }

int minDiff(const vector<int>& a, const vector<int>& b) {
  int asz = a.size(), bsz = b.size();
  int ap = 0;
  int ans = inf;
  REP(bp, bsz) {
    while (ap < asz && a[ap] <= b[bp]) {
      chmin(ans, b[bp] - a[ap++]);
    }
  }
  return ans;
}

int Slen;
map< string, map<string, int> > cache;
map< string, vector<int> > ges;
map< string, vector<int> > les;

template<typename T>
ostream& operator << (ostream& os, vector<T>& V) {
  os << "{";
  for (auto& v : V) os << v << ", ";
  return os << "}";
}

int solve(const string& a, const string& b) {
  if (spos[a].size() < spos[b].size()) return solve(b, a);
  if (cache[a].count(b)) return cache[a][b];
  int& ref = cache[a][b];

  if ((int)spos[a].size() >= BUBEN) {
    int ans = inf;

    // b - a
    vector<int>& a_le = les[a];
    if (a_le.empty()) {
      a_le.assign(Slen, -inf);
      for (int pos : spos[a]) a_le[pos] = pos;
      REP(i, Slen) if (i-1 >= 0 && a_le[i] == -inf) a_le[i] = a_le[i-1];
    }    

    // a - b
    vector<int>& a_ge = ges[a];
    if (a_ge.empty()) {
      a_ge.assign(Slen, +inf);
      for (int pos : spos[a]) a_ge[pos] = pos;
      for (int i = Slen-1; i >= 0; --i) if (i+1 < Slen && a_ge[i] == inf) a_ge[i] = a_ge[i+1];
    }

    for (int bpos : spos[b]) {
      chmin(ans, max(a.size(), bpos - a_le[bpos] + b.size()));
      chmin(ans, max(b.size(), a_ge[bpos] - bpos + a.size()));
    }

    return ref = ans;
  } else {
    int ans = inf;
    chmin(ans, max(a.size(), minDiff(spos[a], spos[b]) + b.size()));
    chmin(ans, max(b.size(), minDiff(spos[b], spos[a]) + a.size()));
    return ref = ans;
  }
}

int main(void)
{
  cin.sync_with_stdio(false);

  string S; cin >> S;
  int len = S.size(); Slen = len;
  for (int L = 1; L <= 4; ++L) {
    REP(i, len-L+1) {
      spos[S.substr(i, L)].push_back(i);
    }
  }

  int nq; cin >> nq;
  REP(iq, nq) {
    string a, b; cin >> a >> b;
    int ans = solve(a, b);
    cout << ((ans >= inf) ? -1 : ans) << endl;
  }

  return 0;
}