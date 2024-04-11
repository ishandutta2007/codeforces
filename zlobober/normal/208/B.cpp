#include <cstdio>
#include <memory.h>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> card;

const int N = 60;
int C[N];

char StoM[] = "SDHC";
char StoV[] = "23456789TJQKA";
char toM[256], toV[256];

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

bool D[N][N][N][N];

int get(card a)
{
    return a.first * 13 + a.second;
}

inline bool good(int a, int b)
{
    if (a == 52 || b == 52)
        return false;
    return a / 13 == b / 13 || a % 13 == b % 13;
}

int main()
{
    int n;
    scanf("%d ", &n);
    memset(toM, -1, sizeof(toM));
    memset(toV, -1, sizeof(toV));
    for (int i = 0; i < strlen(StoM); i++)
        toM[StoM[i]] = i;
    for (int i = 0; i < strlen(StoV); i++)
        toV[StoV[i]] = i;

    C[0] = C[1] = C[2] = 52;
    for (int i = 0; i < n; i++)
    {
        char buf[5];
        scanf(" %s ", buf);
        C[i + 3] = toV[buf[0]] + 13 * toM[buf[1]];
    }

    D[n + 2][C[n]][C[n + 1]][C[n + 2]] = true;
    for (int i = n + 2; i > 3; i--)
    {
        for (int a = 0; a <= 52; a++)
            for (int b = 0; b <= 52; b++)
                for (int c = 0; c <= 52; c++)
                    if (D[i][a][b][c])
                    {
                        if (good(c, b))
                            D[i - 1][C[i - 3]][a][c] = true;
                        if (good(c, C[i - 3]))
                            D[i - 1][c][a][b] = true;
                    }
    }
    bool ans = false;
    for (int q = 0; q < 52; q++)
        ans = ans || D[3][52][52][q];
    printf("%s\n", ans ? "YES" : "NO");
}