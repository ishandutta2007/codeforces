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

void g4()
{
    puts("2 * 3 = 6");
    puts("6 * 4 = 24");
}
void g5()
{
    puts("3 + 4 = 7");
    puts("7 + 5 = 12");
    puts("2 * 12 = 24");
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    if (n<4) puts("NO");
    else
    {
        puts("YES");
        int o=1;
        while (n-2>=4) printf("%d - %d = 1\n", n, n-1), ++o, n-=2;
        if (n==5) g5(); else g4();
        while (o) puts("1 * 24 = 24"), --o;
    }
    return 0;
}