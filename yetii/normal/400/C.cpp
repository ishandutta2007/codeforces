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

int n, m, x, y, z, p;
int main()
{
    scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &z, &p);
    x%=4; y%=2; z%=4;
    for (int i=0;i<p;++i)
    {
        int a, b, n0=n, m0=m; scanf("%d %d", &a, &b);
        for (int j=0;j<x;++j)
        {
            a=n0-a+1;
            swap(a, b);
            swap(n0, m0);
        }
        for (int j=0;j<y;++j)
        {
            b=m0-b+1;
        }
        for (int j=0;j<z;++j)
        {
            for (int k=0;k<3;++k)
            {
                a=n0-a+1;
                swap(a, b);
                swap(n0, m0);
            }
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}