#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

struct ev
{
    int x;
    int t;
    double prob;
    int i;
    ev(int _x, int _t)
    {
        x = _x, t = _t;
        prob = i = -1;
    }
    ev(int _x, int _t, double _prob, int _i)
    {
        x = _x, t = _t, prob = _prob, i = _i;
    }
    friend bool operator <(ev a, ev b)
    {
        if (a.x != b.x)
            return a.x < b.x;
        if (a.t != b.t)
            return a.t < b.t;
        return false;
    }
};

const int N = 1 << 19;
double T[2 * N];

void set(int i, double x)
{
    i += N - 1;
    T[i] = x;
    while (i /= 2)
        T[i] = T[2 * i] * T[2 * i + 1];
}

int Z[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 2 * N; i > 0; i--)
        T[i] = 1;
    vector<ev> E;
    for (int i = 0; i < n; i++)
    {
        int a, h, l, r;
        cin >> a >> h >> l >> r;
        E.push_back(ev(a - h, 1, 1 - l / 100.0, 2 * i + 1));
        E.push_back(ev(a, 0, 1 - l / 100.0, 2 * i + 1));
        E.push_back(ev(a + 1, 1, 1 - r / 100.0, 2 * i + 2));
        E.push_back(ev(a + h + 1, 0, 1 - l / 100.0, 2 * i + 2));
    }
    for (int i = 0; i < m; i++)
    {
        int b, z;
        cin >> b >> z;
        Z[i] = z;
        E.push_back(ev(b, 2, -1, i));
    }
    sort(E.begin(), E.end());
    double ans = 0;
    for (int i = 0; i < E.size(); i++)
    {
        if (E[i].t == 1)
            set(E[i].i, E[i].prob);
        else if (E[i].t == 0)
            set(E[i].i, 1);
        else
            ans += Z[E[i].i] * T[1];
    }
    cout << fixed << setprecision(10);
    cout << ans;
}