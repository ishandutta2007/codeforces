#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
int n;
string s;
ll ans = 1;

string go(int id, int dep) {
  if (dep == n) {
    string ret = " ";
    ret[0] = s[id];
    return ret;
  }
  string now = " ";
  now[0] = s[id];
  string s1 = go(id * 2, dep + 1);
  string s2 = go(id * 2 + 1, dep + 1);
  // cerr << "id = " << id << " , s1 = " << s1 << " , s2 = " << s2 << endl;
  if (s1 != s2) {
    ans = (ans * 2) % mod;
  }
  return min(s1, s2) + now + max(s1, s2);
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  cin >> s;
  s = " " + s;
  go(1, 1);
  cout << ans << endl;
}