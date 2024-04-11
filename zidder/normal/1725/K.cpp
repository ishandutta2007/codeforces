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

const int N = 800005;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());

int n;
int a[N];

map <int, int> mp;

int parent[N], sz[N], val[N];
int ind[N];

int findher(int v) {
  if (v == parent[v]) return v;
  return parent[v] = findher(parent[v]);
}

void merge(int a, int b) {
  a = findher(a);
  b = findher(b);
  if (a == b) return;
  if (sz[a] > sz[b]) swap(a, b);
  parent[a] = b;
  sz[b] += sz[a];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    ind[i] = i;
    parent[i] = i;
    sz[i] = 1;
    val[i] = a[i];
  }

  for (int i = 1; i <= n; i++) {
    if (mp.find(a[i]) == mp.end()) {
      mp[a[i]] = i;
    } else {
      merge(mp[a[i]], i);
      mp[a[i]] = findher(i);
    }
  }

  int timer = n;

  int q;
  cin >> q;
  while (q--) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int id, new_val;
      cin >> id >> new_val;

      int new_vertex = ++timer;
      ind[id] = new_vertex;
      sz[new_vertex] = 1;
      parent[new_vertex] = new_vertex;
      val[new_vertex] = new_val;
      if (mp.find(new_val) == mp.end()) {
        mp[new_val] = new_vertex;
      } else {
        merge(mp[new_val], new_vertex);
        mp[new_val] = findher(new_vertex);
      }
    } else if (tp == 2) {
      int id;
      cin >> id;
      cout << val[findher(ind[id])] << endl;
    } else {
      int l, r;
      cin >> l >> r;

      int mid = (l + r) / 2;

      auto it = mp.lower_bound(l);
      while (it != mp.end() && it -> first <= mid) {
        if (mp.find(l - 1) == mp.end()) {
          mp[l - 1] = it -> second;
          val[it -> second] = l - 1;
        } else {
          merge(mp[l - 1], it -> second);
          mp[l - 1] = findher(it -> second);
          val[mp[l - 1]] = l - 1;
        }
        ++it;
      }

      while (it != mp.end() && it -> first <= r) {
        if (mp.find(r + 1) == mp.end()) {
          mp[r + 1] = it -> second;
          val[it -> second] = r + 1;
        } else {
          merge(mp[r + 1], it -> second);
          mp[r + 1] = findher(it -> second);
          val[mp[r + 1]] = r + 1;
        }
        ++it;
      }

      // deleting vertices
      while (true) {
        auto it = mp.lower_bound(l);
        if (it == mp.end() || it -> first > r) break;
        mp.erase(it);
      }
    }
  }
  return 0;
}