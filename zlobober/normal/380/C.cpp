#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1000500;

int A[N];

char buf[N];

int pt = 0;
int st[N];

struct query
{
    int x, id, k;
    query(int _x, int _id, int _k)
    {
        x = _x, id = _id, k = _k;
    }
};

vector<query> Q[N];

int ans[N];

int F[N];

inline void add(int x, int v)
{
    for (; x < N; x |= x + 1)
        F[x] += v;
}

inline int get(int x)
{
    int ans = 0;
    for (; x >= 0; x &= x + 1, --x)
        ans += F[x];
    return ans;
}

int main()
{
    gets(buf);
    int n = strlen(buf);
    for (int i = 0; i < n; i++)
        A[i] = N - 1;
    for (int i = 0; i < n; i++)
    {
        if (buf[i] == '(')
            st[pt++] = i;
        else
        {
            if (pt == 0)
                continue;
            A[st[pt - 1]] = i;
            --pt;
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        --l;
        Q[l].push_back(query(r - 1, i, -1));
        Q[r].push_back(query(r - 1, i, 1));
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < Q[i].size(); j++)
            ans[Q[i][j].id] += Q[i][j].k * get(Q[i][j].x);
        add(A[i], 1); 
        if (i == n)
            break;
    }
    for (int i = 0; i < q; i++)
        printf("%d\n", 2 * ans[i]);
    return 0;
}