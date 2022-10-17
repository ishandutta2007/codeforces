#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, n, k;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (cin >> T; T; --T) {
    cin >> n >> k;
    srand(time(0));
    auto query = [&](vector<int> a, vector<int> b) {
      cout << "? " << a.size() << " " << b.size() << "\n";
      cout.flush();
      for (auto x : a) {
        cout << x << " "; 
      }
      cout << "\n";
      cout.flush();
      for (auto x : b) {
        cout << x << " ";
      }
      cout << "\n";
      cout.flush();
      string res;
      cin >> res;
      return res;
    };
    bool flag = 0;
    auto answer = [&](int x) {
      cout << "! " << x << "\n";
      cout.flush();
      flag = 1;
    };
    vector<int> a = {1};
    for (int i = 0; i < 30; ++i) {
      vector<int> b = {rand() % (n - 1) + 2};
      if (query(a, b) == "SECOND") {
        answer(1);
        break;
      } 
    }
    if (flag) {
      continue;
    } 
    for (int i = 1; i < n; i *= 2) {
      vector<int> b;
      for (int j = 1; j <= min(i, n - i); ++j) {
        b.push_back(i + j);
      }
      if (i * 2 >= n || query(a, b) == "FIRST") {
        for (int j = b.size(); j > 1; ) {
          auto c = b;
          c.resize(j / 2);
          auto d = a;
          d.resize(j / 2);
          if (query(d, c) == "FIRST") {
            b = c;
            j /= 2;
          } else {
            vector<int> qwq;
            for (int k = j / 2; k < j; ++k) {
              qwq.push_back(b[k]);
            }
            b = qwq;
            j -= j / 2;
          }
        }
        answer(*b.begin());
        break;
      }
      for (auto x : b) {
        a.push_back(x);
      }
      if (flag) {
        break;
      }
    }
  }
  return 0;
}