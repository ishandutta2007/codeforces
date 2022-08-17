#include <cstdio>
#include <queue>
using namespace std;

const int N = 200500;

vector<int> E[N];

queue<int> Q;

int S[N];
int in[N];

bool st[N];

int A[N], B[N], C[N];
int ans[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &A[i], &B[i], &C[i]);
        E[A[i]].push_back(i);
        E[B[i]].push_back(i);
        S[A[i]] += C[i];
        S[B[i]] += C[i];
    }
    Q.push(1);
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        st[x] = true;
        for (int i = 0; i < E[x].size(); i++)
        {
            int y = A[E[x][i]] ^ B[E[x][i]] ^ x;
            if (st[y])
                continue;
            int c = C[E[x][i]];
            ans[E[x][i]] = x != A[E[x][i]];
            in[y] += c;
            if (in[y] == S[y] / 2 && y != n)
                Q.push(y);
        }
    }
    for (int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
    return 0;
}