#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

const int N = 1050;
int F[N][N];

int n, m;

int get(int y1, int x1, int y2, int x2)
{
    return F[y2][x2] - F[y2][x1] - F[y1][x2] + F[y1][x1];
}

bool good(int y, int x)
{
    return (y >= 0 && y < n) && (x >= 0 && x < m);
}

pair<char, int> P[N * 100];
pair<char, pair<int, int> > PP[N];
int main()
{
    cin >> n >> m;
    char c;
    int pppt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> c, F[i + 1][j + 1] = c == '#';
            if (c != '#' && c != '.')
                PP[pppt++] = make_pair(c, make_pair(i, j));
        }
    sort(PP, PP + pppt);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            F[i][j] += -F[i - 1][j - 1] + F[i - 1][j] + F[i][j - 1];

    int k;
    bool was = 0;
    cin >> k;
    int d;
    for (int i = 0; i < k; i++)
        cin >> c >> d, P[i] = make_pair(c, d);
    for (int i = 0; i < pppt; i++)
    {
        int y1 = PP[i].second.first;
        int x1 = PP[i].second.second;
        for (int j = 0; j < k; j++)
        {
            int y2 = y1, x2 = x1;
            int d = P[j].second;
            switch (P[j].first)
            {
                case 'N':
                    y2 = y1 - d;
                    break;
                case 'S':
                    y2 = y1 + d;
                    break;
                case 'W':
                    x2 = x1 - d;
                    break;
                case 'E':
                    x2 = x1 + d;
                    break;
            }
            int _y2 = y2, _x2 = x2;
            if (x1 > x2)
                swap(x1, x2);
            if (y1 > y2)
                swap(y1, y2);
            if (!good(y1, x1) || !good(y2, x2))
                goto nextt;
            if (get(y1, x1, y2 + 1, x2 + 1) != 0)
                goto nextt;
            y1 = _y2, x1 = _x2;
        }
        was = 1;
        cout << PP[i].first;
    nextt:;
    }
    if (!was)
        cout << "no solution";
    cout << endl;
}