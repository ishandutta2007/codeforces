#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define mo 777777777
#define ll long long

using namespace std;

struct Matrix
{
    ll a[4][4];
    
    void init(ll x)
    {
        ll i, j;
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
                a[i][j] = 0;
        if (x == 4)
            a[1][1] = a[2][2] = a[3][3] = 1;
        else if (x)
            a[x][x] = 1;
        return;
    }
    
    void read()
    {
        ll i, j;
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
                scanf("%I64d", &a[i][j]);
        return;
    }
    
    friend Matrix operator * (Matrix &a, Matrix &b)
    {
        Matrix ret;
        ll i, j, k;
        ret.init(0);
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
                for (k = 1; k <= 3; k++)
                    ret.a[i][j] += a.a[i][k] * b.a[k][j], ret.a[i][j] %= mo;
        return ret;
    }
}OK, vv[400005];

ll Left[400005], Right[400005];
ll n, m, i, j, k, Ans, Now, v, t, Val[100005];

void Up(ll i);
void Make(ll l, ll r, ll i);
void Work(ll l, ll r, ll i, ll t);

int main()
{
    scanf("%I64d %I64d", &n, &m);
    OK.read();
    Now = n;
    Make(1, n, 1);
    for (i = 1; i <= m; i++)
    {
        scanf("%I64d %I64d", &v, &t);
        if (Val[v] == 0 && t != 0)
            Now--;
        if (Val[v] != 0 && t == 0)
            Now++;
        Val[v] = t;
        Work(v, v, 1, t);
        Ans = 0;
        for (j = 1; j <= 3; j++)
            for (k = 1; k <= 3; k++)
                Ans = (Ans + vv[1].a[j][k]) % mo;
        printf("%I64d\n", Ans);
    }
    
    return 0;
}

void Up(ll i)
{
    ll lc = (i << 1), rc = (lc | 1);
    vv[i] = vv[lc] * OK;
    vv[i] = vv[i] * vv[rc];
    return;
}

void Make(ll l, ll r, ll i)
{
    ll mid = ((l + r) >> 1);
    Left[i] = l, Right[i] = r;
    if (l == r)
    {
        vv[i].init(4);
        return;
    }
    
    Make(l, mid, (i << 1));
    Make(mid + 1, r, ((i << 1) | 1));
    Up(i);
    return;
}

void Work(ll l, ll r, ll i, ll t)
{
    if (l > Right[i] || r < Left[i])
        return;
    if (l <= Left[i] && r >= Right[i])
    {
        if (t == 0)
            vv[i].init(4);
        else
            vv[i].init(t);
        return;
    }
    
    Work(l, r, (i << 1), t);
    Work(l, r, ((i << 1) | 1), t);
    Up(i);
    return;
}