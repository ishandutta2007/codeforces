#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define xx 1000000
#define ll long long

using namespace std;

ll mo, l, r, k, i, x = 1;

struct Matrix
{
    ll v[3][3];
    
    friend Matrix operator * (Matrix a, Matrix b)
    {
        Matrix ret;
        ll i, j, k;
        for (i = 1; i <= 2; i++)
            for (j = 1; j <= 2; j++)
                ret.v[i][j] = 0;
        for (i = 1; i <= 2; i++)
            for (j = 1; j <= 2; j++)
                for (k = 1; k <= 2; k++)
                    ret.v[i][j] += a.v[i][k] * b.v[k][j], ret.v[i][j] %= mo;
        return ret;
    }
}a, c;

void sumi(ll m);
ll check(ll x);

int main()
{
    scanf("%I64d %I64d %I64d %I64d", &mo, &l, &r, &k);
    for (i = 1; i <= xx; i++)
    {
        if (check(i))
            x = max(x, i);
        if (check(r / i))
            x = max(x, r / i);
    }
    
    c.v[1][1] = 0, c.v[1][2] = c.v[2][1] = c.v[2][2] = 1;
    if (x <= 2)
        printf("%d\n", 1 % mo);
    else
    {
        sumi(x - 1);
        printf("%I64d\n", (a.v[1][1] + a.v[2][1]) % mo);
    }
    
    return 0;
}

void sumi(ll m)
{
    ll i, tag = 0;
    for (i = 1; i <= m; (i <<= 1))
    {
        if ((m & i) > 0)
        {
            if (tag == 0)
                tag = 1, a = c;
            else
                a = a * c;
        }
        
        c = c * c;
    }
    
    return;
}

ll check(ll x)
{
    if (x == 0)
        return x;
    ll s = r / x - l / x;
    if (l % x == 0)
        s++;
    if (s >= k)
        return 1;
    return 0;
}