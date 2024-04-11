#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

inline int myrand() { return ((rand()&((1<<15)-1)) << 15) ^ (rand()&((1<<15)-1)); }
typedef long long llint;

char dp[40][1 << 20];
char bio[40][1 << 20];

int n;
char mat[21][21];
vector<char> diag[40];

inline int getVal(int x, char c) {
  if (x&1) {
    if (c == 'b') return +1;
    if (c == 'a') return -1;
    return 0;
  } else {
    if (c == 'a') return +1;
    if (c == 'b') return -1;
    return 0;
  }
}

int solve(int x, int state) {
  if (x == 2*n - 2) {
    assert(state == 1);
    return getVal(x, mat[n-1][n-1]);
  }

  char& ref = dp[x][state];
  char& bio_ref = bio[x][state];

  if (bio_ref) return ref;
  bio_ref = true;
  ref = -50;

  for (char c = 'a'; c <= 'z'; ++c) {
    int new_state = 0;
    int sz_ex = (int)diag[x].size();
    int sz_nov = (int)diag[x+1].size();

    REP(i, sz_ex) {
      if ((state&(1<<i)) == 0) continue;
      if (diag[x][i] != c) continue;

      if (sz_ex < sz_nov) {
        new_state |= 1<<i;
        if (i+1 < sz_nov) new_state |= 1<<(i+1);
      } else {
        if (i < sz_nov) new_state |= 1<<i;
        if (i-1 >= 0) new_state |= 1<<(i-1);
      }
    }

    if (new_state != 0) {
      int val = getVal(x, c) - solve(x+1, new_state);
      if (val >= ref) ref = val;
    }
  }

  return ref;
}

int main(void)
{
  scanf("%d", &n);
  REP(i, n) scanf("%s", mat[i]);
  REP(i, n) REP(j, n) diag[i+j].push_back(mat[i][j]);

  memset(bio, 0, sizeof bio);
  int val = solve(0, 1<<0);
  if (val > 0)
    puts("FIRST");
  else if (val == 0)
    puts("DRAW");
  else
    puts("SECOND");

  return 0;
}