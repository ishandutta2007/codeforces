#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 250;
const int V = 40500;
int H[2];
int A[N];

int D[N][V][2];


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    int a, b;
    scanf("%d", &n);
    scanf("%d %d", &H[0], &H[1]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < V; j++)
            for (int k = 0; k < 2; k++)
                D[i][j][k] = N * N;
    D[0][H[0]][0] = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int q = A[i];
        int com = min(A[i - 1], A[i]);
        sum += A[i];
        for (int h = 0; h <= H[0]; h++)
        {
            for (int l = 0; l < 2; l++)
            {
                for (int p = 0; p < 2; p++)
                {
                    if (l == 0)
                        D[i][h][l] = min(D[i][h][l], D[i - 1][h + q][p] + ((l != p) ? com : 0));
                    else if (sum - (H[0] - h) <= H[1])
                        D[i][h][l] = min(D[i][h][l], D[i - 1][h][p] + ((l != p) ? com : 0));
                }
            }
        }
    }
    int mn = 1e9;
    for (int h = 0; h <= H[0]; h++)
        for (int l = 0; l < 2; l++)
            mn = min(mn, D[n][h][l]);
    if (mn >= N * N)
        printf("%d\n", -1);
    else
        printf("%d\n", mn);
    return 0;
}