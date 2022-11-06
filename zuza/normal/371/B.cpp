#include <cstdio>
#include <cstdlib>

using namespace std;

int main(void) {
    int a, b; scanf("%d %d", &a, &b);
    int sol = 0;
    auto f = [&a, &b, &sol](int d) {
        int a_cnt = 0;
        for (; a%d == 0; a /= d) ++a_cnt;
        int b_cnt = 0;
        for (; b%d == 0; b /= d) ++b_cnt;
        sol += abs(a_cnt - b_cnt);
    };
    f(2); f(3); f(5);
    if (a != b) puts("-1");
    else printf("%d\n", sol);
    return 0;
}