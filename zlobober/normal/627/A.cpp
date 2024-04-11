#include <cstdio>
using namespace std;

typedef long long llong;

const int N = 55;
llong D[N][2];

int main() {
    llong s, x;
    scanf("%lld %lld", &s, &x);
    D[0][0] = 1;
    for (int i = 0; i < N - 1; i++) {
        for (int carry = 0; carry < 2; carry++) {
            for (int a = 0; a < 2; a++) {   
                for (int b = 0; b < 2; b++) {
                    int cur_s = (a + b + carry) % 2;
                    int ncarry = (a + b + carry) / 2;
                    int cur_x = a ^ b;
                    if (cur_s == ((s >> i) & 1) && cur_x == ((x >> i) & 1))
                        D[i + 1][ncarry] += D[i][carry];
                }
            }
        }
    }
    llong ans = D[N - 1][0];
    if (s == x)
        ans -= 2;
    printf("%lld\n", ans);
}