#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=1010;
int n,m,k,MOD;
inline ll qpow(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

bool flip=0;
int cnt[N],val[N];
ll ans=1;
int main(){
    n=rdi(),m=rdi(),k=rdi();
    if((n^m)&1){
        puts("0");
        return 0;
    }
    if(n<m) swap(n,m),flip=1;
    for(int i=1;i<=k;i++){
        int x=rdi(),y=rdi(),v=rdi();
        if(flip) swap(x,y);
        val[x]=(val[x]?val[x]*v:v),cnt[x]++;
    }
    MOD=rdi();bool empty=0;
    for(int i=1;i<=n;i++){
        if(!cnt[i]&&!empty) {empty=1;continue;}
        if(cnt[i]==m&&val[i]==1){
            puts("0");
            return 0;
        }
        else if(cnt[i]<m) ans=ans*qpow(2,m-cnt[i]-1)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}