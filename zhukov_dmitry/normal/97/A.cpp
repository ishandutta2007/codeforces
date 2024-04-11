#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef long long i64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m, ans, k;
char a[32][32];
int u[7][7];
int uu[32][32];
int col[32][32];
int xy[102][4][2];
int aa[32][32];
int b[32][32];
int cnt[7];
int pa[32][32][2];

void rec(int s, int ma)
{
        if (s == k)
        {
                if (!ans)
                {
                        memcpy(aa, b, sizeof(b));
                }
                ans++;
                return;
        }
        
        int tt = min(ma+1, 7) + 1;
        forn(i, tt)
        {
                if (!cnt[i]) continue;
                cnt[i]--;
                
                bool ok = true;
                forn(t, 4)
                {
                        int x = xy[s][t][0];
                        int y = xy[s][t][1];
                        b[x][y] = i;
                        uu[x][y]++;
                }
                forn(t, 4)
                {
                        int x = xy[s][t][0];
                        int y = xy[s][t][1];
                        int xn = pa[x][y][0];
                        int yn = pa[x][y][1];
//                      forn(l, 4)
//                      {
//                              int xn = x + dx[l];
//                              int yn = y + dy[l];
                                if (xn < 0 || xn >= n || yn < 0 || yn >= m) continue;
                                if (uu[xn][yn])
                                {
                                        if (col[xn][yn] == col[x][y] && (x > xn || (x == xn && y > yn))) continue;
                                        if (a[x][y] != a[xn][yn]) continue;
                                        int c1 = b[x][y];
                                        int c2 = b[xn][yn];
                                        if (c1 > c2) swap(c1, c2);
                                        if (u[c1][c2]) ok = false;
                                        u[c1][c2]++;
                                }
//                      }
                }
                
                if (ok) rec(s+1, max(ma, i));
                forn(t, 4)
                {
                        int x = xy[s][t][0];
                        int y = xy[s][t][1];
                        int xn = pa[x][y][0];
                        int yn = pa[x][y][1];
//                      forn(l, 4)
//                      {
//                              int xn = x + dx[l];
//                              int yn = y + dy[l];
                                if (xn < 0 || xn >= n || yn < 0 || yn >= m) continue;
                                if (uu[xn][yn])
                                {
                                        if (col[xn][yn] == col[x][y] && (x > xn || (x == xn && y > yn))) continue;
                                        if (a[x][y] != a[xn][yn]) continue;
                                        int c1 = b[x][y];
                                        int c2 = b[xn][yn];
                                        if (c1 > c2) swap(c1, c2);
                                        u[c1][c2]--;
                                }
//                      }
                }
                
                forn(t, 4)
                {
                        int x = xy[s][t][0];
                        int y = xy[s][t][1];
                        uu[x][y]--;
                }
                
                cnt[i]++;
        }
}

int main()
{
#ifdef ROOM_311
        freopen("input.txt", "rt", stdin);
        time_t et_0 = clock();
#else
#endif
        cout << setiosflags(ios::fixed) << setprecision(10);

        ans = 0;
        scanf("%d%d", &n, &m);
        forn(i, n)
        {
                scanf("%s", a[i]);
        }
        memset(pa, 0xff, sizeof(pa));
        forn(x, n)
        {
                forn(y, m)
                {
                        if (a[x][y] == '.') continue;
                        forn(l, 4)
                        {
                                int xn = x + dx[l];
                                int yn = y + dy[l];
                                if (xn < 0 || xn >= n || yn < 0 || yn >= m) continue;
                                if (a[x][y] != a[xn][yn]) continue;
                                pa[x][y][0] = xn;
                                pa[x][y][1] = yn;
                        }
                }
        }
        clr(u);
        clr(uu);
        forn(i, n)
        {
                forn(j, m)
                {
                        if (a[i][j] != '.' && !uu[i][j])
                        {
                                forn(x, 2)
                                {
                                        forn(y, 2)
                                        {
                                                uu[i+x][j+y] = true;
                                                col[i+x][j+y] = k;
                                                xy[k][x*2+y][0] = i+x;
                                                xy[k][x*2+y][1] = j+y;
                                        }
                                }
                                k++;
                        }
                }
        }
        
        forn(i, 7)
        {
                cnt[i] = 2;
        }
        clr(uu);
        rec(0, -1);
        
        cout << ans * 5040 << endl;
        forn(i, n)
        {
                forn(j, m)
                {
                        if (a[i][j] == '.') putchar('.');
                        else printf("%d", aa[i][j]);
                }
                puts("");
        }

#ifdef ROOM_311
        time_t et_1 = clock();
        fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
        return 0;
}