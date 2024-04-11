#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define re register
using namespace std;

inline int read() {
    int X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
    return X*w;
}

const int N=500+10;

int n,ans=0;
char s[N][N];

int main() {
    n=read();
    for (re int i=1;i<=n;++i) scanf("%s",s[i]+1);
    for (re int i=2;i<n;++i)
    for (re int j=2;j<n;++j)
        if (s[i][j]=='X'&&s[i-1][j-1]=='X'&&s[i-1][j+1]=='X'&&s[i+1][j-1]=='X'&&s[i+1][j+1]=='X')
        ++ans;
    printf("%d\n",ans);
    return 0;
}