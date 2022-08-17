#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;

const int N = 1000500;

char buf[N];

char dig[] = "1689";

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int main()
{
    gets(buf);
    bool was[10];
    int n = strlen(buf);
    int pt = n - 1;
    memset(was, 0, sizeof(was));
    sort(buf, buf + n);
    reverse(buf, buf + n);
    while (buf[pt] == '0')
        --pt;
    int m = pt + 1;
    for (int i = pt; i >= 0; i--)
    {
        if (find(dig, dig + 4, buf[i]) != dig + 4 && !was[buf[i] - '0'])
            was[buf[i] - '0'] = true, swap(buf[i], buf[pt]), --pt;
    }
    for (int i = 0; i < 4; i++)
        assert(was[dig[i] - '0']);
    ++pt;
    sort(buf + pt, buf + m);
    eprintf("%s\n", buf);
    int val = 0;
    for (int i = 0; i < m - 4; i++)
        val = (10 * val + buf[i] - '0') % 7;
    eprintf("val = %d\n", val);
    do
    {
        int tl = 0;
        for (int i = m - 4; i < m; i++)
            tl = (10 * tl + buf[i] - '0') % 7;
        eprintf("buf = %s, tl = %d\n", buf, tl);
        if ((val * 10000 + tl) % 7 == 0)
        {
            puts(buf);
            return 0;
        }
    } while(next_permutation(buf + pt, buf + m));
    assert(false);
}