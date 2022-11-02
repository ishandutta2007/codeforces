#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, a[N], b[N], c[N];

int or_(int x, int y, int res = 0) {
    printf("or %d %d\n", x, y);
    fflush(stdout);
    scanf("%d", &res); 
    return res;
}

int and_(int x, int y, int res = 0) {
    printf("and %d %d\n", x, y);
    fflush(stdout);
    scanf("%d", &res); 
    return res;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 2; i <= n; i++) 
        a[i] = or_(i, 1), b[i] = and_(i, 1), c[i] = a[i]^b[i], c[1] |= b[i];

    int k = or_(2, 3);
    
    for (int i = 0; i < 30; i++)
        if (!(c[1]&(1<<i)) && !(k&(1<<i))) {
            c[1] ^= 1<<i;

            for (int j = 2; j <= n; j++)
                if (!(a[j]&(1<<i))) {
                    c[1] ^= 1<<i;
                    break;
                }
        }
    
    for (int i = 2; i <= n; i++)
        c[i] ^= c[1];
    
    sort(c + 1, c + n + 1);

    printf("finish %d\n", c[m]);
    fflush(stdout);
}