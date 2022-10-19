#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 550;

int n;
int a[N][N];
void f(int x, int y, int val, int &k)
{
    if (x < y || x <= 0 || y <= 0)
        return;
    if (a[x][y] != 0 || k == 0)
        return;
    a[x][y] = val;
    k--;
    f(x - 1, y, val, k);
    f(x, y - 1, val, k);
    f(x + 1, y, val, k);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i][i]);
    for (int i = 1; i <= n; i++)
    {
        int k = a[i][i];
        a[i][i] = 0;
        f(i, i, k, k);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}