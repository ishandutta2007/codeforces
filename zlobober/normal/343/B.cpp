#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int N = 100500;
char buf[N];

char st[N];
int pt = 0;
int main()
{
    gets(buf);
    int n = strlen(buf);
    for (int i = 0; i < n; i++)
    {
        if (pt != 0 && st[pt - 1] == buf[i])
        {
            --pt;
            continue;
        }
        else
            st[pt++] = buf[i];
    }
    if (pt)
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}