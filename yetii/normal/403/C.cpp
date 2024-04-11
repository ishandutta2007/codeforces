#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

int n, g[2222][2222], c, u[2222];
void go(int v)
{
    ++c; u[v]=1;
    for (int i=0;i<n;++i) if (g[v][i]&&!u[i]) go(i);
}
int main()
{
    scanf("%d", &n);
    int s=0;
    for (int i=0;i<n;++i) for (int j=0;j<n;++j)
    {
        scanf("%d", &g[i][j]);
    }
    for (int i=0;i<n;++i) if (g[i][i]) s=i;
    int r=0;
    for (int it=0;it<2;++it)
    {
        c=0; memset(u, 0, sizeof(u));
        go(s);
        if (c==n) ++r;
        for (int i=0;i<n;++i) for (int j=0;j<i;++j) swap(g[i][j], g[j][i]);
    }
    puts(r==2?"YES":"NO");
    return 0;
}