# include <cstdio>
const int MN=11;
char mapa[MN][MN];
bool row[MN], col[MN];
int main()
{
    int r, c;
    
    scanf("%d%d", &r, &c);
    
    for (int i=0; i<r; ++i)
    
        scanf("%s", mapa[i]);
    int ramo=0, camo=0;
    for (int i=0; i<r; ++i)
    
        for (int k=0; k<c; ++k)
        
            if (mapa[i][k]=='S')
            {
                if (!row[i]) {row[i]=true; ramo++;}
                if (!col[k]) {col[k]=true; camo++;}
                

            }
        printf("%d\n", r*c-ramo*camo);
}