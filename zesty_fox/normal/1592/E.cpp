#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

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
#define mp make_pair
#define pb push_back

const int N=1050010;
int n,a[N],ans,sum[N];
int pos[2][N];

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=n;i>=1;i--) sum[i]=sum[i+1]^a[i];
    for(int bit=19;bit>=0;bit--){    
        for(int l=1,r=1;l<=n;l=r){
            r=l;
            while(r<=n&&(a[r]>>bit&1)==(a[l]>>bit&1)) r++;
            if(!(a[l]>>bit&1)) continue;
            for(int i=l;i<=r;i++) pos[i&1][sum[i]>>bit]=i;
            for(int i=l;i<r;i++) ans=max(ans,pos[i&1][sum[i]>>bit]-i);
            for(int i=l;i<r;i++) pos[i&1][sum[i]>>bit]=0;
        }
    }
    printf("%d\n",ans);
    return 0;
}