#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, k, step, p, a[N], b[N];

int cnt;
void f()
{
    for (int j = 0; j < n; j++)
        if (j != p)
        {
            b[(j + 1) % n] += a[j] - a[j] / 2;
            b[(j + n - 1) % n] += a[j] / 2;
        }
        else
        {
            b[(j + 1) % n] += a[j];
        }
    
    for (int j = 0; j < n; j++)
        a[j] = b[j], b[j] = 0;
}

int ask(int i)
{
    i %= n;
    i += n;
    i %= n;
    int x;

    cout << "? " << i + 1 << endl;
    cin >> x;

    // cnt++;
    // x = a[i];
    // f();

    return x;
}
void ans(int i)
{
    i %= n;
    i += n;
    i %= n;
    // cerr << cnt << endl;
    cout << "! " << i + 1 << endl;
    exit(0);
}
int main()
{
    cin >> n >> k;

    // cin >> p;
    // for (int i = 0; i < n; i++)
    //     a[i] = k;

    step = sqrt(n) + 1;

    int i = 0;
    while (true)
    {
        int x = ask(i);

        if (x == k)
        {
            i = (i + step) % n;
            continue;
        }

        if (x > k)
        {
            //need left
            int l = 0, r = n / 2;
            while (l <= r)
            {
                int m = (l + r) / 2;
                int x = ask(i - m);
                if (x > k)
                    l = m + 1;
                else
                    r = m - 1;
            }
            ans(i - l);
        }

        if (x < k)
        {
            //need right
            int l = 0, r = n / 2;
            while (l <= r)
            {
                int m = (l + r) / 2;
                int x = ask(i + m);
                if (x < k)
                    l = m + 1;
                else
                    r = m - 1;
            }
            ans(i + l);
        }
    }
}