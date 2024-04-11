#include <cstdio>
#include <algorithm>
#include <set>
#include <cassert>
#include <vector>
using namespace std;

const int N = 3050;

int F[N][N];
char buf[N];
vector<int> row[N];

short S[N][N];

inline short get(int y1, int x1, int y2, int x2) {
    return S[y2][x2] + S[y1][x1] - S[y2][x1] - S[y1][x2];
}

int A[N];

int n, m, k;

short to_L[N], to_R[N];
short path[N];
int pt = 0;
inline short getL(short x) {
    if (x == -1)
        return -1;
    if (to_L[x] == -1 || A[to_L[x]])
        return to_L[x];
    pt = 0;
    path[pt++] = x;
    while (true) {
        x = to_L[x];
        if (x == -1 || A[x] != 0) 
            break;
        else
            path[pt++] = x;
    }
    for (int i = 0; i < pt - 1; i++)
        to_L[path[i]] = x;
    return x;
}

short getR(short x) {
    if (x == m)
        return m;
    if (to_R[x] == m || A[to_R[x]])
        return to_R[x];
    pt = 0;
    path[pt++] = x;
    while (true) {
        x = to_R[x];
        if (x == m || A[x] != 0) 
            break;
        else
            path[pt++] = x;
    }
    for (int i = 0; i < pt - 1; i++)
        to_R[path[i]] = x;
    return x;
}
vector <short> visited;

short Rpos[N];

int used[N];
int curver = 0;

vector<short> interesting;

void calcLpos(short x) {
    visited.clear();
    short cur = 0;
    while (true) {
        if (x == -1)
            return;
        if (used[x] == curver)
            return;
        used[x] = curver;
        visited.push_back(x);
        
        cur += A[x];
        if (cur >= k) {
            x = getL(x);
            if (x != -1 && used[x] != curver)
                visited.push_back(x), used[x] = curver;
            return;
        }
        x = getL(x);
    }
    assert(false);
}

typedef long long llong;

llong start(short r) {
    for (short j = 0; j < m; j++) {
        A[j] = get(r, j, n, j + 1);
    }
    short lst = m;
    for (short j = m - 1; j >= 0; j--) {
        to_R[j] = lst;
        if (A[j])
            lst = j;
    }
    lst = -1;
    for (short j = 0; j < m; j++) {
        to_L[j] = lst;
        if (A[j])
            lst = j;
    }
    lst = -1;
    for (short j = 0; j < m; j++) {
        if (A[j]) {
            Rpos[j] = max(j, lst);
            while (true) {
                short nrpos = getR(Rpos[j]);
                if (Rpos[j] == m || get(r, j, n, Rpos[j] + 1) >= k) {
                    break;
                } else {
                    Rpos[j] = nrpos;
                }
            }
            lst = Rpos[j];
        }
    }
    int curval = 0;
    for (short j = 0; j < m; j++) {
        if (A[j]) {
            short pj = getL(j);
            short from = Rpos[j];
            curval += (int)(j - pj) * (m - from);
        }
    }
    llong ans = 0;
    ans += curval;
    for (int i = n - 1; i > r; i--) {
        interesting.clear();
        ++curver;
        for (short x : row[i]) {
            calcLpos(x);
            interesting.insert(interesting.end(), visited.rbegin(), visited.rend());
            short r = getR(x);
            if (r != m && used[r] != curver) {
                used[r] = curver;
                interesting.push_back(r);
            }
        }
        for (short j : interesting) {
            short pj = getL(j);
            short from = Rpos[j];
            curval -= (int)(j - pj) * (m - from);
        }
        for (short x : row[i]) {
            A[x]--;
        }
        short lst = -1;
        for (short j : interesting) {   
            if (!A[j])
                continue;
            short pj = getL(j);
            Rpos[j] = max(Rpos[j], lst);
            while (true) {
                short nrpos = getR(Rpos[j]);
                if (Rpos[j] == m || get(r, j, i, Rpos[j] + 1) >= k) {
                    break;
                } else {
                    Rpos[j] = nrpos;
                }
            }
            lst = Rpos[j];
            short from = Rpos[j];
            curval += (int)(j - pj) * (m - from);
        }
        ans += curval;
    }
    return ans;
}


int main() {
    int tmp;
    scanf("%d %d %d %d ", &n, &m, &tmp, &k);
    for (int i = 0; i < tmp; i++) {
        int y, x;
        scanf("%d %d", &y, &x);
        --y, --x;
        F[y][x] = 1;
        row[y].push_back(x);
    }
    for (int i = 0; i < n; i++){
        sort(row[i].begin(), row[i].end());
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            S[i + 1][j + 1] = S[i + 1][j] + S[i][j + 1] - S[i][j] + F[i][j];
        }
    }
    llong ans = 0;
    llong last = start(n - 1);
    ans = last;
    for (int i = n - 2; i >= 0; i--) {
        if (i % 10 == 0) {
            //fprintf(stderr, "%d\n", i);
        }
        if (row[i].empty())
            ans += last;
        else {
            ans += (last = start(i));
        }
    }
    printf("%lld\n", ans);
}