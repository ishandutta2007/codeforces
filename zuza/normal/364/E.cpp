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

template<typename T> ostream& operator << (ostream& os, const vector<T>& V) { for (const T& t : V) os << t << " "; return os; }
inline int myrand() { return ((rand()&((1<<15)-1)) << 15) ^ (rand()&((1<<15)-1)); }
typedef long long llint;

const int MAXN = 2512;

int R, S;
int K;
char Grid[2][MAXN][MAXN];

int Mid[MAXN];
vector<int> Left[MAXN], Right[MAXN];

template<class T> void merge_it(const vector<int>& A, const vector<int>& B, vector<int>& tmpV, const T& cmpf) {
  int a = 0, b = 0;
  while (a < (int)A.size() && b < (int)B.size()) {
    if (cmpf(A[a], B[b])) tmpV.push_back(A[a++]);
    else tmpV.push_back(B[b++]);
  }
  while (a < (int)A.size()) tmpV.push_back(A[a++]);
  while (b < (int)B.size()) tmpV.push_back(B[b++]);
}

llint solve(int x1, int x2, int y1, int y2, int dir, char grid[][MAXN]) {
  //  printf("x=%d,%d y=%d,%d dir=%d\n", x1, x2, y1, y2, dir);

  if (x1 >= x2 || y1 >= y2) return 0;
  int my = (y1 + y2) / 2;
  llint sol = 0;

  for (int r = x1; r < x2; ++r) {
    Mid[r] = grid[r][my] - '0';
    Left[r].clear();
    Right[r].clear();

    for (int s = my - 1; (int)Left[r].size() != K+1 && s >= y1; --s) {
      if (grid[r][s] == '1') Left[r].push_back(s);
    }

    for (int s = my + 1; (int)Right[r].size() != K+1 && s < y2; ++s) {
      if (grid[r][s] == '1') Right[r].push_back(s);
    }
  }

  for (int r1 = x1; r1 < x2; ++r1) {
    static vector<int> left, right; left.clear(); right.clear();
    int mid = 0;

    for (int r2 = r1; r2 < x2; ++r2) {
      mid += Mid[r2];
      static vector<int> mergeL; mergeL.clear();
      merge_it(left, Left[r2], mergeL, greater<int>()); left.swap(mergeL);
      if ((int)left.size() > K+1) left.resize(K+1);

      static vector<int> mergeR; mergeR.clear();
      merge_it(right, Right[r2], mergeR, less<int>()); right.swap(mergeR);
      if ((int)right.size() > K+1) right.resize(K+1);

      int l_sz = left.size();
      int r_sz = right.size();
      for (int a = 0; a <= K && a <= l_sz; ++a) {
        int b = K - mid - a;
        if (b < 0) break;
        if (b > r_sz) continue;
        int la = (a<l_sz) ? left[a] : y1-1, lb = (a-1>=0) ? left[a-1] : my; // < ]
        int ra = (b-1>=0) ? right[b-1] : my, rb = (b<r_sz) ? right[b] : y2; // [ >
        sol += (lb-la) * (rb-ra);
      }
    }
  }

  sol += solve(y1, my, x1, x2, dir^1, Grid[dir^1]);
  sol += solve(my+1, y2, x1, x2, dir^1, Grid[dir^1]);
  return sol;
}

int main(void)
{
  scanf("%d %d", &R, &S);
  scanf("%d", &K);
  REP(r, R) scanf("%s", Grid[0][r]);
  REP(r, R) REP(s, S) Grid[1][s][r] = Grid[0][r][s];

  //  R = S = 2500; K = 6;
  //  REP(r, R) REP(s, S) Grid[1][s][r] = Grid[0][r][s] = (rand() % 1000 < 650) ? '1' : '0';

  cout << solve(0, R, 0, S, 0, Grid[0]) << endl;
  return 0;
}