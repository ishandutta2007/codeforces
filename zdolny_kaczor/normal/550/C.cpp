# include <cstdio>
# include <cstring>
const int MN = 110;
char text[MN];
int main()
{
    scanf("%s", text);
    int n = strlen (text);
    for (int i = 0; i<n; ++i)
        for (int k = i + 1; k < n; ++k)
            for (int l = k + 1; l < n; ++l)
                if ((text[i]*100 + text[k] * 10 + text [l] ) % 8 == 0 && text[i] != '0')
                {
                    printf("YES\n%c%c%c\n", text[i], text[k], text[l]);
                    return 0;
                 }   
                    
                    
    for (int i = 0; i<n; ++i)
        for (int k = i + 1; k < n; ++k)
                if ((text[i] * 10 + text[k]) % 8 == 0 && text[i] != '0')
                {
                    printf("YES\n%c%c\n", text[i], text[k]);
                    return 0;
                 }   
     for (int i = 0; i< n; ++i)
        if (text[i] % 8 == 0) {
            printf("YES\n%c\n", text[i]);
            return 0;
        }
                    printf("NO\n");
    
}