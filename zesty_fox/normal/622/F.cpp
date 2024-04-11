#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using db=double;
using vi=vector<int>;
using pii=pair<int,int>;

template <typename T>
T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int MOD=1e9+7,N=1e6+10;

i64 qpow(i64 x,i64 y=MOD-2){
    i64 res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int k,n;
i64 ans;

int v[N],p[N/5],pcnt;
void init(int n){
    v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i]) {v[i]=i,p[++pcnt]=i;}
        for(int j=1;j<=pcnt;j++){
            if(p[j]>v[i]||p[j]>n/i) break;
            v[p[j]*i]=p[j];
        }
    }
    for(int i=1;i<=n;i++){
        if(v[i]==i) v[i]=qpow(i,k);
        else v[i]=(i64)v[i/v[i]]*v[v[i]]%MOD;
    }
    for(int i=1;i<=n;i++) (v[i]+=v[i-1])%=MOD;
}

i64 calc(int *v,int st,int len,int k){
    static int faci[N],pre[N],suf[N];
    faci[len]=pre[0]=1;
    for(int i=1;i<=len;i++){
        faci[len]=(i64)faci[len]*i%MOD;
        pre[i]=(i64)pre[i-1]*((st+i-1)-k)%MOD;
    }
    faci[len]=qpow(faci[len]),suf[len+1]=1;
    for(int i=len;i>=1;i--){
        faci[i-1]=(i64)faci[i]*i%MOD;
        suf[i]=(i64)suf[i+1]*((st+i-1)-k)%MOD;
    }

    i64 ret=0;
    for(int i=1;i<=len;i++){
        i64 fm=(i64)((i-1)&1?-faci[i-1]:faci[i-1])*faci[len-i]%MOD;
        i64 fz=(i64)pre[i-1]*suf[i+1]%MOD;
        ret+=v[i-1]*fz%MOD*fm%MOD;
    }
    ret=(ret%MOD+MOD)%MOD;
    return ret;
}

int main(){
    n=rdi(),k=rdi();init(k+2);
    ans=calc(v+1,1,k+2,n);
    cout<<ans<<endl;
    return 0;
}