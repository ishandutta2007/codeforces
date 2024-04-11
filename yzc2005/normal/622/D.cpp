#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n;
vector<int> a, b;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for(int i = n - 2; i >= 1; i -= 2) a.emplace_back(i);
  for(int i = n - 1; i >= 1; i -= 2) b.emplace_back(i);
  reverse(a.begin(), a.end());
  for(int x : a) printf("%d ", x);
  printf("%d ", n);
  reverse(a.begin(), a.end());
  for(int x : a) printf("%d ", x);
  reverse(b.begin(), b.end());
  for(int x : b) printf("%d ", x);
  reverse(b.begin(), b.end());
  for(int x : b) printf("%d ", x);
  printf("%d ", n);
  return 0;
}