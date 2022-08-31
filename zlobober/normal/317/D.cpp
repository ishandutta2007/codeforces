#include <cstdio>
#include <map>
#include <set>
#include <memory.h>
using namespace std;

typedef long long llong;


const int N = 30;
int D[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, };

int BIT(int msk, int i)
{
    return (msk >> i) & 1;
}

void SBIT(int& msk, int i, int x)
{
    msk ^= ((x ^ BIT(msk, i)) << i);
}

int mark(int msk, int j, int l)
{
    for (int i = j; i <= l; i += j)
        SBIT(msk, i, 1);
    return msk;
}

map<int, int> M;

int go(int msk, int l)
{
    if (2 + msk == (1 << (l + 1)))
        return 0;
    else
    {
        if (M.find(msk) != M.end())
            return M[msk];
        set<int> S;
        for (int j = 1; j <= l; j++)
            if (!BIT(msk, j))
                S.insert(go(mark(msk, j, l), l));
        int ans;
        for (ans = 0; S.find(ans) != S.end(); ans++);
        return M[msk] = ans;
    }
}

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

char *bin(int x, int l)
{
    char* ans = new char[10];
    for (int i = 0; i < l; i++)
        ans[i] = BIT(x, i) + '0';
    ans[l] = 0;
    return ans;
}

int get(int l)
{
    if (D[l] != -1)
        return D[l];
    else
    {
        /*eprintf("\\\\\\\n");
        for (map<int, int>::iterator it = M.begin(); it != M.end(); it++)
        {
            eprintf("%s %d\n", bin(it->first, l), it->second);
        }*/
        M.clear();
        return D[l] = go(0, l);
    }
}

const int SQ = 40000;

typedef long long llong;

bool was[SQ];

int main()
{
    //memset(D, -1, sizeof(D));
    int n;
    scanf("%d", &n);
    int X = get(1);
    eprintf("{0, ");
    for (int i = 1; i <= 29; i++)
        eprintf("%d, ", get(i));
    eprintf("};");
    //return 0;

    for (int x = 2; x <= min(n, SQ - 1); x++)
    {
        if (was[x])
            continue;
        int q = 0;
        llong t = x;
        while (t <= n)
        {
            if (t < SQ)
                was[t] = true;
            t = t * (llong)x, q++;
        }
        X = X ^ get(q);
    }
    X = X ^ (((max(0, n - (SQ - 1))) % 2 == 1) ? get(1) : 0);
    if (X)
        printf("Vasya\n");
    else
        printf("Petya\n");
}