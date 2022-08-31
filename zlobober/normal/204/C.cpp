#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200500;
char A[N], B[N];

const int E = 26;


int main()
{
    double n;
    scanf("%lf", &n);

    for (int i = 0; i < n; i++)
        scanf(" %c ", &A[i]), A[i] -= 'A';
    for (int i = 0; i < n; i++)
        scanf(" %c ", &B[i]), B[i] -= 'A';
    double de = (double)n * (n + 1) * (2 * n + 1) / 6;

    double en = 0;
    double smx = 0;
    double smn = 0;
    for (int e = 0; e < E; e++)
    {
        smx = 0;
        smn = 0;
        double sa = 0, sb = 0, cnta = 0, cntb = 0;
        for (int i = 0; i < n; i++)
            cnta += A[i] == e, cntb += B[i] == e, sa += i * (A[i] == e), sb += i * (B[i] == e);
        en += cnta * cntb * n - sa * sb;
        double ca = 0, cb = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == e)
                smx += cb * i;
            if (B[i] == e)
                smx += ca * i;
            if (A[i] == e && B[i] == e)
                smx += i;
            ca += A[i] == e;
            cb += B[i] == e;
        }
        ca = 0, cb = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (A[i] == e)
                smn += cb * i;
            if (B[i] == e)
                smn += ca * i;
            if (A[i] == e && B[i] == e)
                smn += i;
            ca += A[i] == e;
            cb += B[i] == e;
        }
        en += n * smn - smx;
    }

    printf("%.10lf\n", (double)en / de);
}