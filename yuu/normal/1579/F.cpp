#include <bits/stdc++.h>
using namespace std;
int n, d;
int a[1000000];
bool done[1000000];
void solve() {
  cin >> n >> d;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    done[i] = 0;

  int ans = 0;
  for (int i = 0; i < d; i++)
    if (!done[i]) {
      int j = i;
      deque<int> temp;
      while (!done[j]) {
        done[j] = 1;
        temp.push_front(j);
        j = (j + n - d) % n;
      }
      for (auto &&x : temp)
        if (a[x] == 0) {
          while (a[temp.front()]) {
            temp.push_back(temp.front());
            temp.pop_front();
          }
          break;
        }

      if (a[temp.front()] == 0) {
        int last = 0;
        for (int j = 0; j < temp.size(); j++) {
          if (a[temp[j]])
            ans = max(ans, j - last);
          else
            last = j;
        }
      } else {
        cout << "-1\n";
        return;
      }
    }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}