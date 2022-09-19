# include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 44;
pair <int, int> in[MN];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i< n; ++i)
    cin >> in[i].first >> in[i].second;
  sort(in, in + n);
  bool is = false;
  for (int i = 0; i < n - 1; i++)
    if (in[i].second > in[i + 1].second)
      is = true;
  if (is)
    cout << "Happy Alex" << endl;
  else
    cout << "Poor Alex" << endl;
}