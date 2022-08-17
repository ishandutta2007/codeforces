#include <cstdio>
#include <cassert>
#include <bitset>
#include <memory.h>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 70500;

pair<int, int> A[N];

typedef bitset<N> bs;

void die()
{
    printf("-1\n");
    exit(0);
}
const int D = 1000;
const int K = N / D + 10;

bs ST[K];
bs T[D + 1];
bs B;

int out[N];
int val[N];

vector<int> in1;

vector<int> E[N];

#define eprintf(...) 42//fprintf(stderr, __VA_ARGS__)


void refill(int x)
{
    assert(x % D == 0);
    T[0] = ST[x / D];
    for (int i = 1; i < D; i++)
        T[i] = (T[i - 1] | (T[i - 1] << A[i + x].first));
}

int main()
{
    int n, s;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i].first), A[i].second = i + 1;
    sort(A, A + n);
    reverse(A, A + n);
    B.set(A[0].first);
    ST[0] = B;
    for (int i = 1; i < n; i++)
    {
        B = B | (B << (A[i].first));
        if (i % D == 0)
            ST[i / D] = B;
    }
    if (!B.test(s))
        die();
    int cur = s;
    if (n != 1)
    {
        refill(((n - 2) / D) * D);
        int pt = ((n - 2) % D);
        for (int i = n - 2; i >= 0; i--)
        {
            if (T[pt].test(cur))
            {
            }
            else
            {
                cur -= A[i + 1].first;
                assert(T[pt].test(cur));
                out[i + 1] = true;
            }
            if (i == 0)
                break;
            pt--;
            if (pt < 0)
                pt += D, refill(i - D);
        }
    }
    assert(cur == A[0].first);
    out[0] = true;
    for (int i = 0; i < n; i++)
        eprintf("%d ", (int)out[i]);
    eprintf("\n");
    in1.push_back(0);
    memset(val, -1, sizeof(val));
    for (int i = 0; i < n; i++)
    {
        if (!out[i])
            in1.push_back(i);
        else
            val[A[i].second] = A[i].first;
    }
    for (int i = 0; i < in1.size(); i++)
    {
        if (i + 1 != in1.size())
            E[A[in1[i]].second].push_back(A[in1[i + 1]].second), val[A[in1[i]].second] = A[in1[i]].first - A[in1[i + 1]].first;
        else
            val[A[in1[i]].second] = A[in1[i]].first;
    }
    for (int i = 1; i <= n; i++)
    {
        assert(val[i] != -1);
        printf("%d %d ", val[i], (int)E[i].size());
        for (int j = 0; j < E[i].size(); j++)
            printf("%d ", E[i][j]);
        printf("\n");
    }
    //while(1);
}