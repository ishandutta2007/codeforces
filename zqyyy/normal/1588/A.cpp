#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=107;
int n,a[N],b[N];
inline void work(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)b[i]=read();
    sort(a+1,a+n+1),sort(b+1,b+n+1);
    int ans=1;
    for(int i=1;i<=n;i++)ans&=a[i]<=b[i] && b[i]<=a[i]+1;
    puts(ans?"YES":"NO");
}
int main(){
    int test=read();
    while(test--)work();
    return 0;
}