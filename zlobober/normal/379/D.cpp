#include <cstdio>
#include <cassert>
#include <memory.h>
using namespace std;

const int inf = 1e9 + 42;

struct str
{
    char b, e;
    int in;
};

str operator +(str a, str b)
{
    str c;
    c.b = a.b;
    c.e = b.e;
    c.in = a.in + b.in + ((a.e == 'A') && (b.b == 'C'));
    if (c.in > inf)
        c.in = inf;
    return c;
}

const int N = 100;
str S[N];

inline int get(str a, str b, int k)
{
    S[1] = a;
    S[2] = b;
    for (int i = 3; i <= k; i++)
        S[i] = S[i - 2] + S[i - 1];
    return S[k].in;
}

void myset(char& a, char b)
{
    assert(a == 0 || a == b);
    a = b;
}

void build(str s, int l)
{
    char res[150];
    memset(res, 0, sizeof(res));
    res[0] = s.b;
    res[l - 1] = s.e;
    int pt = (res[0] == 'A') ? 0 : 1;
    for (int d = 0; d < s.in; d++)
    {
        myset(res[pt], 'A');
        myset(res[pt + 1], 'C');
        pt += 2;
    }
    for (int i = 1; i < l; i++)
        if (!res[i])
            res[i] = 'B';
    puts(res);
}

int main()
{
    int k, x, n, m;
    scanf("%d %d %d %d", &k, &x, &n, &m);
    for (int b1 = 'A'; b1 <= 'C'; b1++)
        for (int e1 = 'A'; e1 <= 'C'; e1++)
            for (int b2 = 'A'; b2 <= 'C'; b2++)
                for (int e2 = 'A'; e2 <= 'C'; e2++)
                {
                    if (n == 1 && (b1 != e1))
                        continue;
                    if (m == 1 && (b2 != e2))
                        continue;
                    for (int in1 = (n == 2 && b1 == 'A' && e1 == 'C'); in1 <= (n - (b1 != 'A') - (e1 != 'C')) / 2; in1++)
                        for (int in2 = (m == 2 && b2 == 'A' && e2 == 'C'); in2 <= (m - (b2 != 'A') - (e2 != 'C')) / 2; in2++)
                        {
                            str s1, s2;
                            s1.b = b1;
                            s1.e = e1;
                            s2.b = b2;
                            s2.e = e2;
                            s1.in = in1;
                            s2.in = in2;
                            int res = get(s1, s2, k);
                            if (res == x)
                            {
                                build(s1, n);
                                build(s2, m);
                                return 0;
                            }
                        }
               } 
    puts("Happy new year!");
    return 0;
}