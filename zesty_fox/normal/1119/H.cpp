#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int MOD=998244353,INV2=499122177;
const int N=140010;

i64 qpow(i64 x,i64 y=MOD-2){
    i64 res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

void FWT(i64 *a,int n,int typ=1){
    for(int len=2;len<=n;len<<=1){
        int mid=len>>1;
        for(int i=0;i<n;i+=len){
            for(int j=i;j<i+mid;j++){
                i64 a1=a[j]+a[j+mid],a2=a[j]-a[j+mid];
                if(typ==-1) a1*=INV2,a2*=INV2;
                a[j]=a1%MOD,a[j+mid]=a2%MOD;
            }
        }
    }
}

int n,k,s;
i64 x,y,z;
i64 a1[N],a2[N],a3[N],r[N],res[N];

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),k=(1<<rdi()),x=rdi(),y=rdi(),z=rdi();
    for(int i=1;i<=n;i++){
        int a=rdi(),b=rdi(),c=rdi();
        b^=a,c^=a,s^=a;
        a1[b]++,a2[c]++,a3[b^c]++;
    }
    FWT(a1,k),FWT(a2,k),FWT(a3,k);
    for(int i=0;i<k;i++){
        int c0=(n+a1[i]+a2[i]+a3[i])/4,c1=(n+a1[i]-2*c0)/2,c2=(n+a2[i]-2*c0)/2,c3=(n+a3[i]-2*c0)/2;
        r[i]=qpow(x+y+z,c0)*qpow(x+y-z,c1)%MOD*qpow(x-y+z,c2)%MOD*qpow(x-y-z,c3)%MOD;
    }
    FWT(r,k,-1);
    for(int i=0;i<k;i++){
        r[i]=(r[i]%MOD+MOD)%MOD;
        res[i^s]=r[i];
    }
    for(int i=0;i<k;i++) cout<<res[i]<<' ';
    return 0;
}