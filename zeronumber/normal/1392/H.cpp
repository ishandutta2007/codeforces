#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=6e6+5;
const int M=998244353;
int n,m;
ll f[maxn],nf[maxn],inv[maxn],p[maxn],s;
int main(){
    inv[1]=1;for (int i=2;i<maxn;i++) inv[i]=M-(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1;for (int i=1;i<maxn;i++) f[i]=f[i-1]*i%M,nf[i]=nf[i-1]*inv[i]%M;
    cin >> n >> m; s=0;
    p[n]=1; s=f[n-1]*nf[n+m-1]%M;
    for (int i=n-1;i;i--){
        p[i]=s*f[m-1+i]%M*nf[i]%M*m%M;
        s=(s+1ll*p[i]*f[i-1]%M*nf[i+m-1])%M;
        //cout<<i<<' '<<p[i]<<endl;
    }
    int ans=0;
    for (int i=n;i;i--){
        ll res=((i+m)*inv[i]%M*(i*inv[m+1]%M+i*inv[m+i]%M)%M+m*inv[i]%M)%M;
        res=res*((n-i)*inv[m+i+1]%M+1)%M;
        ans=(ans+p[i]*res)%M;
    }
    cout << (ans%M+M)%M << endl;
    return 0;
}