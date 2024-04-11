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
#include <numeric>
using namespace std;
typedef long long ll;

const int N=1000*1000;
int n, p[N];
char S[N];
string f[N][2];
int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d\n", &n);
    for (int i=0, j;i<n;++i)
    {
        gets(S);
        for (j=0;S[j]!=' ';++j);
        S[j]=0; f[i][0]=S; f[i][1]=S+j+1;
        sort(f[i], f[i]+2);
    }
    for (int i=0;i<n;++i) scanf("%d", &p[i]), --p[i];
    string pr="a";
    for (int i=0;i<n;++i)
    {
        int j=p[i];
        string ca=f[j][0];
        if (ca<pr) ca=f[j][1];
        if (ca<pr)
        {
            puts("NO");
            return 0;
        }
        pr=ca;
    }
    puts("YES");
    return 0;
}