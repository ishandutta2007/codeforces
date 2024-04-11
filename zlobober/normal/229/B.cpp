#include <cstdio>
#include <vector>
#include <set>
using namespace std;

const int INF = 2000000000;

const int N = 100500;
vector<pair<int, int> > E[N];

vector<pair<int, int> > bad[N];

int D[N];
set<pair<int, int> > Q;

int corr(const vector<pair<int, int> >& V, int x)
{
    vector<pair<int, int> >::const_iterator it = lower_bound(V.begin(), V.end(), make_pair(x, INF));
    if (it == V.begin())
        return x;
    --it;
    return max(x, it->second);
}

bool was[N];

int n, m;


int dij()
{
    for (int i = 1; i <= n; i++)
    {
        D[i] = (i != 1) * INF;
        Q.insert(make_pair(D[i], i));
    }
    while (!Q.empty())
    {
        pair<int, int> pr = *Q.begin();
        Q.erase(Q.begin());
        int x = pr.second;
        if (x == n)
            break;
        int t = pr.first;
        D[x] = corr(bad[x], t);
        t = D[x];
        if (t >= INF)
            break;
        was[x] = true;
        for (int i = 0; i < E[x].size(); i++)
        {
            int y = E[x][i].first;
            int d = E[x][i].second;
            if (was[y])
                continue;
            int tt = t + d;
            int rt = tt;
            if (D[y] > rt)
                Q.erase(make_pair(D[y], y)), D[y] = rt, Q.insert(make_pair(D[y], y));
        }
    }
    if (D[n] >= INF)
        return -1;
    else
        return D[n];
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        E[a].push_back(make_pair(b, c));
        E[b].push_back(make_pair(a, c));
    }
    for (int a = 1; a <= n; a++)
    {
        vector<int> tmp;
        int k;
        scanf("%d", &k);
        int t;
        for (int i = 0; i < k; i++)
            scanf("%d", &t), tmp.push_back(t);
        tmp.push_back(1000*1000*1500);
        int beg = tmp[0];
        for (int i = 1; i < tmp.size(); i++)
            if (tmp[i] - tmp[i - 1] != 1)
                bad[a].push_back(make_pair(beg, tmp[i - 1] + 1)), beg = tmp[i];
    }
    int ans = dij();
    printf("%d\n", ans);
    return 0;
}