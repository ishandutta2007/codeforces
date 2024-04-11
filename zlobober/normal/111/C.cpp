#include <iostream>
using namespace std;

const int M = 6;
const int MSK = 1 << M;
const int N = 45;
int D[45][MSK][MSK];

int col(int x)
{
    int ans = 0;
    while (x)
        ans += x % 2, x /= 2;
    return ans;
}

int n, m;

bool BIT(int x, int i)
{
    if (i < 0)
        return 0;
    return (x >> i) & 1;
}

bool bad(int a, int b, int c)
{
    for (int i = 0; i < m; i++)
        if (!(BIT(a, i) || BIT(c, i) || BIT(b, i - 1) || BIT(b, i) || BIT(b, i + 1)))
            return true;
    return false;
}


int main()
{
    cin >> n >> m;
    if (n < m)
        swap(n, m);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < MSK; j++)
            for (int k = 0; k < MSK; k++)
                D[i][j][k] = 1e9;
    for (int i = 0; i < MSK; i++)
        D[0][0][i] = col(i);

    for (int i = 1; i <= n; i++)
    {
        for (int pmsk = 0; pmsk < MSK; pmsk++)
            for (int msk = 0; msk < MSK; msk++)
            {
                for (int tmsk = 0; tmsk < MSK; tmsk++)
                {
                    if (bad(tmsk, pmsk, msk))
                        continue;
                    D[i][pmsk][msk] = min(D[i][pmsk][msk], D[i - 1][tmsk][pmsk] + col(msk));
                }
            }
    }
    int ans = 1e9;
    for (int msk = 0; msk < MSK; msk++)
    {
        ans = min(ans, (D[n][msk][0]));
    }
    cout << n * m - ans;

}