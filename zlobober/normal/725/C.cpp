#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <memory.h>
using namespace std;

const int N = 13;
char F[2][N + 1];
char buf[2 * N + 3];

int pos[128];

void put(int y, int x, char c) {
    assert(y <= 1 && y >= 0 && x < N && x >= 0);
    assert(F[y][x] == 0);
    F[y][x] = c;
}

int main() {
    scanf("%s", buf);
    memset(pos, -1, sizeof(pos));
    int a = -1, b = -1;
    for (int i = 0; i < 2 * N + 1; i++) {
        if (pos[buf[i]] == -1) {
            pos[buf[i]] = i;
        } else {
            assert(a == -1);
            a = pos[buf[i]];
            b = i;
        }
    }
    for (int c = 'A'; c <= 'Z'; c++)
        assert(pos[c] != -1);
    if (a + 1 == b) {
        puts("Impossible");
        return 0;
    }

    int len = b - a - 1;
    assert(len >= 0);
    int pos = N - 1 - len / 2;
    int y = 0, x = pos;
    for (int i = a; i < b; i++) {
        put(y, x, buf[i]);
        if (y == 0 && x == N - 1) {
            y = 1;
        } else if (y == 0) {
            x++;
        } else {
            x--;
        }
    }
    assert(x == pos - 1 || x == pos);
    vector<pair<int, int>> s[2];
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < 2; i++) {
            if (F[i][j] == 0)
                s[i].emplace_back(i, j);
        }
    }
    reverse(s[1].begin(), s[1].end());
    auto seq = s[1];
    seq.insert(seq.end(), s[0].begin(), s[0].end());
    assert(seq.size() == a + (2 * N - b));
    for (int i = a - 1; i >= 0; i--) {
        put(seq.back().first, seq.back().second, buf[i]);
        seq.pop_back();
    }
    for (int i = 2 * N; i >= b + 1; i--) {
        put(seq.back().first, seq.back().second, buf[i]);
        seq.pop_back();
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            assert(F[i][j] != 0);
            printf("%c", F[i][j]);
        }
        printf("\n");
    }

}