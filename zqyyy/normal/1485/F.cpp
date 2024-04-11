#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=2e5+7,mod=1e9+7;
int n,a[N];
map<ll,int>f;
inline void work(){
    n=read(),f.clear();
    for(int i=1;i<=n;i++)a[i]=read();
    f[0]=1;ll sum=0;int ans=1;
    for(int i=1;i<=n;i++){
	int tmp=(ans+mod-f[sum])%mod;
	ans=(ans+tmp)%mod,f[sum]=(f[sum]+tmp)%mod;
	sum+=a[i];
    }
    printf("%d\n",ans);
}
int main(){
    int test=read();
    while(test--)work();
    return 0;
}