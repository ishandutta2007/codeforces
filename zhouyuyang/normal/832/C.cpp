#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int OPEN = 1;
const int CLOSE = -1;

struct tsob
{
    int x, t, id;
};

inline bool operator<(const tsob &a, const tsob &b)
{
    if (a.x != b.x) return a.x < b.x;
    return a.t == OPEN && b.t == CLOSE;
}

const int maxn = 100005;
const int DR = 1000000;

int curb[2];
vector<tsob> sobs;
int x[maxn], v[maxn], dir[maxn], dist[maxn];
int n, s;

bool can(ld t)
{
    sobs.clear();
    curb[0] = 0;
    curb[1] = 0;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] <= (ll)v[i] * t)
        {
            curb[dir[i]]++;
        } else if (dist[i] <= (ll)(v[i] + s) * t)
        {
            // A * r + B = 0
            ld A = (ld)1 / (s - v[i]) - (ld)v[i] / (s - v[i]) / (s + v[i]);
            ld B = (ld)dist[i] / (s + v[i]) - t;
            ld r = -B / A;
            if (dir[i] == 0)
            {
                sobs.pb({x[i], OPEN, dir[i]});
                sobs.pb({lround(min((ld)DR + 1, floor(x[i] + r))), CLOSE, dir[i]});
            } else
            {
                sobs.pb({lround(max((ld)-1.0, ceil(x[i] - r))), OPEN, dir[i]});
                sobs.pb({x[i], CLOSE, dir[i]});
            }
        }
    }
    if (curb[0] > 0 && curb[1] > 0) return true;
    sort(all(sobs));
    for (auto t : sobs)
    {
        curb[t.id] += t.t;
        if (curb[0] > 0 && curb[1] > 0) return true;
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &x[i], &v[i], &dir[i]);
        dir[i]--;
        if (dir[i] == 0) dist[i] = x[i];
        else dist[i] = DR - x[i];
    }
    ld l = 0;
    ld r = 1e6;
    for (int IT = 0; IT < 100; IT++)
    {
        ld m = (l + r) / 2;
        if (can(m)) r = m;
        else l = m;
    }
    cout.precision(20);
    cout << (double)(l + r) / 2 << endl;
    return 0;
}