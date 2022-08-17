#include <cstdio>
#include <memory.h>
#include <utility>
using namespace std;

int abs(int x)
{
    return (x < 0) ? -x : x;
}

const int N = 4050;

typedef long long llong;

const llong MOD = 1000*1000*1000 + 7;

llong cnt[2][2];

int _gcd[N][N];

int gcd(int a, int b)
{
    if (_gcd[a][b] != -1)
        return _gcd[a][b];
    if (b == 0)
        return _gcd[a][b] = a;
    else
        return _gcd[a][b] = gcd(b, a % b);
}

int main()
{
    memset(_gcd, -1, sizeof(_gcd));
    int w, h;
    scanf("%d %d", &w, &h);
    for (int y = 0; y <= h; y++)
        for (int x = 0; x <= w; x++)
            cnt[y & 1][x & 1]++;
    llong good = 0;
    for (int msk = 0; msk < 64; msk++)
    {
        int x[6];
        for (int i = 0; i < 6; i++)
            x[i] = (msk >> i) & 1;
        int s = x[0] * x[3] - x[1] * x[2] + x[2] * x[5] - x[3] * x[4] + x[4] * x[1] - x[5] * x[0];
        if (s % 2 == 0)
            good = (good + (((cnt[x[0]][x[1]] * cnt[x[2]][x[3]]) % MOD) * cnt[x[4]][x[5]]) % MOD) % MOD;
    }
    good -= (w + 1) * (h + 1);
    llong q = ((w + 1) * (h + 1));
    llong q2 = q - 1;
    good -= ((q * q2) * 3) % MOD;

    for (int vx = 0; vx <= w; vx++)
    {
        for (int vy = (vx == 0) ? 1 : -h; vy <= h; vy++)
        {
            if (vy == 0 && vx == 0)
                continue;
            llong num = gcd(vx, abs(vy)) - 1;
            good = (good - 6 * num * (h - abs(vy) + 1) * (w - vx + 1)) % MOD;
        }
    }

    good %= MOD;
    good += MOD;
    good %= MOD;


    printf("%d\n", (int)good);
}