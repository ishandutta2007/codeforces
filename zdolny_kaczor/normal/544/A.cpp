# include <cstdio>
# include <cstring>
char tekst[101];
bool is[26];
bool spl[101];
int main()
{
    int k;
    scanf("%d%s", &k, tekst);
    int n=strlen(tekst);
    int amo=0;
    for (int i=0; i<n && amo<k; ++i)
        if (!is[tekst[i]-'a'])
        {
            amo++;
            is[tekst[i]-'a']=true;
            spl[i]=true;
        }
    if (amo<k)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for (int i=0; i<n; ++i)
        {
            if (i && spl[i])
                putchar('\n');
            putchar(tekst[i]);
        }
        putchar('\n');
    }
}