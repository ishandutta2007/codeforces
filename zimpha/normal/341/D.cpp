#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long LL;

const int N = 1000 + 10;
int n,m,x1,y1,x2,y2;
LL multree[N][N][2];
LL addtree[N][N][2];

LL query2(LL tree[N][N][2], int x, int y) {
  LL mul = 0, add = 0;
  for (int j = y; j > 0; j -= j&-j) {
    mul ^= tree[x][j][0];
    add ^= tree[x][j][1];
  }

  return (mul * (y%2)) ^ add;
}

LL query1(int x, int y) {
  LL mul = 0, add = 0;

  for (int i = x; i > 0; i -= i&-i) {
    mul ^= query2(multree, i, y);
    add ^= query2(addtree, i, y);
  }

  return (mul * (x%2)) ^ add;
}


LL query(int x1, int x2, int y1, int y2) {
  return query1(x2, y2) ^ query1(x1-1, y2) ^ query1(x2, y1-1) ^ query1(x1-1, y1-1);
}

int ev(int x) { return x%2; }

void update2(LL tree[N][N][2], int x, int y, LL mul, LL add) {
  for (int i = x; i <= n; i += i&-i) {
    for (int j = y; j <= n; j += j&-j) {
      tree[i][j][0] ^= mul;
      tree[i][j][1] ^= add;
    }
  }
}

void update1(int x, int y1, int y2, LL mul, LL add) {
  update2(multree, x, y1, mul, mul * ev(y1 - 1));
  update2(multree, x, y2, mul, mul * ev(y2));

  update2(addtree, x, y1, add, add * ev(y1 - 1));
  update2(addtree, x, y2, add, add * ev(y2));
}

void update(int x1, int x2, int y1, int y2, LL by) {
  update1(x1, y1, y2, by, by * ev(x1 - 1));
  update1(x2, y1, y2, by, by * ev(x2));
}

int main() {
  scanf("%d %d", &n, &m);
  {
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        addtree[i][j][0] = addtree[i][j][1] = 0;
        multree[i][j][0] = multree[i][j][1] = 0;
      }
    }
    for (int i = 0; i < m; ++i) {
      int op;
      scanf("%d", &op);
      if (op == 1) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        LL res = query(x1, x2, y1, y2);
        printf("%lld\n", res);
      } else {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        LL val;
        scanf("%lld", &val);
        update(x1, x2, y1, y2, val);
      }
    }
  }
}