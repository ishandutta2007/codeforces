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

const int N=100010,M=7010;
int n,Q;

int mu[M],pr[M],v[M],cnt;
bitset<M> a[N],m[M],ys[M];
void init(int lim){
    mu[1]=1;
    for(int i=2;i<=lim;i++){
        if(!v[i]){v[i]=i;pr[++cnt]=i;mu[i]=-1;}
        for(int j=1;j<=cnt;j++){
            if(pr[j]>lim/i||pr[j]>v[i]) continue;
            v[pr[j]*i]=pr[j];
            if(i%pr[j]) mu[pr[j]*i]=-mu[i];
            else mu[pr[j]*i]=0;
        }
    }
    for(int i=1;i<=lim;i++){
        for(int j=i;j<=lim;j+=i){
            ys[j][i]=1;
            m[i][j]=(mu[j/i]!=0);
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("sol.in","r",stdin);
#endif
    n=rdi(),Q=rdi();init(M-10);
    while(Q--){
        int typ=rdi(),x=rdi(),y=rdi(),z;
        if(typ==1) a[x]=ys[y];
        if(typ==2) z=rdi(),a[x]=a[y]^a[z];
        if(typ==3) z=rdi(),a[x]=a[y]&a[z];
        if(typ==4) putchar(((a[x]&m[y]).count()&1)+'0');
    }
    puts("");
    return 0;
}