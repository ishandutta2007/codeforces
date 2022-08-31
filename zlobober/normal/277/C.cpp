#include <cstdio>
#include <cassert>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, vector<pair<int, int> > > Mx, My;

const int INF = 1e9 + 42;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    else
        return a.second > b.second;
}


int get(vector<pair<int, int> > V)
{
    vector<pair<int, int> > E;
    for (int i = 0; i < V.size(); i++)
        E.push_back(make_pair(V[i].first, 1)), E.push_back(make_pair(V[i].second, -1));
    E.push_back(make_pair(0, 1));
    E.push_back(make_pair(0, -1));
    E.push_back(make_pair(INF, 1));
    E.push_back(make_pair(INF, -1));

    sort(E.begin(), E.end(), comp);
    int bal = 0;
    int prv = 0;
    int ans = 0;
    for (int i = 0; i < E.size(); i++)
    {
        if (bal == 0)
            assert(E[i].second == 1);
        if (bal > 0)
            ans += E[i].first - prv;
        bal += E[i].second;
        prv = E[i].first;
    }
    assert(bal == 0);
    return ans;
}

//#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eprintf(...) 42

pair<int, int> go(vector<pair<int, int> > V, int q)
{
    vector<pair<int, int> > E;
    for (int i = 0; i < V.size(); i++)
        E.push_back(make_pair(V[i].first, 1)), E.push_back(make_pair(V[i].second, -1));
    sort(E.begin(), E.end(), comp);
    E.push_back(make_pair(0, 1));
    E.push_back(make_pair(0, -1));
    E.push_back(make_pair(INF, 1));
    E.push_back(make_pair(INF, -1));

    int bal = 0;
    int prv = 0;
    int ans = 0;
    int got = 0;
    for (int i = 0; i < E.size(); i++)
    {
        bal += E[i].second;
        if (bal == 1 && E[i].second == 1)
            got += (E[i].first - prv);
        if (got >= q)
            return make_pair(0, E[i].first - (got - q));
        prv = E[i].first;
    }
    assert(false);
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
        if (x1 == x2)
        {
            Mx[x1].push_back(make_pair(y1, y2));
        }
        else
        {
            My[y1].push_back(make_pair(x1, x2));
        }
    }
    if ((n - 1 - Mx.size()) % 2 == 1)
    {
        for (int i = 1; i <= n - 1; i++)
            if (Mx.find(i) == Mx.end())
            {
                Mx[i];
                break;
            }
    }
    if ((m - 1 - My.size()) % 2 == 1)
    {
        for (int i = 1; i <= m - 1; i++)
            if (My.find(i) == My.end())
            {
                My[i];
                break;
            }
    }
    vector<pair<int, pair<int, int> > > V;
    for (map<int, vector<pair<int, int> > >::iterator it = Mx.begin(); it != Mx.end(); it++)
    {
        V.push_back(make_pair(m - get(it->second), make_pair(0, it->first)));
    }
    for (map<int, vector<pair<int, int> > >::iterator it = My.begin(); it != My.end(); it++)
    {
        V.push_back(make_pair(n - get(it->second), make_pair(1, it->first)));
    }

    eprintf("It's like a Nim on:\n");
    int xr = 0;
    for (int i = 0; i < V.size(); i++)
        eprintf("%d%c", V[i].first, " \n"[i + 1 == V.size()]), xr ^= V[i].first;
    eprintf("xor = %d\n", xr);
    if (xr == 0)
    {
        printf("SECOND\n");
        return 0;
    }
    else
    {
        printf("FIRST\n");
        for (int i = 0; i < V.size(); i++)
        {
            if ((xr ^ V[i].first) < V[i].first)
            {
                pair<int, int> pr = go(((V[i].second.first == 0) ? Mx : My)[V[i].second.second], (V[i].first - (xr ^ V[i].first)));
                if (V[i].second.first == 0)
                    printf("%d %d %d %d\n", V[i].second.second, pr.first, V[i].second.second, pr.second);
                else
                    printf("%d %d %d %d\n", pr.first, V[i].second.second, pr.second, V[i].second.second);
                break;
            }
        }
        return 0;
    }
}