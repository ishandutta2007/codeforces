# include <cstdio>
const int MN = 1e6 + 44;
char in[MN];
int main()
{
    scanf("%s", in);
    int pos = 0;
    for (int ch = 'z'; ch >= 'a'; --ch)
    {
        for (int i = pos; in[i]; ++i)
            if (in[i] == ch)
            {
                putchar(ch);
                pos = i;
            }
    }
}