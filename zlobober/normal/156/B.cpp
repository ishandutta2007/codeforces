#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <list>
using namespace std;

const int N = 100500;

int K[2][N];
int U[N];
list<int> E[2][N];

int st[N];

int main()
{
    int n, m;
    char c;
    cin >> n >> m;
    int t;
    for (int i = 1; i <= n; i++)
        cin >> c >> t, K[c == '+'][t]++, E[c == '+'][t].push_back(i);
    int s = 0;
    for (int i = 1; i <= n; i++)
        s += K[0][i];

    vector<int> g;
    for (int i = 1; i <= n; i++)
    {
        if (K[1][i] + s - K[0][i] == m)
        {
            g.push_back(i);
            U[i] = 1;
        }
    }
    assert(g.size());
    if (g.size() == 1)
    {
        for (int x : E[1][g[0]])
            st[x] = 1;
        for (int i = 1; i <= n; i++)
            if (i != g[0])
                for (int x : E[0][i])
                    st[x] = 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int x : E[0][i])
                st[x] = (U[i]) ? 2 : 1;
            for (int x : E[1][i])
                st[x] = (U[i]) ? 2 : 0;
        }
    }

    string S[3] = {"Lie", "Truth", "Not defined"};

    for (int i = 1; i <= n; i++)
        cout << S[st[i]] << endl;
}