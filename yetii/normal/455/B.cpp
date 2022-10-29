#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
using namespace std;
typedef long long ll;
int n, k, nx[111111][26], wi[111111][3], sz=1;
char s[111111];
bool W(int v, int k)
{
    int rs=wi[v][k];
    if (rs) return rs-1;
    int t=0;
    for (int i=0;i<26;++i) if (nx[v][i])
    {
        ++t;
        if (!W(nx[v][i], k)) { rs=2; return rs-1; }
    }
    if (t||k==::k) { rs=1; return rs-1; }
    rs=W(0, k+1)+1;
    return rs-1;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d %d\n", &n, &k); if (k%2) k=1; else k=2;
    for (int i=0;i<n;++i)
    {
        gets(s); int m=strlen(s);
        for (int j=0, v=0;j<m;++j)
        {
            char c=s[j]-'a';
            if (!nx[v][c]) nx[v][c]=sz++;
            v=nx[v][c];
        }
    }
    puts(W(0, 1)?"First":"Second");
    return 0;
}