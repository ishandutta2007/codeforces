#include<bits/stdc++.h>
#define maxn 105
using namespace std;

int n,m,q;
char s[maxn][maxn],t[maxn][maxn];

int main()  {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i)
        scanf("%s",s[i]);
    for (int i=0;i<m;++i)
        scanf("%s",t[i]);
    scanf("%d",&q);
    while (q--) {
        int x;
        scanf("%d",&x);
        --x;
        printf("%s%s\n",s[x%n],t[x%m]);
    }
    return 0;
}