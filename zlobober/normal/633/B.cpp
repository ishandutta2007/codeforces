#include <cstdio>
#include <algorithm>
using namespace std;

int get(int x, int k) {
    int ans = 0;
    while (x)
        ans += x / k, x /= k;
    return ans;
}

int get(int x) {
    int pw2 = get(x, 2);
    int pw5 = get(x, 5);
    return min(pw2, pw5);
}

int first(int m) {
    int l = 0, r = 5 * m + 10;
    while (r - l > 1) {
        int x = (l + r) / 2;
        if (get(x) < m)
            l = x;
        else
            r = x;
    }
    return r;
}

int main() {
    int m;
    scanf("%d", &m);
    int a = first(m);
    int b = first(m + 1);
    printf("%d\n", b - a);
    for (int i = a; i < b; i++)
        printf("%d%c", i, " \n"[i + 1 == b]);
}