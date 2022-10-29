//
//         ."".    ."",
//         |  |   /  /
//         |  |  /  /
//         |  | /  /
//         |  |/  ;-._ 
//         }  ` _/  / ;
//         |  /` ) /  /
//         | /  /_/\_/\
//         |/  /      |
//         (  ' \ '-  |
//          \    `.  /
//           |      |
//           |      |
//

#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
#include <numeric>
using namespace std;
typedef long long ll;

const int N=1000*1000+10;
int d[N], h[N], n, m;
int main()
{
    scanf("%d %d", &n, &m);
    for (int i=0;i<m;++i) scanf("%d %d", &d[i], &h[i]);
    int rs=0;
    rs=max(rs, h[0]+d[0]-1);
    rs=max(rs, h[m-1]+n-d[m-1]);
    for (int i=0;i+1<m;++i)
    {
        int dx=abs(d[i]-d[i+1]), dy=abs(h[i]-h[i+1]);
        if (dy>dx)
        {
            puts("IMPOSSIBLE");
            return 0;
        }
        rs=max(rs, max(h[i], h[i+1])+(dx-dy)/2);
    }
    printf("%d\n", rs);
    return 0;
}