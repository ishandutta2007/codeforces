#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int SIZE = 1000000 + 10, MAXN = 10000 + 10;

vector<string> word;
char s[MAXN], t[MAXN];
int go[SIZE][26], val[SIZE], rt, sz;
int dp[MAXN], pr[MAXN], n, m;

void ins(char *s, int i) {
  int p = rt;
  for (int o; *s; s++) {
    if (*s >= 'A' && *s <= 'Z') o = *s - 'A';
    else o = *s - 'a';
    if (go[p][o] == 0) go[p][o] = sz++;
    p = go[p][o];
  }
  val[p] = i;
}

void trans(int p, int d, int i) {
  if (d == 0) return;
  int o = s[d] - 'a';
  if (go[p][o]) {
    p = go[p][o];
    if (val[p]) {
      if (dp[d - 1]) dp[i] = 1, pr[i] = val[p];
    }
    trans(p, d - 1, i);
  }
}

void run() {
  rt = 0; sz = 1;
  scanf("%d%s", &n, s + 1);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%s", t);
    word.push_back(t);
    ins(t, i + 1);
  }
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) trans(rt, i, i);
  vector<string> ret;
  assert(dp[n]);
  for (int i = n; i; ) {
    ret.push_back(word[pr[i] - 1]);
    i -= word[pr[i] - 1].size();
  }
  reverse(ret.begin(), ret.end());
  for (auto &s: ret) cout << s << " ";
  cout << endl;
}

int main() {
  run();
  return 0;
}