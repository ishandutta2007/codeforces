# include <cstdio>
# include <cstring>
const int MN = 1e6 + 44;
char a[MN], b[MN];
bool isin(char a, char tab[])
{
    for (; *tab; tab++)
        if (a == *tab)
            return true;
    return false;
}
int main()
{
    scanf("%s%s", a, b);
    if (strlen(a) == strlen(b) && (isin('1', a) == isin('1', b)) && !(strlen(a) == 1 && a[0] != b[0]))
        printf("YES\n");
    else
        printf("NO\n");
}