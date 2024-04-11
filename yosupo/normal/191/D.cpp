#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;
const int MAX_N = 100010;
vector<int> edge[MAX_N];
int roop_base[MAX_N] = {}, roop_count[MAX_N] = {}, roop_num = 0;
bool used[MAX_N] = {}, roop_flag[MAX_N] = {};

int roop_check(int i, int back) {
    used[i] = true;
    int r = -1;
    for (int d: edge[i]) {
        if (d == back) continue;
        if (!used[d]) {
            int rc = roop_check(d, i);
            if (r == -1 && rc != -1) {
                r = rc;
                roop_flag[i] = true;
                if (edge[i].size() > 2) roop_count[r]++;
                if (roop_base[r] == i) {
                    r = -1;
                }
            }
        } else if (!roop_flag[d]) {
            r = roop_num;
            roop_num++;
            roop_base[r] = d;
            roop_flag[i] = true;
            if (edge[i].size() > 2) roop_count[r]++;
        }
    }
    return r;
}

int main(int argc, char *argv[]) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (edge[i].size() % 2) {
            r++;
        }
    }
    r /= 2;
    roop_check(0, -1);
    for (int i = 0; i < roop_num; i++) {
        if (roop_count[i] < 2) r++;
    }
    printf("%d %d\n", r, m);
    return 0;
}