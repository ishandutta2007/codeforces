#include <iostream>
#include <memory.h>
using namespace std;

const int N = 1000500;

int D[N];

int get(int x, bool w)
{
    if (x < 0)
        return N + 1;
    if (x == 0)
        return 0;
    int ans = 0;
    if (D[x] != -1)
        ans = D[x];
    else
    {
        if (get(x - 7, 0) < get(x - 4, 0))
            D[x] = get(x - 7, 0) + 1;
        else
            D[x] = get(x - 4, 0) + 1;
        ans = D[x];
    }

    if (w)
    {
        int a;
        if (get(x - 7, 0) < get(x - 4, 0))
            a = 7;
        else
            a = 4;
        if (get(x - a, 0) > N)
            return N + 1;
        cout << a;
        get(x - a, 1);
    }
    return ans;
}

int main()
{
    memset(D, -1, sizeof(D));
    D[0] = 0;
    int n;
    cin >> n;
    if (get(n, 1) > N)
        cout << -1;
}