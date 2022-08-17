#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
using namespace std;

const int N = 505;

int A[N][N];
int n, m;

void check_complete() {
    if (m != n * (n - 1) / 2) {
        return;
    }
    puts("Yes");
    for (int i = 0; i < n; i++)
        printf("a");
    puts("");
    exit(0);
}



int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        A[i][i] = 1;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        A[a][b] = A[b][a] = true;
    }
    check_complete();
    int u = -1, v = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!A[i][j]) {
                u = i, v = j;
            }
        }
    }
    assert(u != -1);
    vector<int> pA, pB, pC;
    pA.push_back(u);
    pC.push_back(v);
    bool bad = false;
    for (int i = 0; i < n; i++) {
        if (i == u || i == v)
            continue;
        int num = 0;
        if (!A[u][i])
            pC.push_back(i), num++;
        if (!A[v][i])
            pA.push_back(i), num++;
        if (num == 2)
            bad = true;
        if (num == 0)
            pB.push_back(i);
    }
    vector<int> pos[3] = {pA, pB, pC};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int pi : pos[i]) {
                for (int pj : pos[j]) {
                    if (A[pi][pj] != (abs(i - j) <= 1))
                        bad = true;
                }
            }
        }
    }
    if (bad) {
        puts("No");
    } else {
        puts("Yes");
        string res(n, '#');
        for (int x : pA)
            res[x] = 'a';
        for (int y : pB)
            res[y] = 'b';
        for (int z : pC)
            res[z] = 'c';
        puts(res.data());
    }
}