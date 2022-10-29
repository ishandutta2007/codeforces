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

using namespace std;
int t, n, p, g[50][50];
void make(int n, int p)
{
    for (int i=0;i<n;++i) for (int j=0;j<n;++j) g[i][j]=0;
    for (int i=0;i<5;++i) for (int j=0;j<i;++j) g[i][j]=g[j][i]=1;
    for (int i=5;i<n;++i) for (int j=0;j<2;++j) g[i][j]=g[j][i]=1;
    for (int i=0;i<n;++i) for (int j=0;j<i;++j) if (!g[i][j]&&p)
    {
        g[i][j]=g[j][i]=1;
        --p;
    }
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &p);
        make(n, p);
        for (int i=0;i<n;++i) for (int j=0;j<i;++j) if (g[i][j]) printf("%d %d\n", i+1, j+1);
    }
    return 0;
}