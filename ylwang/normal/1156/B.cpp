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
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
    return X*w;
}
 
const int N=100+10;
 
int n,sa,sb;
char s[N],a[N],b[N];
 
int main() {
    int T=read();
    while (T--) {
        scanf("%s",s+1); n=strlen(s+1),sa=sb=0;
        for (re int i=1;i<=n;++i) {
            if (s[i]&1) a[++sa]=s[i];
            else b[++sb]=s[i];
        }
        sort(a+1,a+sa+1),sort(b+1,b+sb+1);
        if (abs(b[1]-a[sa])!=1) {
            for (re int i=1;i<=sa;++i) putchar(a[i]);
            for (re int i=1;i<=sb;++i) putchar(b[i]);
            puts("");
        }
        else if (abs(a[1]-b[sb])!=1) {
            for (re int i=1;i<=sb;++i) putchar(b[i]);
            for (re int i=1;i<=sa;++i) putchar(a[i]);
            puts("");
        }
        else puts("No answer");
    }
    return 0;
}