#include <cstdio>
using namespace std;

const int N = 100500;
char buf[N];
int L[N];

bool was[N];

int main() {
    int n;
    scanf("%d", &n);
    scanf(" %s", buf);
    for (int i = 0; i < n; i++) {
        scanf("%d", &L[i]);
    }
    int x = 0;
    while (!was[x]) {
        was[x] = true;
        x += L[x] * ((buf[x] == '>') ? 1 : -1);
        if (x < 0 || x >= n) {
            puts("FINITE");
            return 0;
        }
    }
    puts("INFINITE");
}