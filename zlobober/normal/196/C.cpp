#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <cstdio>
using namespace std;

const int N = 5500;
vector<int> E[N];

bool done = false;

struct pt
{
    int x, y;
};


pt P[N];

int pt = 0;
int ord[N];
int to[N];

typedef long long llong;

struct cmp
{
    llong x, y;

    cmp(llong _x, llong _y)
    {
        x = _x, y = _y;
    }
    bool operator()(int a, int b)
    {
        llong x1 = P[a].x - x, y1 = P[a].y - y;
        llong x2 = P[b].x - x, y2 = P[b].y - y;
        llong d = x1 * y2 - x2 * y1;
        assert(d != 0);
        return d < 0;
    }
};

int sz[N];

void DFS1(int x, int p)
{
    sz[x] = 1;
    for (int y : E[x])
    {
        if (y == p)
            continue;
        DFS1(y, x);
        sz[x] += sz[y];
    }
}



void DFS(int x, int p, int *beg, int* end)
{
    assert(end - beg == sz[x]);
    for (int i = 0; i < end - beg; i++)
        if (P[beg[i]].y < P[beg[0]].y)
            swap(beg[i], beg[0]);

    sort(beg + 1, end, cmp(P[beg[0]].x, P[beg[0]].y));
    to[*beg] = x;
    int *cur = beg + 1;
    for (int y : E[x])
    {
        if (y == p)
            continue;
        DFS(y, x, cur, cur + sz[y]);
        cur += sz[y];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &P[i].x, &P[i].y);
        ord[i - 1] = i;
    }
    DFS1(1, 0);
    DFS(1, 0, ord, ord + n);
    for (int i = 1; i <= n; i++)
        printf("%d ", to[i]);
}