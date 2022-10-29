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
vector<int> e;
int d[N], w[N];
bool oke(int x)
{
    while (x>0)
    {
        int a=x%10;
        if (a>=2) return 0;
        x/=10;
    }
    return 1;
}
int main()
{
    for (int i=1;i<N;++i) if (oke(i)) e.push_back(i);
    // for (int i=0;i<e.size();++i) cout<<e[i]<<endl;
    for (int i=1;i<N;++i)
    {
        d[i]=1e7;
        for (int j=0;j<e.size();++j) if (i>=e[j]&&d[i-e[j]]+1<d[i])
        {
            d[i]=d[i-e[j]]+1;
            w[i]=e[j];
        }
    }
    int n;
    scanf("%d", &n);
    printf("%d\n", d[n]);
    while (n)
    {
        printf("%d ", w[n]);
        n-=w[n];
    }
    puts("");
    return 0;
}