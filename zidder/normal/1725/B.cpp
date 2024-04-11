///////////////////////////////    _LeMur_
#define _CRT_SECURE_NO_WARNINGS
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <chrono>
#include <random>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <tuple>
#include <queue>
#include <ctime>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

const int N = 100005;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());

int n, d;
int a[N];

bool check(int x) {
  long long all = 0;

  for (int i = n; i >= n - x + 1; i--) {
    all += d / a[i] + 1;
  }

  return all <= n;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> d;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a + 1, a + n + 1);

  int ina = 1, inb = n, answ;
  while (ina <= inb) {
    int mid = (ina + inb) / 2;
    if (check(mid)) {
      answ = mid;
      ina = mid + 1;
    } else {
      inb = mid - 1;
    }
  }
  
  cout << answ << endl;
  return 0;
}