#include <memory.h>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <tuple>
using namespace std;

const int N = 205;

char buf[N];

bool used[N][N][N];

tuple<int, int, int> Q[N * N * N];

int main() {
    int n;
    scanf("%d %s", &n, buf);
    int ia = 0, ib = 0, ic = 0;
    for (int i = 0; i < n; i++) {
        if (buf[i] == 'R')
            ia++;
        if (buf[i] == 'G')
            ib++;
        if (buf[i] == 'B')
            ic++;
    }
    int lpt = 0, rpt = 0;
    Q[rpt++] = make_tuple(ia, ib, ic);
    used[ia][ib][ic] = true;
    bool was[3] = {false, false, false};
    while (lpt != rpt) {
        int a, b, c;
        tie(a, b, c) = Q[lpt++];
        int cnt[] = {a, b, c};
        assert(a + b + c >= 1 && a >= 0 && b >= 0 && c >= 0);
        if (a + b + c == 1) {
            if (a == 1)
                was[0] = true;
            else if (b == 1)
                was[1] = true;
            else if (c == 1)
                was[2] = true;
            else
                assert(false); 
        }
        for (int i = 0; i < 3; i++) {
            int ni = (i + 1) % 3;
            int nni = (i + 2) % 3;
            if (cnt[i] != 0 && cnt[ni] != 0) {
                int ncnt[3];
                memcpy(ncnt, cnt, sizeof(cnt));
                ncnt[i]--;
                ncnt[ni]--;
                ncnt[nni]++;
                int na = ncnt[0], nb = ncnt[1], nc = ncnt[2];
                if (!used[na][nb][nc]) {
                    used[na][nb][nc] = true;
                    Q[rpt++] = make_tuple(na, nb, nc);
                }
            }
            if (cnt[i] >= 2) {
                int ncnt[3];
                memcpy(ncnt, cnt, sizeof(cnt));
                ncnt[i]--;
                int na = ncnt[0], nb = ncnt[1], nc = ncnt[2];
                if (!used[na][nb][nc]) {
                    used[na][nb][nc] = true;
                    Q[rpt++] = make_tuple(na, nb, nc);
                }
            }
        }
    }
    char let[] = "RGB";
    char res[4] = {0, 0, 0, 0};
    int respt = 0;
    for (int i = 0; i < 3; i++) {
        if (was[i])
            res[respt++] = let[i];
    }
    sort(res, res + respt);
    printf("%s\n", res);
}