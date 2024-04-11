%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
#define dd double
#define _i int
#define RE register
#define rep(i, l, r) for (RE int i = l; i <= r; i++)
#define req(i, l, r) for (RE int i = l; i >= r; i--)
#define range(i, l, r) rep(i, l, r - 1)
#define Be(s, t) memset(s, t, sizeof(s))
#define poly vector <int>
#define pii pair <int, int>
template <typename T> void read(T &x) { x = 0; int FF = 1; char op = getchar(); while (!isdigit(op)) { if (op == '-') FF = -1; op = getchar(); } while (isdigit(op)) { x = (x << 1) + (x << 3) + op - '0'; op = getchar(); } x *= FF; }
template <typename T> void print(T x) { if (x < 0) { putchar('-'); x = -x; } if (x < 1) return ; print(x / 10); putchar(x % 10 + '0'); }
template <typename T> void print(T x, char _tab) { print(x); putchar(_tab); }

const int maxn = 100005;
int a[maxn], b[maxn];
int l[maxn], r[maxn];
int n;
int q1, q2, cnt1, cnt2;
int x, y;
int pos[1005][1005];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 4 * n + 1; i++) {
    scanf("%d%d", &a[i], &b[i]);
    pos[a[i]][b[i]] = 1;
  }
  
  for (int la = 0; la <= 50; la++) {
    for (int lb = la + 1; lb <= 50; lb++) {
      for (int ra = 0; ra <= 50; ra++) {
        for (int rb = ra + 1; rb <= 50; rb++) {
          int xx, yy, tot = 0;
          for (int i = 1; i <= 4 * n + 1; i++) {
            if (a[i] == la && ra <= b[i] && b[i] <= rb) ;
            else if (a[i] == lb && ra <= b[i] && b[i] <= rb) ;
            else if (b[i] == ra && la <= a[i] && a[i] <= lb) ;
            else if (b[i] == rb && la <= a[i] && a[i] <= lb) ;
            else {
              tot++;
              xx = a[i], yy = b[i];
            }
          }
          
          if (tot == 1) {
            printf("%d %d\n", xx, yy);
            exit(0);
          }
        }
      }
    }
  }
  
  return 0;
}