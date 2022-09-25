#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void predict(string s) {
  vector<string> grumpy = {
    "no way",
    "go die in a hole",
    "worse",
    "terrible",
    "are you serious?",
    "don't even"
  };
  vector<string> normal = {
    "cool",
    "great!",
    "not bad",
    "yes",
    "great",
    "yeah",
    "hell yes",
    "awesome"
  };
  for (auto w : grumpy) {
    if (s.find(w) != string::npos) {
      cout << "grumpy" << endl;
      exit(0);
    }
  }
  for (auto w : normal) {
    if (s.find(w) != string::npos) {
      cout << "normal" << endl;
      exit(0);
    }
  }
}

signed main() {
  const int k = 10;
  for (int i = 0; i < k; ++i) {
    cout << i << endl;
    string s;
    getline(cin, s);
    predict(s);
  }
  return 0;
}