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

const int N=55;
int n, m;
char s[N][N], t[N+N][N+N], at[N][N];
bool ok(int dx, int dy)
{
    for (int i=0;i<n;++i) for (int j=0;j<n;++j) if (s[i][j]=='o')
    {
        int x=i+dx, y=j+dy;
        if (x<0||y<0||x>=n||y>=n) continue;
        if (s[x][y]=='.') return 0;
    }
    return 1;
}
void ma(int dx, int dy)
{
    for (int i=0;i<n;++i) for (int j=0;j<n;++j) if (s[i][j]=='o')
    {
        int x=i+dx, y=j+dy;
        if (x<0||y<0||x>=n||y>=n) continue;
        at[x][y]='x';
    }
}
int main()
{
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("\n%s",s[i]);
    m=n+n-1;
    for (int i=0;i<m;++i) for (int j=0;j<m;++j) t[i][j]='.';
    for (int i=0;i<n;++i) for (int j=0;j<n;++j) at[i][j]='.';
    for (int DX=0;DX<m;++DX) for (int DY=0;DY<m;++DY)
    {
        int dx=DX-n+1, dy=DY-n+1;
        if (ok(dx, dy)) t[DX][DY]='x', ma(dx, dy);
    }
    t[n-1][n-1]='o';
    //for (int i=0;i<m;++i) puts(t[i]); puts(""); puts("");
    //for (int i=0;i<n;++i) puts(at[i]); puts(""); puts("");
    for (int i=0;i<n;++i) for (int j=0;j<n;++j)
    {
        if (s[i][j]=='x'&&at[i][j]!='x')
        {
            //printf("%d %d\n", i, j);
            puts("NO");
            return 0;
        }
        if (s[i][j]=='.'&&at[i][j]=='x') throw;
    }
    puts("YES");
    for (int i=0;i<m;++i) puts(t[i]);
    return 0;
}