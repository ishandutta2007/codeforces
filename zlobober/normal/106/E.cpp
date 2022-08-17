#include <iostream>
#include <iomanip>
using namespace std;

int n;
const int N = 150;

#define double long double

struct vt
{
    double x, y, z;
    inline double& operator [](int i)
    {
        return (i == 0) ? x : ((i == 1) ? y : z);
    }
} P[N];

inline double len(vt a, vt b)
{
    double ans = 0;
    for (int i = 0; i < 3; i++)
        ans += (a[i] - b[i]) * (a[i] - b[i]);
    return ans;
}

inline double get(vt v)
{
    double mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, len(P[i], v));
    return mx;
}

inline bool gr(vt a, vt b)
{
    return get(a) < get(b);
}

const int T = 10;

const double EPS = 1e-6;

vt best;
vt cur;

inline double bs(int i)
{
    if (i == 3)
    {
        if (gr(cur, best))
            best = cur;
        return get(cur);
    }
    double a = -1e4;
    double b = 1e4;
    while (b - a > EPS)
    {

        double p = ((T + 1) * a + (T - 1) * b) / (2 * T);
        double q = ((T - 1) * a + (T + 1) * b) / (2 * T);
        cur[i] = p;
        double pv = bs(i + 1);
        cur[i] = q;
        double qv = bs(i + 1);
        if (pv < qv)
            b = q;
        else
            a = p;
    }
    cur[i] = (a + b) / 2;
    return bs(i + 1);
}

int main()
{
    cout << fixed << setprecision(10);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> P[i].x >> P[i].y >> P[i].z;
    bs(0);
    cout << best[0] << ' ' << best[1] << ' ' << best[2];
}