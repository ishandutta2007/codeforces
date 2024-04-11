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
#include <string>
#include <numeric>
#include <memory.h>
using namespace std;
typedef long long ll;

const int M=4e5;
int n, a[M], d1[M], d2[M], f[M];
int main()
{
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    for (int i=0;i<n;++i)
    {
        int j=i-1;
        while (j>=0&&a[j]>=a[i]) j=d1[j];
        d1[i]=j;
    }
    for (int i=n-1;i>=0;--i)
    {
        int j=i+1;
        while (j<n&&a[j]>=a[i]) j=d2[j];
        d2[i]=j;
    }
    for (int i=0;i<n;++i)
    {
        int z=d2[i]-d1[i]-1;
        f[z]=max(f[z], a[i]);
    }
    for (int i=n;i;--i) f[i-1]=max(f[i-1], f[i]);
    for (int i=0;i<n;++i)
    {
        printf("%d ", f[i+1]);
    }
    puts("");
    return 0;
}