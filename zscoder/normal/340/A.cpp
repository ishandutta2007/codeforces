#include <stdio.h>

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int solve(int x, int y, int uppBound) 
{
    long long lcm = 1LL * x * y;
    lcm = lcm / gcd(x, y);
    return uppBound / lcm;
}

int main() 
{
    int x, y, A, B;
    scanf("%d%d%d%d", &x, &y, &A, &B);
    printf("%d", solve(x, y, B) - solve(x, y, A - 1));
    return 0;
}