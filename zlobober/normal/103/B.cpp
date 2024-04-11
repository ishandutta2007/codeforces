#include <iostream>
#include <memory.h>
#include <stack>
#include <cstdlib>
#include <list>
using namespace std;

const int N = 150;
list<int> E[N];

bool was[N];

void die(const char* s)
{
    cout << "NO";
    cerr << " " << s;
    exit(0);
}

int n, m;

void DFS_c(int x)
{
    was[x] = 1;
    for (list<int>::iterator it = E[x].begin(); it != E[x].end(); it++)
        if (!was[*it])
            DFS_c(*it);
}

void check_c()
{
    memset(was, 0, sizeof(was));
    DFS_c(1);
    for (int i = 1; i <= n; i++)
        if (!was[i])
            die("not connected");
}

int st[N];

stack<int> S;

bool good[N][N];

void extr(int b)
{
    memset(st, 0, sizeof(st));
    st[b] = 1;
    cerr << b << ' ';
    int t;
    good[S.top()][b] = good[b][S.top()] = 1;
    while (S.top() != b)
    {
        st[t = S.top()] = 1;
        cerr << S.top() << ' ';
        S.pop();
        good[t][S.top()] = good[S.top()][t] = 1;
    }
}

bool DFS2(int x, int p)
{
    st[x] = 1;
    S.push(x);
    for (list<int>::iterator it = E[x].begin(); it != E[x].end(); it++)
    {
        if (*it == p)
            continue;
        if (st[*it] == 1)
        {
            extr(*it);
            return true;
        }
        if (st[*it] == 2)
            continue;
        if (DFS2(*it, x))
            return true;
    }
    st[x] = 2;
    S.pop();
    return false;
}


int DFS3(int x, int p, int u)
{
    was[x] = 1;
    for (list<int>::iterator it = E[x].begin(); it != E[x].end(); it++)
    {
        if (*it == p || *it == u || good[x][*it])
            continue;
        
        if (was[*it])
            die("edge in shup");
        DFS3(*it, x, u);
    }
}

int main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
        cin >> a >> b, E[a].push_back(b), E[b].push_back(a);
    check_c();
    if (!DFS2(1, -1))
        die("no cycles");

    memset(was, 0, sizeof(was));
    
    for (int i = 1; i <= n; i++)
        if (st[i] == 1)
        {
            for (list<int>::iterator it = E[i].begin(); it != E[i].end(); it++)
                if (st[*it] == 1 && !good[i][*it])
                    die("edge inside cycle");
            was[i] = 1;
        }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (st[i] == 1)
        {
            DFS3(i, -1, i);
            ans += E[i].size() > 2;
        }
    //if (ans < 3)
    //{
    //    die("there are not 3 shup");
    //}
    cout << "FHTAGN!";
    return 0;
    
}