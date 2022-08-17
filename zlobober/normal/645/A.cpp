#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

struct table {
    char T[2][3];
    bool operator ==(table other) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (T[i][j] != other.T[i][j])
                    return false;
            }
        }
        return true;
    }
    void read() {
        scanf("%s", T[0]);
        scanf("%s", T[1]);
    }
    void rot() {
        if (T[0][0] == 'X') {
            swap(T[0][0], T[0][1]);
        } else if (T[0][1] == 'X') {
            swap(T[0][1], T[1][1]);
        } else if (T[1][1] == 'X') {
            swap(T[1][1], T[1][0]);
        } else if (T[1][0] == 'X') {
            swap(T[1][0], T[0][0]);
        } else {
            assert(false);
        }
    }
};

int main() {
    table a;
    table b;
    a.read();
    b.read();
    bool ans = false;
    for (int it = 0; it < 10000; it++) {
        a.rot();
        if (a == b)
            ans = true;
    }
    puts(ans ? "YES" : "NO");
}