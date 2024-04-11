#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100500;

char buf[N];

int main() {
    int n;
    scanf("%d ", &n);
    gets(buf);
    int eq = 0;
    int neq = 0;
    for (int i = 1; i < n; i++) {
        (buf[i] == buf[i - 1] ? eq : neq)++;
    }
    int ans = 1 + neq + min(eq, 2);
    printf("%d\n", ans);
}