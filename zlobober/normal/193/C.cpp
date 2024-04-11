#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int A[4][4];

void die()
{
    cout << -1 << endl;
    exit(0);
}

int main()
{
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j <= 3; j++)
            scanf("%d", &A[i][j]), A[j][i] = A[i][j];
    int b[4];
    for (int i = 1; i <= 3; i++)
        b[i] = A[0][i];
    if (A[1][2] > b[1] + b[2])
        die();
    if (A[2][3] > b[2] + b[3])
        die();
    if (A[3][1] > b[3] + b[1])
        die();
    int q = b[1] + b[2] - A[1][2];
    if (q % 2 != 0)
        die();
    q /= 2;
    int p = b[1] - q;
    int r = b[2] - q;
    if (p < 0 || q < 0 || r < 0)
        die();
    for (int t = 0; t <= 300000; t++)
    {
        int al = b[3] - t;
        int be = A[2][3] - t - q - r; // x - y - z
        int ga = A[1][3] - t - p - q; // z - y - x

        int y2 = -be - ga;
        if (y2 % 2 != 0)
            continue;
        int y = y2 / 2;

        int x2 = al + be;
        if (x2 % 2 != 0)
            continue;
        int x = x2 / 2;

        int z2 = al + ga;
        if (z2 % 2 != 0)
            continue;
        int z = z2 / 2;

        if (x > p || y > q || z > r || x < 0 || y < 0 || z < 0)
            continue;

        string S[4];
        int n = p + q + r + t;
        cout << n << endl;
        S[0] = string(n, 'a');
        S[1] = string(p + q, 'b') + string(r + t, 'a');
        S[2] = string(p, 'a') + string(q + r, 'b') + string(t, 'a');
        S[3] = string(x, 'b') + string(p - x, 'a') + string(y, 'b') + string(q - y, 'a') +
               string(z, 'b') + string(r - z, 'a') + string(t, 'b');
        cout << S[0] << endl << S[1] << endl << S[2] << endl << S[3] << endl;
        return 0;
    }
    die();
    return 0;
}