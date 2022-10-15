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

int n;
long long a[N];

int t[N];

void update(int pos) {
  for (; pos <= n; pos += pos & -pos) {
    t[pos]++;
  }
}

int get(int pos) {
  int answ = 0;
  for (; pos > 0; pos -= pos & -pos) {
    answ += t[pos];
  }
  return answ;
}

int get(int l, int r) {
  return get(r) - get(l - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  vector < pair<long long, int> > mas;

  bool flag = true;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];

    if (i > 1) a[i] += a[i - 1];
    mas.emplace_back(a[i], i);

    if (a[i] < 0) {
      flag = false;
    }
  }

  if (!flag) {
    cout << -1 << endl;
    return 0;
  }

  sort(mas.begin(), mas.end());
  if (mas[n - 1].second != n) {
    cout << -1 << endl;
    return 0;
  }

  long long answ = 0;
  for (int i = 0; i < (int)mas.size(); i++) {
    int id = mas[i].second;
    answ += id - 1 - get(1, id - 1);
    update(id);
  }

  cout << answ << endl;
  return 0;
}