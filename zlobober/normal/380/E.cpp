#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int N = 1 << 19;

double pw2[8 * N];

struct mynum
{
    double v;
    int sh;
    mynum(double _v, int _sh)
    {
        v = _v;
        //assert(v == v);
        sh = _sh;
    }
    mynum(){}
    mynum shift(int x)
    {
        return mynum(v, sh + x);
    }
    friend mynum operator +(mynum a, mynum b)
    {
        if (a.sh < b.sh)
            swap(a, b);
        if (b.v == 0)
            return a;
        if (a.v == 0)
            return b;
        b.v *= pw2[b.sh - a.sh + 4 * N];
        return mynum(a.v + b.v, a.sh);
    }
};

struct tree
{
    int sh[2 * N];
    mynum T[2 * N];

    void push(int v)
    {
        if (v >= N)
        {
            T[v].sh += sh[v];
            sh[v] = 0;
        }
        else
        {
            sh[2 * v] += sh[v];
            sh[2 * v + 1] += sh[v];
            T[v].sh += sh[v];
            sh[v] = 0;
        }
    }

    mynum get(int l, int r, int L = 1, int R = N, int v = 1)
    {
        if (r < L || l > R)
            return mynum(0, 0);
        else if (l <= L && R <= r)
            return T[v].shift(sh[v]);
        else
        {
            push(v);
            return get(l, r, L, (L + R) / 2, 2 * v) + get(l, r, (L + R) / 2 + 1, R, 2 * v + 1);
        }
    }

    inline int getsh(int x)
    {
        int L = 1, R = N, v = 1;
        while (v < N)
        {
            push(v);
            if ((L + R) / 2 >= x)
                v = 2 * v, R = (L + R) / 2;
            else
                v = 2 * v + 1, L = (L + R) / 2 + 1;
        }
        return sh[v] + T[v].sh;
    }

    void ch(int l, int r, int x, int L = 1, int R = N, int v = 1)
    {
        if (r < L || l > R)
            return;
        else if (l <= L && R <= r)
            sh[v] += x;
        else
        {
            push(v);
            ch(l, r, x, L, (L + R) / 2, 2 * v);
            ch(l, r, x, (L + R) / 2 + 1, R, 2 * v + 1);
            T[v] = T[2 * v].shift(sh[2 * v]) + T[2 * v + 1].shift(sh[2 * v + 1]);
        }
    }
    tree(){}
    void init()
    {
        for (int i = N; i < 2 * N; i++)
            sh[i] = 0, T[i] = mynum(1, 0);
        for (int i = N - 1; i > 0; i--)
            sh[i] = 0, T[i] = T[2 * i] + T[2 * i + 1];
    }
};

tree TL, TR;

int main()
{
    pw2[4 * N] = 1;
    for (int i = 1; i < 4 * N - 10; i++)
        pw2[4 * N + i] = pw2[4 * N + i - 1] * 2.0,
        pw2[4 * N - i] = pw2[4 * N - i + 1] / 2.0;
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > V;
    TL.init();
    TR.init();
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        V.push_back(make_pair(-t, i));
    }
    sort(V.begin(), V.end());
    double ans = 0;
    for (int i = 0; i < V.size(); i++)
    {
        int v = -V[i].first;
        int p = V[i].second;
        mynum a = TL.get(1, p);
        int sa = TL.getsh(p);
        mynum b = TR.get(p, n);
        int sb = TR.getsh(p);
        a = a.shift(-sa);
        b = b.shift(-sb);
        assert(a.v == a.v);
        assert(b.v == b.v);
        assert(v == v);
        int tp = a.sh + b.sh;
        double res = v * a.v * b.v * pw2[4 * N + tp]; // #
        assert(pw2[4 * N + tp] == pw2[4 * N + tp]);
        assert(res == res);
        //assert(res == res);
        //eprintf("%.6lf\n", res);
        ans += res;
        TL.ch(1, p, -1);
        TR.ch(p, n, -1);
    }
    ans /= 2 * (double)n * (double)n;
    printf("%.10lf\n", ans);
}