#include <cstdio>
#include <cmath>

#define PIE 3.1415926535

using namespace std;

int main()
{
    int n,r; scanf("%d%d",&n,&r);
    double x = sin(PIE / n);
    double ans = r * x / (1 - x);
    printf("%.15f",ans);
    return 0;
}