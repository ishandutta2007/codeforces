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
int n,sa[N],sb[N];
inline void work(){
    n=read();
    for(int i=1;i<=n;i++)sa[(read()+1)>>1]=i-1;
    for(int i=1;i<=n;i++)sb[read()>>1]=i-1;
    for(int i=2;i<=n;i++)sa[i]=min(sa[i],sa[i-1]);
    int ans=1e9;
    for(int i=1;i<=n;i++)ans=min(ans,sa[i]+sb[i]);
    printf("%d\n",ans);
}
int main(){
    int test=read();
    while(test--)work();
    return 0;
}