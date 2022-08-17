#include <algorithm>
#include <tuple>
#include <cstdio>
using namespace std;

const int M = 400;

bool used[M][M];

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct part {
    int x, y, v;
    void move(int d) {
        for (int i = 0; i < d; i++) {
            used[x][y] = true;
            x += dx[v], y += dy[v];
        }
        used[x][y] = true;
    }
    pair<part, part> split() {
        part l = *this, r = *this;
        l.v = (l.v + 1) & 7, r.v = (r.v + 7) & 7;
        return make_pair(l, r);
    }
    friend bool operator <(part a, part b) {
        return make_tuple(a.x, a.y, a.v) < make_tuple(b.x, b.y, b.v);
    }
    friend bool operator ==(part a, part b) {
        return make_tuple(a.x, a.y, a.v) == make_tuple(b.x, b.y, b.v);
    }
};

int main() {
    int n;
    scanf("%d", &n);
    vector<part> V = {{M / 2, M / 2, 0}};
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (i == 0)
            --t;
        vector<part> U;
        for (auto& p : V) {
            p.move(t);
            part l, r;
            tie(l, r) = p.split();
            U.emplace_back(l);
            U.emplace_back(r);
        }
        sort(U.begin(), U.end());
        U.resize(unique(U.begin(), U.end()) - U.begin());
        V.swap(U);
    }
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cnt += used[i][j];
        }
    }
    printf("%d\n", cnt);
}