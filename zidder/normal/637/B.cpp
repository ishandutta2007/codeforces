#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
map <long long, int> m;
char s[200200][12];
long long hash (int k)
{
    long long ret=0;
    int i,m=strlen(s[k]);
    for (i=0; i<m; i++)
    {
        ret*=27;
        ret+=s[k][i]-'a'+1;
    }
    return ret;
}
int i,n;
long long t;
int main()
{
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("\n");
        scanf("%s", &s[i]);
    }
    for (i=n-1; i>=0; i--)
    {
        t=hash(i);
        if (m[t]==1) continue;
        m[t]=1;
        printf("%s\n", s[i]);
    }
    return 0;
}