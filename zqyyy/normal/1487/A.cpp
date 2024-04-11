#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=2e5+7;
int n,a[N];
inline void work(){
    n=read();int ans=0;
    for(int i=1;i<=n;i++)a[i]=read();
    int mn=*min_element(a+1,a+n+1);
    for(int i=1;i<=n;i++)if(a[i]!=mn)ans++;
    printf("%d\n",ans);
}
int main(){
    int test=read();
    while(test--)work();
    return 0;
}