#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1050;
char F[N][N];

vector<int> E[2 * N];

int D[2 * N];

queue<int> Q;
bool was[2 * N];
void BFS()
{
    D[0] = 0;
    Q.push(0);
    was[0] = 1;
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        for (int i = 0; i < E[x].size(); i++)
        {
            int y = E[x][i];
            if (was[y])
                continue;
            D[y] = D[x] + 1;
            was[y] = 1;
            Q.push(y);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> F[i][j];
            if (F[i][j] == '#')
                E[i].push_back(j + N), E[j + N].push_back(i);
        }
    }
    BFS();
    if (!was[n - 1])
        cout << -1 << endl;
    else
        cout << D[n - 1] << endl;
}