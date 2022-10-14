#include <cstdio>

using namespace std;

int a, b, c, d, e, f;
bool can() {
    if (d == 0) return false;
    if (c == 0) return true;
    if (b == 0) return false;
    if (a == 0) return true;
    if (f == 0) return false;
    if (e == 0) return true;
    return a * c * e < b * d * f;
}

int main() {
    #ifdef DEBUG
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    #endif
    while (scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f) == 6) {
        if (can()) {
            printf("Ron\n");
        } else {
            printf("Hermione\n");
        }
    }
}