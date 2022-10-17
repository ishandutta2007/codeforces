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
int s_p,pr[N],mu[N],v[N];
inline void init(int n){
    mu[1]=1;
    for(int i=2;i<=n;i++){
	if(!v[i])v[i]=i,pr[++s_p]=i,mu[i]=-1;
	for(int j=1;j<=n && i*pr[j]<=n;j++){
	    v[i*pr[j]]=1;
	    if(i%pr[j]==0)break;
	    mu[i*pr[j]]=-mu[i];
	}
    }
}
int n,m,Q,a[N],b[N];
ll sum,pre[N],suf[N];
int main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)b[i]=read()-a[i];
    Q=read(),init(n);
    for(int i=2;i<=n;i++){
	for(int j=i+i;j<=n;j+=i)b[j]-=b[i];
	if(!mu[i])sum+=abs(b[i]);
	else b[++m]=mu[i]*b[i];
    }
    sort(b+1,b+m+1);
    for(int i=1;i<=m;i++)pre[i]=pre[i-1]-b[i];
    for(int i=m;i;i--)suf[i]=suf[i+1]+b[i];
    while(Q--){
	int x=read()-a[1],p=lower_bound(b+1,b+m+1,-x)-b;
	printf("%lld\n",1ll*x*(m-2*(p-1))+sum+pre[p-1]+suf[p]+abs(x));
    }
    return 0;
}