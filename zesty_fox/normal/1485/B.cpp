#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
int n,Q,K,a[N];
ll sum[N];
inline void work(){
    n=read(),Q=read(),K=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=2;i<n;i++)sum[i]=sum[i-1]+a[i+1]-a[i-1]-2;
    while(Q--){
	int l=read(),r=read();
	if(l==r)printf("%d\n",K-1);
	else printf("%lld\n",max(0,a[l+1]-2)+max(0,K-a[r-1]-1)+sum[r-1]-sum[l]);
    }
}
int main(){
    /*
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    */
    int test=1;
    while(test--)work();
    return 0;
}