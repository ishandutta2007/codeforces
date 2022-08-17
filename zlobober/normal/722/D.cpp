#include <cstdio>
#include <memory.h>
#include <cassert>
#include <algorithm>
#include <map>
using namespace std;

const int N = 3 * 1000 * 1000;

int ept[N];
int E[N][2];

int invM[N];
map<int, int> M;

int X[N];

bool leaf[N];

const int inf = 1e9 + 42;

int rem[N];

int ans[N];
int apt;
int cur[N];
int cpt;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
        for (int v = X[i]; v > 0; v >>= 1)
            M[v];
    }
    int pt = 0;
    for (map<int, int>::iterator it = M.begin(); it != M.end(); it++) {
        it->second = pt;
        invM[pt] = it->first;
        pt++;
    }
    for (int i = 0; i < n; i++) {
        for (int v = X[i]; v > 1; v >>= 1) {
            int a = M[v];
            int b = M[v / 2];
            if (find(E[b], E[b] + ept[b], a) != E[b] + ept[b])
                continue;
            assert(ept[b] < 2);
            E[b][ept[b]++] = a;
        }
        leaf[M[X[i]]] = true;
    }
    int l = 0, r = inf;

    while (r - l > 1) {
        int m = (l + r) / 2;
        cpt = 0;
        for (int i = pt - 1; i >= 0; i--) {
            int v = invM[i];
            if (leaf[i]) {
                rem[i] = 1;
            } else {
                rem[i] = 0;
            }
            for (int _j = 0; _j < ept[i]; _j++) {
                int j = E[i][_j];
                rem[i] += rem[j];
            }
            if (v <= m) {
                if (rem[i]) {
                    cur[cpt++] = invM[i];
                    rem[i]--;
                }
            }
        }
        if (rem[M[1]])
            l = m;
        else {
            r = m;
            assert(cpt == n);
            memcpy(ans, cur, sizeof(int) * cpt);
        }
    }
    fprintf(stderr, "ans = %d\n", r);
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");
}