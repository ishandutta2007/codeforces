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

int t;
char s[15], e[15][15];
int main()
{
    scanf("%d\n", &t);
    while (t--)
    {
        gets(s);
        vector<int> rs;
        for (int a=1;a<=12;++a) for (int b=1;b<=12;++b) if (a*b==12)
        {
            for (int i=0;i<a;++i) for (int j=0;j<b;++j) e[i][j]=s[i*b+j];
            bool ok=0;
            for (int j=0;j<b;++j)
            {
                bool z=1;
                for (int i=0;i<a;++i) if (e[i][j]=='O') z=0;
                ok|=z;
            }
            if (ok) rs.push_back(a);
        }
        printf("%d", int(rs.size()));
        for (int i=0;i<rs.size();++i) printf(" %dx%d", rs[i], 12/rs[i]);
        puts("");
    }
    return 0;
}