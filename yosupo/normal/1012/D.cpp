#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

template<class T> ostream& operator<<(ostream& os, const deque<T> &v) {
  cout << "[";
  for (auto p: v) cout << p << ", ";
  cout << "]";
  return os;
}

bool single(const string &s) {
  if (count(s.begin(), s.end(), 'a') == 0) return true;
  if (count(s.begin(), s.end(), 'b') == 0) return true;
  return false;
}

deque<int> gr(const string &s) {
  deque<int> q;
  int n = int(s.size());
  int l = 0;
  while (l < n) {
    int r = l;
    while (r < n && s[r] == s[l]) r++;
    q.push_back(r-l);
    l = r;
  }
  q.pop_back();
  return q;
}

using Q = pair<int, int>;


V<Q> solve2(deque<int> q1, deque<int> q2) {
  V<Q> q;
  bool rev = false;
  auto addq = [&](int a, int b) {
    if (rev) swap(a, b);
    q.push_back(Q(a, b));
  };
  while (true) {
    if (q1.size() == 0 && q2.size() == 0) break;
    if (q1.size() == 0) {
      addq(1, q2[0]);
      q1.push_front(q2[0]);
      q2.pop_front();
      q2[0]++;
      continue;
    }
    if (q2.size() == 0) {
      swap(q1, q2);
      rev = !rev;
      continue;
    }
    if (q1.size() == 1 && q2.size() == 1) {
      addq(q1[0], q2[0]);
      q1.pop_front(); q2.pop_front();
      continue;
    }
    if (q1.size() == 1) {
      addq(q1[0], q2[0]+q2[1]+q2[2]);
      int a = q1[0], b = q2[0], c = q2[1];
      q1.pop_front();
      q1.push_back(b); q1.push_back(c);
      q2.pop_front(); q2.pop_front(); q2.pop_front();
      q2[0] += a;
      continue;
    }
    if (q2.size() == 1) {
      swap(q1, q2);
      rev = !rev;
      continue;
    }

    addq(q1[0], q2[0]);
    q1[1] += q2[0];
    q2[1] += q1[0];
    q1.pop_front();
    q2.pop_front();
  }
  return q;
}

V<Q> solve(string s, string t) {
  return solve2(gr(s), gr(t));
}


int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  string s, t;
  cin >> s >> t;
  V<Q> q;
  for (int ph = 0; ph < 4; ph++) {
    string ns, nt;
    if ((ph & 1) == 0) {
      ns += "a";
      nt += "b";
    } else {
      ns += "b";
      nt += "a";
    }
    ns += s; nt += t;
    if ((ph & 2) == 0) {
      ns += "a";
      nt += "b";
    } else {
      ns += "b";
      nt += "a";
    }
    auto nq = solve(ns, nt);
    if (nq.size() == 0) {
      cout << 0 << endl;
      return 0;
    }
    if (q.size() == 0 || nq.size() < q.size()) {
      q = nq;
    }
  }
  cout << q.size() << endl;
  for (auto p: q) {
    cout << p.first - 1 << " " << p.second - 1 << endl;
  }
  return 0;
}