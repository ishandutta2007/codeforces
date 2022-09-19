# include <cstdio>
const int MN = 55;
char board[MN][MN];
bool forbidden[MN * 2][MN * 2];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%s", board[i]);
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
            if (board[i][k] == 'o')
                for (int ii = 0; ii < n; ++ii)
                    for (int kk = 0; kk < n; ++kk)
                        if (board[ii][kk] == '.')
                            forbidden[i - ii + MN][k - kk + MN] = true;
    bool OK = true;
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
            if (board[i][k] == 'x')
            {
                bool attacked = false;
                for (int ii = 0; ii < n; ++ii)
                    for (int kk = 0; kk < n; ++kk)
                        if (board[ii][kk] == 'o' && forbidden[ii - i + MN][kk - k + MN] == false)
                            attacked = true;
                if (!attacked)
                    OK = false;
            }
    if (OK)
    {
        printf("YES\n");
        for (int i = - n + 1; i < n; ++i)
        {
            for (int k = - n + 1; k < n; ++k)
                if (i == k && i == 0)
                    putchar('o');
                else if (forbidden[- i + MN][- k + MN])
                    putchar('.');
                else
                    putchar('x');
            putchar('\n');
        }
    }
    else
        printf("NO\n");
}