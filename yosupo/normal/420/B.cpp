#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int MN = 100010;
int back[MN];
int status[MN];
bool flag[MN];
bool type[MN];
int id[MN];
int main() {
    fill_n(back, MN, -1);
    fill_n(status, MN, -1);
    fill_n(flag, MN, true);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        char c; int u;
        scanf(" %c %d", &c, &u); u--;
        type[i] = (c == '+');
        id[i] = u;
    }
    for (int i = 0; i < m; i++) {
        if (status[id[i]] == -1) {
            status[id[i]] = (type[i] ? 0 : 1);
        }
    }
    int c = 0;
    set<int> s;
    for (int i = 0; i < n; i++) {
        if (status[i] == 1) {
            c++;
        }
    }
    if (c) {
        for (int i = 0; i < n; i++) {
            if (status[i] == 0) {
                flag[i] = false;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (status[i] == 0) {
                s.insert(i);
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        int ii = id[i];
        if (type[i]) {
            c++;
            s.erase(ii);
            for (int p: s) {
                flag[p] = false;
            }
            s.clear();
        } else {
            c--;
            if (c) {
                flag[ii] = false;
            }
            if (flag[ii]) {
                s.insert(ii);
            }
        }
    }
    if (c) {
        for (int p: s) {
            flag[p] = false;
        }
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (flag[i]) {
            r++;
        }
    }
    printf("%d\n", r);
    for (int i = 0; i < n; i++) {
        if (flag[i]) {
            printf("%d", i+1);
            if (i == n-1) {
                printf("\n");
            } else {
                printf(" ");
            }
        }
    }
    return 0;
}