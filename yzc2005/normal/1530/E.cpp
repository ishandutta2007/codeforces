#include <bits/stdc++.h>
const int N = 1e5 + 5;
int t, n, cnt[30];
char s[N];
void solve() {
  scanf("%s", s + 1), n = strlen(s + 1);
  if (std::count(s + 1, s + n + 1, s[1]) == n) printf("%s\n", s + 1);
  else {
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; ++i) ++cnt[s[i] - 'a'];
    std::vector<int> p;
    for (int i = 0; i < 26; ++i) 
      if (cnt[i]) p.emplace_back(i);
    std::sort(p.begin(), p.end());
    int pos = -1;
    for (auto x : p) {
      if (cnt[x] > 1) continue;
      pos = x; break;
    }
    if (pos != -1) {
      std::string s;
      s += char('a' + pos), --cnt[pos];
      for (auto x : p) while (cnt[x]--) s += char('a' + x);
      std::cout << s << "\n";
    } else {
      std::string s;
      int x = p[0], y = p[1];
      int required = (n - 1) / 2;
      if (n - cnt[x] >= required) {
        std::multiset<char> tmp;
        s += char('a' + x);
        s += char('a' + x);
        cnt[x] -= 2;
        for (int i = 1; i < p.size(); ++i) 
          while (cnt[p[i]]--) tmp.insert('a' + p[i]);
        auto push = [&]() {
          char cur = *tmp.begin();
          tmp.erase(tmp.find(cur));
          s += cur;
        };
        while (cnt[x]--) push(), s += char('a' + x);
        while (!tmp.empty()) push();
      } else {
        if (p.size() == 2) {
          s += char('a' + x), --cnt[x];
          while (cnt[y]--) s += char('a' + y);
          while (cnt[x]--) s += char('a' + x);
        } else {
          int z = p[2];
          s += char('a' + x), --cnt[x];
          s += char('a' + y), --cnt[y];
          while (cnt[x]--) s += char('a' + x);
          s += char('a' + z), --cnt[z];
          for (auto x : p) if (~cnt[x])
            while (cnt[x]--) s += char('a' + x);
        }
      }      
      std::cout << s << "\n";
    }
  }
}
int main() {
  scanf("%d", &t); while (t--) solve();
  return 0;
}