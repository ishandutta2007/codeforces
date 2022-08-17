#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int C = 4;

vector<pair<int, int> > P;

int n, m;

double dist(pair<int, int> a, pair<int, int> b)
{
    return sqrt(1.0 * (a.first - b.first) * (a.first - b.first) + 1.0 * (a.second - b.second) * (a.second - b.second));
}

bool good(int x, int y)
{
    return 0 <= x && x <= n && 0 <= y && y <= m;
}

void write(pair<int, int> a)
{
    printf("%d %d\n", a.first, a.second);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            if (good(i, j))
                P.push_back(make_pair(i, j));
            if (good(n - i, j))
                P.push_back(make_pair(n - i, j));
            if (good(i, m - j))
                P.push_back(make_pair(i, m - j));
            if (good(n - i, m - j))
                P.push_back(make_pair(n - i, m - j));
        }
    sort(P.begin(), P.end());
    P.resize(unique(P.begin(), P.end()) - P.begin());
    pair<double, pair<pair<int, int>, pair<int, int> > > ans(-1.0, make_pair(make_pair(-42, -42), make_pair(-42, -42)));
    for (int i = 0; i < P.size(); i++)
        for (int j = 0; j < P.size(); j++)
        {
            if (i == j)
                continue;
            for (int a = 0; a < P.size(); a++)
            {
                if (a == i || a == j)
                    continue;
                for (int b = 0; b < P.size(); b++)
                {
                    if (b == i || b == j || b == a)
                        continue;
                    double d = dist(P[i], P[j]) + dist(P[j], P[a]) + dist(P[a], P[b]);
                    ans = max(ans, make_pair(d, make_pair(make_pair(i, j), make_pair(a, b))));
                }
            }
        }
    fprintf(stderr, "%.7lf\n", ans.first);
    write(P[ans.second.first.first]);
    write(P[ans.second.first.second]);
    write(P[ans.second.second.first]);
    write(P[ans.second.second.second]);
}