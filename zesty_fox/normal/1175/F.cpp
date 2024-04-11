#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
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
#define rdl read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=300010;
int n,a[N];

random_device rd;
ull sum[N],stdsum[N],ha[N];
void init_ha(){
    for(int i=1;i<=n;i++) ha[i]=rd(),stdsum[i]=stdsum[i-1]^ha[i];
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]^ha[a[i]];
}

inline bool ispermutation(int l,int r){
    if(l<1||r>n) return false;
    return (sum[r]^sum[l-1])==stdsum[r-l+1];
}

int pos[N],cnt;
ll ans;
int main(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    init_ha();
    for(int i=1;i<=n;i++){
        if(a[i]==1) pos[++cnt]=i;
    }
    pos[cnt+1]=n+1;
    for(int i=1;i<=cnt;i++){
        ans++;
        int maxn=1;
        for(int j=pos[i]-1;j>pos[i-1];j--){
            maxn=max(maxn,a[j]);
            if(ispermutation(j,j+maxn-1)) ans++;
        }
        maxn=1;
        for(int j=pos[i]+1;j<pos[i+1];j++){
            maxn=max(maxn,a[j]);
            if(ispermutation(j-maxn+1,j)) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}