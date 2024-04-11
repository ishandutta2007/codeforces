#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();

const int maxn = 5005;

template<typename T>
void add(T f, int i, int j, int x) {
    if (i < 0 || j < 0) return;
    const static int M = sizeof(f[0]) / sizeof(int);
//    cout << M << endl;
    int _j = j;
    for (; i < maxn; i |= i+1) {
        for (j = _j; j < M; j |= j+1) {
            f[i][j] += x;
        }
    }
}

template<typename T>
int get(T f, int i, int j) {
    if (i < 0 || j < 0) return 0;
    int s = 0;
    int _j = j;
    for (; i >= 0; i = (i&(i+1))-1) {
        for (j = _j; j >= 0; j = (j&(j+1))-1) {
            s += f[i][j];
        }
    }
    return s;
}

int n, q;
int f1[maxn][maxn];
int fp[maxn][maxn*2];
int fm[maxn][maxn*2];

void add_tr(int d, int x, int y, int len)
{
    if (len == 0) {
        add(f1, x, y, 1);
        add(f1, x+1, y, -1);
        add(f1, x, y+1, -1);
        add(f1, x+1, y+1, 1);
        return;
    }
    ++len;
    if (d == 1) {
        add(f1, x, y, 1);
        add(f1, x+len, y, -1);
        add(fp, x, x+y+len, -1);
        add(fp, x+len, x+y+len, 1);
    } else if (d == 2) {
        add(f1, x, y+1, -1);
        add(f1, x+len, y+1, 1);
        add(fm, x, (y-len+1)-x+maxn, 1);
        add(fm, x+len, (y+1)-(x+len)+maxn, -1);
    } else if (d == 4) {
        add(f1, x-len+1, y+1, -1);
        add(f1, x+1, y+1, 1);
        add(fp, x-len+1, x-len+y+1, 1);
        add(fp, x+1, x+y-len+1, -1);
    } else if (d == 3) {
        add(f1, x-len+1, y, 1);
        add(f1, x+1, y, -1);
        add(fm, x+1, y+len-x+maxn, 1);
        add(fm, x-len+1, y+1-x+len-1+maxn, -1);

    }
}

int get(int x, int y) {
    return get(f1, x, y) + get(fp, x, x+y) + get(fm, x, y-x+maxn);
}

int solve()
{
    scanf("%d%d", &n, &q);
    forn(II, q) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int dir, x, y, len;
            scanf("%d%d%d%d", &dir, &x, &y, &len);
            add_tr(dir, x-1, y-1, len);
        } else {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%d\n", get(x-1, y-1));
        }
        if(0)
        forn(i, n) {
            forn(j, n) cout << get(i, j);
            cout << endl;
        }
    }
    return 0;
}


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("i.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}