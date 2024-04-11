# include <cstdio>
# include <cstring>
char slowo[101];
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", slowo);
        int len=strlen(slowo);
        if (len>10)
            printf("%c%d%c\n", slowo[0], len-2, slowo[len-1]);
        else
            printf("%s\n", slowo);
    }
}