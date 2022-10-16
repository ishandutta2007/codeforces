#include <bits/stdc++.h>
using namespace std;

int count_x[3], count_y[3];
int n, m, k;
const int base = 998244353;
int p2[1000001];
int stage_x[1000001][2];
int stage_y[1000001][2];
int stage[2];
map<pair<int, int>, int> cell;
int common() {
  if (stage[0]) {
    return stage[1] == 0;
  } else {
    if (stage[1])
      return 1;
    return 2;
  }
}
int get_ans() {
  //   cerr << count_x[0] << ' ' << count_x[1] << ' ' << count_x[2] << '\n';
  //   cerr << count_y[0] << ' ' << count_y[1] << ' ' << count_y[2] << '\n';
  //   cerr << stage[0] << ' ' << stage[1] << '\n';

  if (count_x[2]) {
    if (count_y[2])
      return 0;
    return p2[count_y[0]];
  } else {
    if (count_y[2])
      return p2[count_x[0]];
    return ((p2[count_x[0]] + p2[count_y[0]]) % base + base - common()) % base;
  }
}

void change_x(int x, int d) {
  int val = (stage_x[x][0] > 0);
  val += (stage_x[x][1] > 0);
  count_x[val] += d;
}

void change_y(int y, int d) {
  int val = (stage_y[y][0] > 0);
  val += (stage_y[y][1] > 0);
  count_y[val] += d;
}

void solve() {
  cin >> n >> m >> k;
  count_x[0] = n;
  count_y[0] = m;
  for (int i = 1, x, y, t; i <= k; i++) {
    cin >> x >> y >> t;
    if (cell.find({x, y}) == cell.end()) {
      if (t != -1) {
        change_x(x, -1);
        change_y(y, -1);

        stage_x[x][(x + y + t) % 2]++;
        stage_y[y][(x + y + t) % 2]++;
        stage[(x + y + t) % 2]++;
        cell[{x, y}] = t;

        change_x(x, 1);
        change_y(y, 1);
      }
    } else {
      int now = cell[{x, y}];
      if (now != t) {
        change_x(x, -1);
        change_y(y, -1);

        stage_x[x][(x + y + now) % 2]--;
        stage_y[y][(x + y + now) % 2]--;
        stage[(x + y + now) % 2]--;

        if (t != -1) {
          stage_x[x][(x + y + t) % 2]++;
          stage_y[y][(x + y + t) % 2]++;
          stage[(x + y + t) % 2]++;
          cell[{x, y}] = t;
        } else {
          cell.erase({x, y});
        }
        change_x(x, 1);
        change_y(y, 1);
      }
    }
    cout << get_ans() << '\n';
  }
}

int main() {
  p2[0] = 1;
  for (int i = 1; i <= 1000000; i++)
    p2[i] = (p2[i - 1] * 2) % base;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}