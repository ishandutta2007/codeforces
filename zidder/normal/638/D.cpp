#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[105][105][105],n,m,k,i,j,g,ans;
char s[105];
int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &k);
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
             scanf("%s", s);
             for (g=0; g<k; g++)
                 a[i][j][g+1]=s[g]-'0';
        }
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            for (g=1; g<=k; g++)
            {
                 if (!a[i][j][g]) continue;
                 if (a[i-1][j][g] & a[i+1][j][g])
                 {
                     ans++;
                     continue;
                 }
                 if (a[i][j-1][g] & a[i][j+1][g])
                 {
                     ans++;
                     continue;
                 }
                 if (a[i][j][g-1] & a[i][j][g+1])
                 {
                     ans++;
                     continue;
                 }
                 if (a[i-1][j][g] & a[i][j+1][g] & (!a[i-1][j+1][g]))
                 {
                     ans++;
                     continue;
                 }
                 if (a[i+1][j][g] & a[i][j-1][g] & (!a[i+1][j-1][g]))
                 {
                     ans++;
                     continue;
                 }
                 if (a[i-1][j][g] & a[i][j][g+1] & (!a[i-1][j][g+1]))
                 {
                     ans++;
                     continue;
                 }
                 if (a[i+1][j][g] & a[i][j][g-1] & (!a[i+1][j][g-1]))
                 {
                     ans++;
                     continue;
                 }
                 if (a[i][j][g-1] & a[i][j+1][g] & (!a[i][j+1][g-1]))
                 {
                     ans++;
                     continue;
                 }
                 if (a[i][j][g+1] & a[i][j-1][g] & (!a[i][j-1][g+1]))
                 {
                     ans++;
                     continue;
                 }
            }
    printf("%d\n", ans);
    return 0;
}