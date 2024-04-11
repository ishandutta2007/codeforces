#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 151;
const int BLOCK = 5;
const int N = maxn * maxn;
const int masks = 1 << (2 * BLOCK + 1);

char a[maxn][maxn];
char s[100100];
int n, m;

short f[4][N];
short fp[masks][N];

bool pos[N];
bool tmp[N];

bool bad(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m)
        return true;
    return a[i][j] == '#';
}

map<char, int> cdir = {{'U', 0}, {'L', 1}, {'D', 2}, {'R', 3}};
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int nodes;
short ff[BLOCK + 5][N];
void rec(int mask = 1, int d = 0) {
    memcpy(fp[mask], ff[d], sizeof(ff[d]));
    if (d == BLOCK)
        return;
    forn (q, 4) {
        int nmask = (mask << 2) | q;
        forn (i, nodes)
            ff[d + 1][i] = f[q][ff[d][i]];
        rec(nmask, d + 1);
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int k;
    cin >> n >> m >> k;
    forn (i, n)
        scanf("%s", a[i]);
    scanf("%s", s);
    int cnt = 0;
    int ex = -1;
    forn (i, n)
        forn (j, m) {
            if (a[i][j] == '#')
                continue;
            int u = i * m + j;
            if (a[i][j] == 'E')
                ex = u;
            pos[u] = true;
            ++cnt;
            forn (q, 4) {
                int x = i + dx[q];
                int y = j + dy[q];
                if (bad(x, y))
                    f[q][u] = u;
                else
                    f[q][u] = x * m + y;
            }
        }
    nodes = n * m;
    forn (i, nodes)
        ff[0][i] = i;
    rec();
    int pr = 0;
    int blck = BLOCK;
    while (pr < k && cnt > 1) {
        int mask = 1;
        int j;
        for (j = 0; j < blck && pr + j < k; ++j)
            mask = (mask << 2) | cdir[s[pr + j]];
        memset(tmp, 0, sizeof(tmp));
        int ncnt = 0;
        forn (i, nodes)
            if (pos[i]) {
                int to = fp[mask][i];
                if (!tmp[to]) {
                    tmp[to] = true, ++ncnt;
                }
            }
        if (ncnt == 1 && blck > 1) {
            //cerr << "small step\n";
            blck = 1;
            continue;
        }

        memcpy(pos, tmp, sizeof(tmp));
        cnt = ncnt;
        pr += j;
    }

    if (cnt > 1) {
        cout << -1 << '\n';
        return 0;
    }

    int u = -1;
    forn (i, nodes)
        if (pos[i])
            u = i;
    assert(u != -1);
    while (pr < k && u != ex) {
        u = f[cdir[s[pr]]][u];
        ++pr;
    }

    if (u != ex) {
        cout << -1 << '\n';
        return 0;
    }

    cout << pr << '\n';
}