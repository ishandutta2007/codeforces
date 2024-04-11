#include <iostream>
#include <set>
using namespace std;

const int N = 100500;

pair<int, int> to[N];
int from[N];

void go(int x, int *b, int *c)
{
    if (to[x].first != 0)
    {
        go(to[x].first, b, c);
        *c = min(*c, to[x].second);
    }
    else
    {
        *b = x, *c = 1e9;
    }
}

set<pair<pair<int, int>, int> > st;
int main()
{
    int n, p;
    cin >> n >> p;
    int a, b, c;
    for (int i = 0; i < p; i++)
    {
        cin >> a >> b >> c;
        to[a] = make_pair(b, c);
        from[b] = a;
    }
    for (int i = 1; i <= n; i++)
    {
        if (from[i] == 0 && to[i].first != 0)
        {
            go(i, &b, &c);
            st.insert(make_pair(make_pair(i, b), c));
        }
    }

    cout << st.size() << endl;
    for (set<pair<pair<int, int>, int> >::iterator it = st.begin(); it != st.end(); it++)
        cout << it->first.first << ' ' << it->first.second << ' ' << it->second << endl;
}