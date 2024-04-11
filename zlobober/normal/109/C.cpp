#include <iostream>
#include <cassert>
#include <list>
#include <vector>
using namespace std;

const int N = 100500;

int p[N];
int s[N];
int v[N];

bool bad(int x)
{
    if (x == 0)
        return true;
    while (x)
    {
        if (x % 10 != 4 && x % 10 != 7)
            return true;
        x /= 10;
    }
    return false;
}

int get(int x)
{
    return (x == p[x]) ? x : (p[x] = get(p[x]));
}


void merge(int a, int b)
{
    a = get(a), b = get(b);
    assert(a != b);
    if (v[a] == v[b])
        v[a]++;
    if (v[a] < v[b])
        swap(a, b);
    p[b] = a;
    s[a] += s[b];
}


int main()
{
    for (int i = 0; i < N; i++)
        s[i] = 1, p[i] = i, v[i] = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        if (bad(w))
            merge(a, b);
    }

    long long ans = 0;

    for (int i = 1; i <= n; i++)
        ans += (long long)(n - s[get(i)]) * (long long)(n - s[get(i)] - 1);
    cout << ans;
}