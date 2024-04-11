#include <cstdio>
using namespace std;

const int N = 10500;

bool can[N];

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    can[0] = true;
    for (int i = 0; i < c; i++) {
        if (can[i])
            can[i + a] = can[i + b] = true;
    }
    printf("%s\n", can[c] ? "Yes" : "No");
}