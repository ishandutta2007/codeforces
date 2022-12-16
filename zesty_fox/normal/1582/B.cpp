#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=67;
int n,a[N];
inline void work(){
    n=read();ll cnt0=0,cnt1=0;
    for(int i=1;i<=n;i++)a[i]=read(),cnt1+=a[i]==1,cnt0+=a[i]==0;
    unsigned long long ans=(1ull<<(unsigned long long)cnt0)*cnt1;
    printf("%llu\n",ans);
}
int main(){
    int test=read();
    while(test--)work();
    return 0;
}